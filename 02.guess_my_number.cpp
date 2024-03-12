#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); // seed random number generator

	int secretNumber = rand() % 100 + 1; // 生成随机数
	int tries = 0;
	int guess;

	cout << "\tWelcome to Guess My Number\n\n";

	do
	{
		cout << "Enter a guess: ";
		cin >> guess; // 获取用户猜测
		++tries;	  // 增加猜测次数

		// 告知猜测情况
		if (guess > secretNumber)
		{
			cout << "Too high!\n\n";
		}
		else if (guess < secretNumber)
		{
			cout << "Too low!\n\n";
		}
		else
		{
			cout << "\nThat's it! You got it in " << tries << " guesses!\n";
		}

	} while (guess != secretNumber); // 是否猜对

	return 0;
}
