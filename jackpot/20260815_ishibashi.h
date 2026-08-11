#pragma once
//定数
const int DICE = 6;
const int MIN = 1;
const int MAX = 9;
//関数プロトタイプ宣言
int InputCheck(int min, int max);
void Board(bool b[]);
bool BoardComplete(int t);
void Rolldice(int &dice1, int &dice2, int &sumdice);
void Game();
