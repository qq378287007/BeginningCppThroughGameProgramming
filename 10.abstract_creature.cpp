#include <iostream>
using namespace std;

class Creature // 抽象类
{
public:
    Creature(int health = 100);
    virtual void Greet() const = 0; // 纯虚函数
    virtual void DisplayHealth() const;

protected:
    int m_Health;
};

Creature::Creature(int health)
    : m_Health(health)
{
}

void Creature::DisplayHealth() const
{
    cout << "Health: " << m_Health << endl;
}

class Orc : public Creature
{
public:
    Orc(int health = 120);
    virtual void Greet() const override;
};

Orc::Orc(int health)
    : Creature(health)
{
}

void Orc::Greet() const // 重写纯虚函数
{
    cout << "The orc grunts hello.\n";
}

int main()
{
    Creature *pCreature = new Orc();
    pCreature->Greet();
    pCreature->DisplayHealth();
    delete pCreature;
    pCreature = nullptr;

    return 0;
}
