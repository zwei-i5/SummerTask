#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//変数
    int player;
    int cpu;
    int result;
    int i;
    int win = 0;
    int lose = 0;
    int draw = 0;
	//乱数初期化
    srand((unsigned int)time(nullptr));
    cout << "じゃんけんゲームを開始します。" << endl;
    //ゲーム開始（五回勝負）
    for (i = 0; i < 5; i++)
    {
        cout << endl;
        //ターン数表示
        cout << "-------- " << i + 1 << "回戦 --------" << endl;
		//入力チェック
        while (true)
        {
            cout << "0：グー　1：チョキ　2：パー" << endl;
            cout << "プレイヤーの手を入力してください：" << endl;
			//入力
            cin >> player;

            if (player >= 0 && player <= 2)
            {
                break;
            }

            cout << "入力に誤りがあります。再入力してください。" << endl;
        }
		//CPUの手をランダムで生成
        cpu = rand() % 3;
        //プレイヤーの手の表示
        switch (player)
        {
        case 0:
            cout << "PLAYER：グー" << endl;
            break;

        case 1:
            cout << "PLAYER：チョキ" << endl;
            break;

        case 2:
            cout << "PLAYER：パー" << endl;
            break;
        }

		//CPUの手の表示
        switch (cpu)
        {
        case 0:
            cout << "CPU：グー" << endl;
            break;

        case 1:
            cout << "CPU：チョキ" << endl;
            break;

        case 2:
            cout << "CPU：パー" << endl;
            break;
        }


        result = player - cpu;
		//勝敗判定
        if (result == -1 || result == 2)
        {
            cout << "PLAYER WIN!" << endl;
            win++;
        }
        else if (result == 0)
        {
            cout << "DRAW" << endl;
            draw++;
        }
        else
        {
            cout << "CPU WIN!" << endl;
            lose++;
        }
    }

	//結果表示
    cout << endl;
    cout << "==============================" << endl;
    cout << "5回勝負終了！" << endl;
    cout << win << "勝 "
        << draw << "分 "
        << lose << "敗" << endl;
    cout << "==============================" << endl;

    return 0;
}