#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	//定数
	const int CARD = 3;
	const int CARD_NUMBER = 10;
	//変数＆配列
	int i, hit = 0;
	//プレイヤーの手札
	int playerCard[CARD];
	//CPUの手札
	int enemyCard[CARD];
	//プレイヤーの選択したカード
	int plyChoice[CARD];
	//CPUの選択したカード
	int emyChoice[CARD];
	//ターンフラグ
	bool turnFlag = true;
	bool judgementFlag = false;
	//乱数初期化
	srand((unsigned int)time(NULL));
	//手札配布
	for (i = 0; i < CARD; i++)
	{
		playerCard[i] = rand() % CARD_NUMBER;
		enemyCard[i] = rand() % CARD_NUMBER;
	}
	cout << "===================   Hit & Blow   ============================" << "\n";
	cout << "3マスの数字あてゲームプレイヤーとCPUが、お互いに隠し持った3つの数字を当てるターン制のゲーム" << "\n";
	cout << "あなたの配られてカードは," << "\n";
	//回数カウント
	for (i = 0; i < CARD; i++)
	{
		cout << i + 1 << "番目" << playerCard[i] << "\n";
	}

	cout << "===================   GAME STRAT   ============================" << "\n";
	//ゲーム開始
	while (true)
	{

		if (turnFlag)
		{
			//ヒット数初期化
			hit = 0;
			cout << "PLAYER TRUN 「数字の0から9までの数字を3つ選んでください」\n";
			//入力を三回行う
			for (i = 0; i < CARD; i++)
			{
				//入力チェック
				while (true)
				{
					//入力
					cin >> plyChoice[i];
					if (0 > plyChoice[i] || 9 < plyChoice[i])
					{
						cout << "入力に誤りがあります。再度入力してください。\n";
					}
					else
					{
						break;
					}

				}
			}

			//ヒット数判定
			for (i = 0; i < CARD; i++)
			{
				if (plyChoice[i] == enemyCard[i])
				{
					cout << "Hit,";
					hit++;
				}
				else
				{
					cout << "Blow,";
				}
			}
			cout << "\n";
			//勝敗判定
			if (hit == 3)
			{
				cout << "3Hit!!\n";
				//trueを返す
				judgementFlag = true;
				//ループを抜ける
				break;
			}

			cout << "\n";
			//ターンフラグをfalseにする
			turnFlag = false;
		}
		else
		{
			//ヒット数初期化
			hit = 0;
			//敵のターン
			cout << "ENEMY TRUN \n";
			//敵の選択カードの生成
			for (i = 0; i < CARD; i++)
			{
				//数字生成
				emyChoice[i] = rand() % CARD_NUMBER;

				cout << i + 1 << "番目" << emyChoice[i] << "\n";
			}
			//ヒット数判定
			for (i = 0; i < CARD; i++)
			{
				if (emyChoice[i] == playerCard[i])
				{
					cout << "Hit,";
					hit++;
				}
				else
				{
					cout << "Blow,";
				}
			}
			cout << "\n";
			//勝敗判定
			if (hit == 3)
			{
				cout << "3Hit!!\n";
				break;
			}

			cout << "\n";
			//ターンフラグをtrueにする
			turnFlag = true;
		}


	}
	//試合結果
	if (judgementFlag)
	{
		//プレイヤー勝利
		cout << "PLAYER WINNER\n";
	}
	else
	{
		//CPU勝利
		cout << "ENEMY WINNER\n";
	}

	return 0;
}