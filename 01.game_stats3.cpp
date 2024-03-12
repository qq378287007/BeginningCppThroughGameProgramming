#include <iostream>
using namespace std;

int main()
{
	const int ALIEN_POINTS = 150; // 常量，经过命名的无法修改的值
	int aliensKilled = 10;
	int score = aliensKilled * ALIEN_POINTS;
	cout << "score: " << score << endl;

	enum difficulty // 枚举类型
	{
		NOVICE,
		EASY,
		NORMAL,
		HARD,
		UNBEATABLE
	};
	difficulty myDifficulty = EASY;

	enum shipCost
	{
		FIGHTER_COST = 25,
		BOMBER_COST,
		CRUISER_COST = 50
	};
	shipCost myShipCost = BOMBER_COST;
	cout << "\nTo upgrade my ship to a Cruiser will cost "
		 << (CRUISER_COST - myShipCost) << " Resource Points.\n";

	return 0;
}
