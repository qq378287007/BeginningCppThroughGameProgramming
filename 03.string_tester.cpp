#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 创建string对象
    string word1 = "Game";
    string word2("Over");
    string word3(3, '!');

    string phrase = word1 + " " + word2 + word3; // string对象连接
    cout << "The phrase is: " << phrase << "\n\n";

    cout << "The phrase has " << phrase.size() << " characters in it.\n\n"; // size()成员函数

    cout << "The character at position 0 is: " << phrase[0] << "\n\n"; // 索引获取字符

    cout << "Changing the character at position 0.\n";
    phrase[0] = 'L'; // 索引字符赋值
    cout << "The phrase is now: " << phrase << "\n\n";

    for (unsigned int i = 0; i < phrase.size(); ++i) // 循环访问单个字符
    {
        cout << "Character at position " << i << " is: " << phrase[i] << endl;
    }

    cout << "\nThe sequence 'Over' begins at location ";
    cout << phrase.find("Over") << endl; // find()查找字符串

    if (phrase.find("eggplant") == string::npos) // 未找到
    {
        cout << "'eggplant' is not in the phrase.\n\n";
    }

    phrase.erase(4, 5); // 移除从位置4开始的长度为5个字符的子字符串
    cout << "The phrase is now: " << phrase << endl;

    phrase.erase(4);
    cout << "The phrase is now: " << phrase << endl;

    phrase.erase();
    cout << "The phrase is now: " << phrase << endl;

    if (phrase.empty())//是否空
    {
        cout << "\nThe phrase is no more.\n";
    }

    return 0;
}
