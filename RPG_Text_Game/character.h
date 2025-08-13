#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class CharacterClass {
public:
	CharacterClass(std::string init_name, int init_hp, int init_attack, int init_defence);
	~CharacterClass();

	static constexpr int kMinAttack = 1;

	enum class kCommandList : int {
		ATTACK = 1,
		HEAL = 2
	};

	// Getter
	const std::string& getName(void)const;
	const int getMaxHp(void)const;
	int getHp(void)const;				
	int getAttack(void)const;
	int getDefense(void)const;

	// Setter
	void setName(const std::string& name);
	void setMaxHp(const int update_hp);
	void setHp(int update_hp);					// 負の値は0に補正
	void setAttack(int update_attack);
	void setDefense(int update_defense);

	void showStatus(void)const;					// キャラクター情報を出力
	bool isKnockedOut()const;					// HPが0以下か判定
	int	 calcDamage(const CharacterClass& target)const;
	void attackTo(CharacterClass& target);		// ダメージ分HPを減らす (HPは0未満にならない)
	void healTo();									// 回復	

	void perseCommand(kCommandList command, CharacterClass& target);

private:
	std::string	name;				// キャラクター名
	int	currentHp;					// 現在のヒットポイント
	int maxHp;						// 最大のヒットポイント
	int attack;						// 攻撃力
	int defense;					// 防御力
};


