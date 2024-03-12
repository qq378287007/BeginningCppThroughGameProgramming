#include <iostream>
using namespace std;

class Critter
{
public:
    int m_Hunger;

    Critter(int hunger = 0); // 声明构造函数，提供默认参数
    void Greet();
};

Critter::Critter(int hunger) // 定义构造函数
{
    cout << "A new critter has been born!" << endl;
    m_Hunger = hunger;
}

void Critter::Greet()
{
    cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n\n";
}

int main()
{
    Critter crit(7);
    crit.Greet();

    return 0;
}
