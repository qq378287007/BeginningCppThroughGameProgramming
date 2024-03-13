#include <iostream>
#include <string>
using namespace std;

class Critter
{
    // 友元函数
    friend void Peek(const Critter &aCritter);
    friend ostream &operator<<(ostream &os, const Critter &aCritter);

public:
    Critter(const string &name = "");

private:
    string m_Name;
};

Critter::Critter(const string &name)
    : m_Name(name)
{
}

void Peek(const Critter &aCritter);
ostream &operator<<(ostream &os, const Critter &aCritter);

int main()
{
    Critter crit("Poochie");

    cout << "Calling Peek() to access crit's private data member, m_Name: \n";
    Peek(crit);

    cout << "\nSending crit object to cout with the << operator:\n";
    cout << crit;

    return 0;
}

void Peek(const Critter &aCritter)
{
    cout << aCritter.m_Name << endl;
}

// 运算符重载
ostream &operator<<(ostream &os, const Critter &aCritter)
{
    os << "Critter Object - m_Name: " << aCritter.m_Name;
    return os;
}
