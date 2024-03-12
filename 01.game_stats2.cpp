#include <iostream>
using namespace std;

int main()
{
	unsigned int score = 5000;
	cout << "score: " << score << endl;

	// altering the value of a variable
	score = score + 100; // 修改变量值
	cout << "score: " << score << endl;

	// combined assignment operator
	score += 100; // 使用组合赋值运算符（+=，-=，*=，/=，%=）
	cout << "score: " << score << endl;

	// increment operators
	int lives = 3;
	++lives; // 前置递增运算符，--lives
	cout << "lives: " << lives << endl;

	lives = 3;
	lives++; // 后置递增运算符，lives--
	cout << "lives: " << lives << endl;

	lives = 3;
	int bonus = ++lives * 10;
	cout << "lives, bonus = " << lives << ", " << bonus << endl;

	lives = 3;
	bonus = lives++ * 10;
	cout << "lives, bonus = " << lives << ", " << bonus << endl;

	// integer wrap around
	score = 4294967295;
	cout << "\nscore: " << score << endl;
	++score; // 溢出，变为0
	cout << "score: " << score << endl;

	return 0;
}
