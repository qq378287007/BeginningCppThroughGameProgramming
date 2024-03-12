#include <iostream>
using namespace std;

int main()
{
	int score; // 变量声明
	double distance;
	char playAgain;
	bool shieldsUp;

	short lives, aliensKilled; // 变量声明

	score = 0;
	distance = 1200.76;
	playAgain = 'y';
	shieldsUp = true;
	lives = 3;
	aliensKilled = 10; // 变量赋值

	double engineTemp = 6572.89; // 变量初始化

	cout << "\nscore: " << score << endl; // 显示变量值
	cout << "distance: " << distance << endl;
	cout << "playAgain: " << playAgain << endl;
	// skipping shieldsUp since you don't generally print Boolean values
	cout << "lives: " << lives << endl;
	cout << "aliensKilled: " << aliensKilled << endl;
	cout << "engineTemp: " << engineTemp << endl;

	int fuel;
	cout << "\nHow much fuel? ";
	cin >> fuel; // 获取用户输入
	cout << "fuel: " << fuel << endl;

	typedef unsigned short int ushort; // 定义新变量名
	ushort bonus = 10;
	cout << "\nbonus: " << bonus << endl;

	return 0;
}

// 基本类型
// bool, char, int, float, double

// 类型修饰符
// short, long, signed, unsigned

// 变量命名
// 字母，数字，下划线（非数字开头，非关键字）
// 命名准则:
// 描述性名称、前后一致、语言传统、短变量名

// 根据数据使用范围选择数据类型
