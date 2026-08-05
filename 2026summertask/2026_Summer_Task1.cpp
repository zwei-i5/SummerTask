#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //変数
    int answer = -1;
    int question;
    int count = 0;
    //乱数初期化
    srand((unsigned int)time(nullptr));
    //数字生成
    question = rand() % 101;

    cout << "数字当てゲーム" << endl;
    cout << "0～100までの数字を当ててください。" << endl;
    //ゲーム開始
    while (question != answer)
    {
        //回数カウント
        count++;
        //入力チェック
        while (true)
        {
            cout << "0～100の数字を入力してください：" << endl;
            cin >> answer;

            if (answer < 0 || answer > 100)
            {
                cout << "入力に誤りがあります。再入力してください。" << endl;
            }
            else
            {
                break;
            }
        }
        //ヒント表示
        if (question > answer)
        {
            //小さいとき
            cout << "もっと大きい数字です。" << endl;
        }
        else if (question < answer)
        {
            //大きいとき
            cout << "もっと小さい数字です。" << endl;
        }
    }
    //正解時の結果表示
    cout << endl;
    cout << "おめでとうございます！正解です！" << endl;
    cout << "正解：" << answer << endl;
    cout << count << "回目で当てることができました。" << endl;

    return 0;
}