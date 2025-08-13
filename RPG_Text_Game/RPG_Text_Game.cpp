// RPG_GAME.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "character.h"

int main()
{
    CharacterClass Yuusha("勇者", 30, 5, 3);
    CharacterClass Slime("スライム", 10, 6, 1);

    Yuusha.showStatus();
    std::cout << "---------------" << std::endl;
    Slime.showStatus();
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;

    int command;

    while ((!Yuusha.isKnockedOut()) && (!Slime.isKnockedOut())) {
        std::cout << "攻撃:1" << std::endl;
        std::cout << "回復:2" << std::endl;
        std::cout << "次の行動を入力：";
        std::cin >> command;
        
        Yuusha.perseCommand(static_cast<CharacterClass::kCommandList>(command), Slime);
        std::cout << std::endl;
        Slime.attackTo(Yuusha);
        std::cout << std::endl;

        Yuusha.showStatus();
        std::cout << "---------------" << std::endl;
        Slime.showStatus();
        std::cout << "---------------" << std::endl;
        std::cout << std::endl;
    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
// RPG_Text_Game.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//