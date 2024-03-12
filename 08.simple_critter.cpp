#include <iostream>
using namespace std;

class Critter // 类定义，定义新类型Critter
{
public:
    int m_Hunger; // 声明数据成员
    void Greet(); // 声明成员函数
};

void Critter::Greet() // 成员函数定义
{
    cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n";
}

int main()
{
    Critter crit1; // 对象实例化
    Critter crit2;

    crit1.m_Hunger = 9; // 对象操作
    cout << "crit1's hunger level is " << crit1.m_Hunger << ".\n";

    crit2.m_Hunger = 3;
    cout << "crit2's hunger level is " << crit2.m_Hunger << ".\n\n";

    crit1.Greet(); // 成员函数调用
    crit2.Greet();

    return 0;
}
