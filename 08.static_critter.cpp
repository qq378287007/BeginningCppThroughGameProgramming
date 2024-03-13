#include <iostream>
using namespace std;

class Critter
{
public:
    static int s_Total; // 静态成员变量声明
                        // total number of Critter objects in existence

    Critter(int hunger = 0);
    static int GetTotal(); // 静态成员函数声明

private:
    int m_Hunger;
};

int Critter::s_Total = 0; // 静态成员变量定义并初始化

Critter::Critter(int hunger) : m_Hunger(hunger)
{
    cout << "A critter has been born!" << endl;
    ++s_Total;
}

int Critter::GetTotal() // 静态成员函数定义，不能访问非静态数据成员
{
    return s_Total;
}

int main()
{
    cout << "The total number of critters is: ";
    cout << Critter::s_Total << "\n\n"; // 访问静态常用变量

    Critter crit1, crit2, crit3;

    cout << "\nThe total number of critters is: ";
    cout << Critter::GetTotal() << "\n"; // 调用静态成员函数

    return 0;
}
