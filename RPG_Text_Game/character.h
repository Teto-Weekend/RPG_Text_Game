#pragma once

#include <stdio.h>
#include <iostream>
#include <string>

constexpr int kMinAttack = 1;

class CharacterClass {
public:
	CharacterClass(std::string init_name, int init_hp, int init_attack, int init_defence);
	~CharacterClass();

	// Getter
	std::string getName(void)const;
	int getHp(void)const;
	int getAttack(void)const;
	int getDefense(void)const;

	// Setter
	void setName(const std::string& name);
	void setHp(int update_hp);
	void setAttack(int update_attack);
	void setDefense(int update_defense);

	void showStatus(void)const;			// キャラクター名、HP、攻撃力、防御力を表示する
	int	 calcDamage(const CharacterClass& target)const;
	void attackTo(CharacterClass& target);		// ダメージ分HPを減らす (HPは0未満にならない)

private:
	std::string	name;				// キャラクター名
	int	hp;							// 現在のヒットポイント
	int attack;						// 攻撃力
	int defense;					// 防御力
};
