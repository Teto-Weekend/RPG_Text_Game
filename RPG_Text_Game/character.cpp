#include "character.h"

/* コンストラクタ */
CharacterClass::CharacterClass(std::string init_name, int init_hp, int init_attack, int init_defence) {
	setName(init_name);					// キャラクター名を初期化
	setHp(init_hp);						// HP の初期化
	setAttack(init_attack);				// 攻撃力の初期化
	setDefense(init_defence);			// 防御力の初期化
}

/* デストラクタ */
CharacterClass::~CharacterClass() {
}

/* Getter */
// キャラクター名を取得
std::string CharacterClass::getName(void) const {
	return name;
}
// HPを取得
int CharacterClass::getHp(void) const {
	return hp;
}
// 攻撃力を取得
int CharacterClass::getAttack(void) const {
	return attack;
}
// 防御力を取得
int CharacterClass::getDefense(void) const {
	return defense;
}

/* Setter */
// キャラクター名を設定
void CharacterClass::setName(const std::string& update_name) {
	name = update_name;
}
// HPを設定
void CharacterClass::setHp(int update_hp) {
	hp = update_hp;
}
// 攻撃力を設定
void CharacterClass::setAttack(int update_attack) {
	attack = update_attack;
}
// 防御力を設定
void CharacterClass::setDefense(int update_defense) {
	defense = update_defense;
}


void CharacterClass::showStatus() const {
	std::cout << "NAME	: "		<< this->getName()		<< std::endl;
	std::cout << "HP	: "		<< this->getHp()		<< std::endl;
	std::cout << "ATTACK	: " << this->getAttack()	<< std::endl;
	std::cout << "DEFENSE	: " << this->getDefense()	<< std::endl;
}

int	 CharacterClass::calcDamage(const CharacterClass& target) const {
	int damage = this->getAttack() - target.getDefense();
	return damage > 0 ? damage : MIN_ATTACK;
}

void CharacterClass::attackTo(CharacterClass& target) {
	if (this->getHp() > 0) {
		int damage = this->calcDamage(target);
		int hitpoint = target.getHp() - damage;
		if (hitpoint <= 0) {
			hitpoint = 0;
		}
		target.setHp(hitpoint);
		std::cout << this->getName() << "の攻撃！ " << target.getName() << "に" << damage << "のダメージ" << std::endl;
		std::cout << target.getName() << "の残りHP: " << target.getHp() << std::endl;
		if (target.getHp() <= 0) {
			std::cout << this->getName() << "は" << target.getName() << "を倒した！" << std::endl;
		}
	}
}


