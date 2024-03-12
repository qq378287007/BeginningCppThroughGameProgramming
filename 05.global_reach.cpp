#include <iostream>
using namespace std;

int glob = 10; // 全局变量定义并初始化
void access_global();
void hide_global();
void change_global();

int main()
{
    cout << "In main() glob is: " << glob << "\n\n"; // 访问全局变量
    access_global();

    hide_global();
    cout << "In main() glob is: " << glob << "\n\n";

    change_global();
    cout << "In main() glob is: " << glob << "\n\n";

    return 0;
}

void access_global()
{
    cout << "In access_global() glob is: " << glob << "\n\n"; // 访问全局变量
}

void hide_global()
{
    int glob = 0; // 隐藏全局变量
    cout << "In hide_global() glob is: " << glob << "\n\n";
}

void change_global()
{
    glob = -10; // 改变全局变量
    cout << "In change_global() glob is: " << glob << "\n\n";
}
