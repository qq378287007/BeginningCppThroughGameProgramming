#include <iostream>
using namespace std;

int radiation(int health);//函数声明中不能使用inline

int main()
{
    int health = 80;
    cout << "Your health is " << health << "\n\n";

    health = radiation(health);
    cout << "After radiation exposure your health is " << health << "\n\n";

    health = radiation(health);
    cout << "After radiation exposure your health is " << health << "\n\n";

    health = radiation(health);
    cout << "After radiation exposure your health is " << health << "\n\n";

    return 0;
}

inline int radiation(int health)
{
    return (health / 2);
}
