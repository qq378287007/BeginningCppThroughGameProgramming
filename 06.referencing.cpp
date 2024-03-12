#include <iostream>
using namespace std;

int main()
{
    int myScore = 1000;
    int &mikesScore = myScore; // 创建引用，声明时必须初始化

    cout << "myScore is: " << myScore << "\n";
    cout << "mikesScore is: " << mikesScore << "\n\n"; // 访问被引用的值

    cout << "Adding 500 to myScore\n";
    myScore += 500;
    cout << "myScore is: " << myScore << "\n";
    cout << "mikesScore is: " << mikesScore << "\n\n";

    cout << "Adding 500 to mikesScore\n";
    mikesScore += 500; // 修改被引用的值
    cout << "myScore is: " << myScore << "\n";
    cout << "mikesScore is: " << mikesScore << "\n\n";

    return 0;
}
