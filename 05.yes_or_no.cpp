#include <iostream>
#include <string>
using namespace std;

char askYesNo1();                // 指定返回类型char
char askYesNo2(string question); // 指定参数string类型

int main()
{
    char answer1 = askYesNo1(); // 使用返回值
    cout << "Thanks for answering: " << answer1 << "\n\n";

    char answer2 = askYesNo2("Do you wish to save your game?"); // 形参传值
    cout << "Thanks for answering: " << answer2 << "\n";

    return 0;
}

char askYesNo1()
{
    char response1;
    do
    {
        cout << "Please enter 'y' or 'n': ";
        cin >> response1;
    } while (response1 != 'y' && response1 != 'n');

    return response1; // return返回值
}

// 封装，隐藏细节，分开独立代码
char askYesNo2(string question)
{
    char response2;
    do
    {
        cout << question << " (y/n): "; // 使用形参
        cin >> response2;
    } while (response2 != 'y' && response2 != 'n');

    return response2;
}
