#include "character.h"

/* コンストラクタ */
CharacterClass::CharacterClass(std::string init_name, int init_hp, int init_attack, int init_defense) {
	setName(init_name);					// キャラクター名を初期化
	setHp(init_hp);						// HP の初期化
	setAttack(init_attack);				// 攻撃力の初期化
	setDefense(init_defense);			// 防御力の初期化
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
	// update_hpが0以下ならば0を返す
	hp = std::max(0, update_hp);
}
// 攻撃力を設定
void CharacterClass::setAttack(int update_attack) {
	attack = update_attack;
}
// 防御力を設定
void CharacterClass::setDefense(int update_defense) {
	defense = update_defense;
}

// ステータス表示
void CharacterClass::showStatus() const {
	std::cout << "NAME	: "		<< getName()		<< std::endl;
	std::cout << "HP	: "		<< getHp()		<< std::endl;
	std::cout << "ATTACK	: " << getAttack()	<< std::endl;
	std::cout << "DEFENSE	: " << getDefense()	<< std::endl;
}

// 生存状態を判定する
// true : 戦闘不能
// false: 戦闘可能
bool CharacterClass::isKnockedOut() const {
	return getHp() <= 0;
}

// ダメージ量を計算
int	 CharacterClass::calcDamage(const CharacterClass& target) const {
	int damage = getAttack() - target.getDefense();
	return damage > 0 ? damage : kMinAttack;
}

// ターゲットに攻撃を与える
void CharacterClass::attackTo(CharacterClass& target) {
	// 生存状態を確認 
	if (isKnockedOut()) return;

	int damage = calcDamage(target);
	target.setHp(target.getHp() - damage);

	std::cout << getName()	<< "の攻撃！ "	<< target.getName()		<< "に" << damage	<< "のダメージ" << std::endl;
	std::cout << target.getName()	<< "の残りHP: "	<< target.getHp()	<< std::endl;

	if (target.isKnockedOut()) {
		std::cout << getName()	<< "は"	<< target.getName()	<< "を倒した！"	<< std::endl;
	}
}


