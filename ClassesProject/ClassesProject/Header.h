#pragma once
#ifndef Header_h
#define Header_h
#include<iostream>
#include<cstdlib>
#include<string>
//Структура:
//CreatureEntity
//	NPC
//		Enemy 
//		Vendor 
//			Blacksmith 
//	PlayableCharacter
//		Player
//		Summon
static unsigned PlayerCount=0;
class CreatureEntity
{
protected:
	double HP_max, MP_max,HP_current,MP_current;
	unsigned gold;

public:

	double get_current_health() {
		return HP_current;
	}
	double get_current_mana() {
		return MP_current;
	}
	void set_health(double _HP) {
		HP_current = _HP;
	}
	void set_mana(double _MP) {
		MP_current = _MP;
	}
	unsigned get_gold() {
		return gold;
	}
	void set_gold(unsigned _gold) {
		gold = _gold;
	}
	virtual void heal(double heal_amount) = 0;
	virtual void deal_damage(double damage_amt, CreatureEntity& _enemy) = 0;
	
};
class NPC :public CreatureEntity
{
protected:
	
public:
	
};
class Enemy : public NPC
{
protected:
public:
	Enemy() {
		HP_max = 100 + 100 * PlayerCount * 0.5;
		MP_max = 100 + 100 * PlayerCount * 0.25;
		set_health(HP_max);
		set_mana(MP_max);

	}
	Enemy(double _base_hp, double _base_mp) {
		HP_current = HP_max = _base_hp+_base_hp*PlayerCount*0.5;
		MP_current = MP_max = _base_mp + _base_mp * PlayerCount * 0.5;
	}

	void heal(double heal_amount) {
		set_health(get_current_health() + heal_amount * 0.9); //лечение, получаемое противником, немного уменьшено
	}
	void deal_damage(double damage_amt, CreatureEntity& _enemy) {
		_enemy.set_health(get_current_health() - damage_amt);
	}
	friend std::ostream& operator<<(std::ostream&, Enemy&);
};
std::ostream& operator<<(std::ostream& out, Enemy& e) {
	out << "\nHP: " << e.HP_current << "/" << e.HP_max;
	out << "\nMP: " << e.MP_current << "/" << e.MP_max<<"\n";
	return out;
}
class Vendor :public NPC
{
protected:
public:
	Vendor() {
		set_health(9999);
		set_mana(0);
		set_gold(1000);
	}

};
class Blacksmith :public Vendor
{
protected:
	unsigned scrap_metal;
public:
	unsigned get_scrap() {
		return scrap_metal;
	}
	void set_scrap_metal(unsigned _scrap) {
		scrap_metal = _scrap;
	}
};
class PlayableCharacter : public CreatureEntity
{

};
class Player : public PlayableCharacter
{
protected:

	unsigned player_level,skill_points,healing_spell_level,fireball_level,mana_steal_level,hp_gain,mp_gain;
public:

	static void print_playercount() {
		std::cout << "There are " << PlayerCount << " players in the game.";
	}
	Player() {
		PlayerCount++;
		HP_max = 100;
		MP_max = 100;
		set_health(HP_max);
		set_mana(MP_max);
		player_level = skill_points = 1;
		healing_spell_level = fireball_level = mana_steal_level = 0;
		hp_gain = mp_gain = 20;
	}
	Player(const Player& p) {
		PlayerCount++;
		HP_max = p.HP_max;
		MP_max = p.MP_max;
		set_health(p.HP_max);
		set_mana(p.MP_max);
		player_level = p.player_level;
		skill_points = p.skill_points;
		healing_spell_level = p.healing_spell_level;
		fireball_level = p.fireball_level;
		mana_steal_level = p.mana_steal_level;
		hp_gain = p.hp_gain;
		mp_gain = p.mp_gain;
	}
	void heal(double heal_amount) {
		set_health(get_current_health() + heal_amount * 1.5); // лечение, получаемое игроком, увеличено
	}
	void Purification(PlayableCharacter& _heal_target) {
		unsigned mana_required = 20 * healing_spell_level;
		if (get_current_mana() > mana_required)
		{
			heal(30 * healing_spell_level);
			set_mana(get_current_mana() - mana_required);
		}
		else std::cout << "\nNot enough mana!\n";
	}
	void deal_damage(double damage_amt,CreatureEntity& _enemy) {
		_enemy.set_health(_enemy.get_current_health() - damage_amt);
	}
	void Fireball(CreatureEntity& _enemy) {
		unsigned mana_required = 30 * fireball_level;
		if (get_current_mana() > mana_required) {
			deal_damage(40 * fireball_level, _enemy);
			set_mana(get_current_mana() - mana_required);
		}
		else std::cout << "\nNot enough mana!\n";

	}
	void Mana_steal(CreatureEntity& _enemy) {
		unsigned mana_stolen = 60 * mana_steal_level;
		_enemy.set_mana(get_current_mana() - mana_stolen);
		set_mana(get_current_mana() + mana_stolen);

	}
	void LevelUP() {
		skill_points++;
		player_level++;
		set_health(HP_max + hp_gain);
		set_mana(MP_max + mp_gain);
		std::cout << "\nYou have leveled up! You have been healed to full and gained " << hp_gain << "max health and " << mp_gain << "max mana. You have " << skill_points << "unspent skill points.\n";

	}
	void AbilityLevelUp() {
		std::cout << "\nChoose an ability to level up:\n 1.Purification\n 2.Fireball\n 3. Mana steal\n";
		int abilitycode;
		do
			std::cin >> abilitycode;
		while ((abilitycode < 1) || (abilitycode > 3));
		switch (abilitycode)
		{
			case 1:
				healing_spell_level++;
				break;
			case 2:
				fireball_level++;
				break;
			case 3:
				mana_steal_level++;
				break;
		}
		skill_points--;
	}
	bool operator<(CreatureEntity& c);
	bool operator>(CreatureEntity& c);
	friend std::ostream& operator<<(std::ostream&, const Player&);
};
bool Player::operator<(CreatureEntity& c) {
	return (get_current_health() < c.get_current_health());
}
bool Player::operator>(CreatureEntity& c) {
	return (get_current_health() > c.get_current_health());
}
std::ostream& operator<<(std::ostream& out, const Player& p) {
	out << "\nLevel: " << p.player_level;
	out << "\nHP: " << p.HP_current << "/" << p.HP_max;
	out << "\nMana: " << p.MP_current << "/" << p.MP_max;
	out << "\nUnspent skill points: " << p.skill_points;
	out << "\nAbility levels: \nPurification: " << p.healing_spell_level << "\nFireball: " << p.fireball_level << "\nMana steal: " << p.mana_steal_level<<"\n";
	return out;
}
class Summon : PlayableCharacter
{
private:
public:
	void heal(double heal_amount) {
		set_health(get_current_health() + heal_amount * 0.75); //лечение, получаемое призываемым существом, уменьшено
	}
};

#endif // !Header_h
