#include <iostream>
using namespace std;

class Enemy
{
public:
    Enemy(int damage = 10);
    virtual void Taunt() const;  // 声明虚基类成员函数
    virtual void Attack() const; // 重写函数声明成虚函数

private:
    int m_Damage;
};

Enemy::Enemy(int damage)
    : m_Damage(damage)
{
}

void Enemy::Taunt() const
{
    cout << "The enemy says he will fight you.\n";
}

void Enemy::Attack() const
{
    cout << "Attack! Inflicts " << m_Damage << " damage points.";
}

class Boss : public Enemy
{
public:
    Boss(int damage = 30);
    virtual void Taunt() const;           // virtual可省略
    virtual void Attack() const override; // override建议增加
};

Boss::Boss(int damage)
    : Enemy(damage) // 调用基类构造函数
{
    cout << "damage in Boss(int damage): " << damage << endl;
}

void Boss::Taunt() const // override base class member function
{
    cout << "The boss says he will end your pitiful existence.\n";
}

void Boss::Attack() const // override base class member function
{
    Enemy::Attack(); // 调用基类成员函数
    cout << " And laughs heartily at you.\n";
}

int main()
{
    cout << "Enemy object:\n";
    Enemy anEnemy;
    anEnemy.Taunt();
    anEnemy.Attack();

    cout << "\n\nBoss object:\n";
    Boss aBoss;
    aBoss.Taunt();
    aBoss.Attack();

    return 0;
}
