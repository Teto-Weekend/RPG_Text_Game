#include "character.h"

/* コンストラクタ */
CharacterClass::CharacterClass(std::string init_name, int init_hp, int init_attack, int init_defense)
	: name(init_name),       // キャラクター名
	maxHp(init_hp),        // MaxHP
	currentHp(init_hp),           // 現在HP
	attack(init_attack),   // 攻撃力
	defense(init_defense)  // 防御力
{
	// シードはゲーム開始時に一度だけでOK
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		seeded = true;
	}
}


/* デストラクタ */
CharacterClass::~CharacterClass() {
}

/* Getter */
// キャラクター名を取得
const std::string& CharacterClass::getName(void) const {
	return name;
}
const int CharacterClass::getMaxHp(void) const
{
	return maxHp;
}
// HPを取得
int CharacterClass::getHp(void) const {
	return currentHp;
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
void CharacterClass::setMaxHp(const int update_hp) {
	maxHp = update_hp;
}
// HPを設定
void CharacterClass::setHp(int update_hp) {
	// update_hpが0以下ならば0を返す
	currentHp = std::max(0, update_hp);
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
	return currentHp <= 0;
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
	int targetHp   = target.getHp();
	const std::string& targetName = target.getName();
	const std::string& myName	  = getName();

	int damage = calcDamage(target);
	target.setHp(targetHp - damage);
	
	// 更新後のHPを取得
	int update_targetHp = target.getHp(); 

	std::cout << myName << "の攻撃！ "	<< targetName << "に" << damage	<< "のダメージ" << std::endl;
	std::cout << targetName << "の残りHP: "	<< update_targetHp << std::endl;

	if (target.isKnockedOut()) {
		std::cout << myName << "は"	<< targetName << "を倒した！"	<< std::endl;
	}
}

// 回復をする
void CharacterClass::healTo() {
	// 回復割合（例：10%～25%）
	const float minRate = 0.10f;
	const float maxRate = 0.25f;

	// ランダム割合を算出
	float randomRate = minRate + (static_cast<float>(std::rand()) / RAND_MAX) * (maxRate - minRate);

	// 回復量（整数化）
	int healAmount = static_cast<int>(getMaxHp()* randomRate);

	// 回復（最大HP超えない）
	setHp(std::min(getHp() + healAmount, getMaxHp()));

	const std::string& myName = getName();
	std::cout << myName << "の回復！ " <<  std::endl;
	std::cout << myName << "は " << healAmount << "回復した" << std::endl;
}

void CharacterClass::perseCommand(kCommandList command, CharacterClass& target) {
	switch (command){
	case kCommandList::ATTACK:
		attackTo(target);
		break;
	case kCommandList::HEAL:
		healTo();
		break;
	default:
		break;
	}
}


