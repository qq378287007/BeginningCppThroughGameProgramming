#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> inventory; // 声明
	// 添加元素
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	cout << "You have " << inventory.size() << " items.\n"; // 向量大小

	cout << "\nYour items:\n";
	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		cout << inventory[i] << endl; // 向量索引
	}

	cout << "\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe"; // 向量元素赋值
	cout << "\nYour items:\n";
	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		cout << inventory[i] << endl;
	}

	cout << "\nThe item name '" << inventory[0] << "' has ";
	cout << inventory[0].size() << " letters in it.\n";

	cout << "\nYour shield is destroyed in a fierce battle.";
	inventory.pop_back(); // 移除最后一个元素
	cout << "\nYour items:\n";
	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		cout << inventory[i] << endl;
	}

	cout << "\nYou were robbed of all of your possessions by a thief.";
	inventory.clear();	   // 移除所有元素
	if (inventory.empty()) // 判断是否为空
	{
		cout << "\nYou have nothing.\n";
	}
	else
	{
		cout << "\nYou have at least one item.\n";
	}

	return 0;
}
