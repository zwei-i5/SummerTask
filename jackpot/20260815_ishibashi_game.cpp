#include<iostream>
#include<ctime>
#include<cstdlib>
#include"20260815_ishibashi.h"
using namespace std;

int InputCheck(int min, int max)
{
	int input;
	while (true)
	{
		cin >> input;
		if (min > input || input > max)
		{
			cout << "範囲外です。再入力してください\n";
		}
		else
		{
			break;
		}
	}
	return input;
}
void Rolldice(int &dice1, int &dice2, int &sumdice)
{ 
	dice1 = rand() % DICE + 1;
	dice2 = rand() % DICE + 1;
	sumdice = dice1 + dice2;
	cout << "サイコロの目は " << dice1 << " と " << dice2 << " です。\n" << "取得可能マス：" << dice1 << "," << dice2 << ","; if (sumdice < 10) cout << sumdice << endl; 
}
void Board(bool b[])
{
	// 現在のマスを表示
	cout << "現在のマスを表示\n";
	for (int i = MIN; i <= MAX; i++)
	{
		if (b[i])
			cout << "[X]";
		else
			cout << "[" << i << "]";
	}
	cout << endl;
}
bool BoardComplete(int t)
{
	if (t == 9)
	{
		cout << "すべてのマスが取られました！" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
void Game()
{
	//変数
	int player, cpu[3];
	int cpuchoice;
	int dice1, dice2, sumdice;
	int turn = 0;
	bool b[10] = { false };
	int taken = 0;
	int count =0;
	
	while (true)
	{
		//サイコロを振る
		Rolldice(dice1, dice2, sumdice);cout << endl;
		//現在のマスを表示
		Board(b);
		if (turn == 0)
		{
			cout << "あなたのターンです。\n";
			//取得可能マスがあるか確認
			bool take = false;
			if (!b[dice1])
			{
				take = true;
			}
			if (!b[dice2])
			{
				take = true;
			}
			if (!b[sumdice])
			{
				take = true;
			}
			if (!take)
			{
				cout << "取得可能マスがありません。ゲーム終了です。\n";
				break;
			}
			//入力チェック
			while (true)
			{
				cout << "取るマスを選んでください：";
				cin >> player;

				// サイコロの目、または合計かチェック
				if (player == dice1 ||
					player == dice2 ||
					player == sumdice)
				{
					// すでに取られていないか確認
					if (!b[player])
					{
						b[player] = true;
						taken++;

						cout << player << "のマスを取りました！" << endl;
						cout << endl;
						break;
					}
					else
					{
						cout << "そのマスはすでに取られています。" << endl;
					}
				}
				else
				{
					cout << "そのマスは選べません。" << endl;
				}
			}
			// 全マス取得
			if (BoardComplete(taken))
			{
				cout << "あなたの勝ちです！\n";
				break;
			}
			// CPUのターンへ
			turn = 1;
		}
		else
		{
			cout << endl;
			cout << "CPUのターンです。\n";
			//取得可能マスがあるか確認
			if (!b[dice1])
			{
				cpu[count] = dice1;
				count++;
			}
			if (!b[dice2])
			{
				//同じマスが重複しないようにする
				if (dice2 != dice1)
				{
					cpu[count] = dice2;
					count++;
				}
			}
			if (!b[sumdice])
			{
				if (sumdice != dice1 && sumdice != dice2)
				{
					cpu[count] = sumdice;
					count++;
				}
			}
			//取得可能なマスがない
			if (count == 0)
			{
				cout << "CPUは取れるマスがありません。" << endl;
				cout << "あなたの勝ち！" << endl;
				break;
			}

			// CPUがランダムに選ぶ
			cpuchoice = cpu[rand() % count];

			b[cpuchoice] = true;
			taken++;

			cout << "CPUは " << cpuchoice << " のマスを取りました！" << endl;
			// 全マス取得
			if (BoardComplete(taken))
			{
				cout << "CPUの勝ちです！\n";
				break;
			}
			//PLAYERのターンへ
			turn = 0;
			cout << endl;
		}
			
	}
	
	cout << "ゲーム終了！" << endl;
}