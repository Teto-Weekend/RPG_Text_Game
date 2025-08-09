#pragma once

#include <stdio.h>
#include <iostream>

class CharacterClass {
public:
	CharacterClass(std::string init_name, int init_hp, int init_attack, int init_defence);
	~CharacterClass();

	// Getter
	std::string getName(void);
	int getHp(void);
	int getAttack(void);
	int getDefense(void);

	// Setter
	void setName(std::string);
	void setHp(int);
	void setAttack(int);
	void setDefence(int);

	void showStatus();			// キャラクター名、HP、攻撃力、防御力を表示する
	void takeDamage(int);	// ダメージ分HPを減らす (HPは0未満にならない)

private:
	std::string	name;				// キャラクター名
	int	hp;							// 現在のヒットポイント
	int attack;						// 攻撃力
	int defence;					// 防御力
};


#pragma once
