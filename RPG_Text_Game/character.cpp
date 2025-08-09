#include "character.h"

/* コンストラクタ */
CharacterClass::CharacterClass(std::string init_name, int init_hp, int init_attack, int init_defence) {
	setName(init_name);					// キャラクター名を初期化
	setHp(init_hp);						// HP の初期化
	setAttack(init_attack);				// 攻撃力の初期化
	setDefence(init_defence);			// 防御力の初期化
}

/* デストラクタ */
CharacterClass::~CharacterClass() {
}

/* Getter */
// キャラクター名を取得
std::string CharacterClass::getName(void) {
	return name;
}
// HPを取得
int CharacterClass::getHp(void) {
	return hp;
}
// 攻撃力を取得
int CharacterClass::getAttack(void) {
	return attack;
}
// 防御力を取得
int CharacterClass::getDefense(void) {
	return defence;
}

/* Setter */
// キャラクター名を設定
void CharacterClass::setName(std::string update_name) {
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
void CharacterClass::setDefence(int update_defence) {
	defence = update_defence;
}


void CharacterClass::showStatus() {
	std::cout << "NAME	: " << this->getName() << std::endl;
	std::cout << "HP	: " << this->getHp() << std::endl;
	std::cout << "ATTACK	: " << this->getAttack() << std::endl;
	std::cout << "DEFENCE	: " << this->getDefense() << std::endl;
}

void CharacterClass::takeDamage(int amount) {
}


