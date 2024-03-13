#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Card // 扑克牌
{
public:
    enum rank
    {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };
    enum suit
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };

    Card(rank r = ACE, suit s = SPADES, bool ifu = true)
        : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}

    int GetValue() const // 获取点数, 0 - 11
    {
        int value = 0; // 牌朝下为0
        if (m_IsFaceUp)
        {
            value = m_Rank;
            if (value > 10) // 人脸牌，点数为10
                value = 10;
        }
        return value;
    }

    void Flip() // 翻牌
    {
        m_IsFaceUp = !m_IsFaceUp;
    }

    friend ostream &operator<<(ostream &os, const Card &aCard);

private:
    rank m_Rank;     // 大小
    suit m_Suit;     // 花色
    bool m_IsFaceUp; // 是否正面朝上
};

class Hand // 持有牌
{
public:
    Hand()
    {
        m_Cards.reserve(7);
    }

    virtual ~Hand()
    {
        Clear();
    }

    void Add(Card *pCard)
    {
        m_Cards.push_back(pCard);
    }

    void Clear()
    {
        for (vector<Card *>::iterator iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            delete *iter;
        m_Cards.clear();
    }

    int GetTotal() const // 获取牌的最大点数，aces取1或11
    {
        if (m_Cards.empty() || m_Cards[0]->GetValue() == 0) // 无牌或者牌朝下
            return 0;

        int total = 0; // 所有牌点数加起来，假定Ace点数为1
        for (vector<Card *>::const_iterator iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            total += (*iter)->GetValue();

        if (total <= 11) // 点数和够低，Ace才可能取11
        {
            for (vector<Card *>::const_iterator iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            {
                if ((*iter)->GetValue() == Card::ACE) // 是否存在Ace
                {
                    total += 10; // 1变11，增加10
                    break;
                }
            }
        }

        return total;
    }

protected:
    vector<Card *> m_Cards;
};

class GenericPlayer : public Hand // 一般玩家
{
    friend ostream &operator<<(ostream &os, const GenericPlayer &aGenericPlayer);

public:
    GenericPlayer(const string &name = "") : m_Name(name) {}

    virtual ~GenericPlayer() {}

    // indicates whether or not generic player wants to keep hitting
    virtual bool IsHitting() const = 0;

    // returns whether generic player has busted - has a total greater than 21
    bool IsBusted() const
    {
        return GetTotal() > 21;
    }

    // announces that the generic player busts
    void Bust() const
    {
        cout << m_Name << " busts.\n";
    }

protected:
    string m_Name;
};

class Player : public GenericPlayer // 人类
{
public:
    Player(const string &name = "") : GenericPlayer(name) {}

    virtual ~Player() {}

    // returns whether or not the player wants another hit
    virtual bool IsHitting() const
    {
        cout << m_Name << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }

    // announces that the player wins
    void Win() const
    {
        cout << m_Name << " wins.\n";
    }

    // announces that the player loses
    void Lose() const
    {
        cout << m_Name << " loses.\n";
    }

    // announces that the player pushes
    void Push() const
    {
        cout << m_Name << " pushes.\n";
    }
};

class House : public GenericPlayer // 计算机
{
public:
    House(const string &name = "House") : GenericPlayer(name) {}

    virtual ~House() {}

    // indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const
    {
        return GetTotal() <= 16;
    }

    // flips over first card
    void FlipFirstCard()
    {
        if (!m_Cards.empty())
            m_Cards[0]->Flip();
        else
            cout << "No card to flip!\n";
    }
};

class Deck : public Hand // 堆牌，洗牌和发牌
{
public:
    Deck()
    {
        m_Cards.reserve(52);
        Populate();
    }

    virtual ~Deck() {}

    // create a standard deck of 52 cards
    void Populate()
    {
        Clear();
        // create standard deck
        for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
            for (int r = Card::ACE; r <= Card::KING; ++r)
                Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
    }

    // shuffle cards
    void Shuffle()
    {
        random_shuffle(m_Cards.begin(), m_Cards.end());
    }

    // deal one card to a hand
    void Deal(Hand &aHand)
    {
        if (!m_Cards.empty())
        {
            aHand.Add(m_Cards.back());
            m_Cards.pop_back();
        }
        else
        {
            cout << "Out of cards. Unable to deal.";
        }
    }

    // give additional cards to a generic player
    void AdditionalCards(GenericPlayer &aGenericPlayer)
    {
        cout << endl;
        // continue to deal a card as long as generic player isn't busted and
        // wants another hit
        while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
        {
            Deal(aGenericPlayer);
            cout << aGenericPlayer << endl;

            if (aGenericPlayer.IsBusted())
                aGenericPlayer.Bust();
        }
    }
};

class Game // 游戏
{
public:
    Game(const vector<string> &names)
    {
        // create a vector of players from a vector of names
        for (vector<string>::const_iterator pName = names.begin(); pName != names.end(); ++pName)
            m_Players.push_back(Player(*pName));

        // seed the random number generator
        srand(static_cast<unsigned int>(time(0)));
        m_Deck.Populate();
        m_Deck.Shuffle();
    }

    ~Game() {}

    // plays the game of blackjack
    void Play()
    {
        // deal initial 2 cards to everyone
        vector<Player>::iterator pPlayer;
        for (int i = 0; i < 2; ++i)
        {
            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
                m_Deck.Deal(*pPlayer);
            m_Deck.Deal(m_House);
        }

        // hide house's first card
        m_House.FlipFirstCard();

        // display everyone's hand
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
            cout << *pPlayer << endl;
        cout << m_House << endl;

        // deal additional cards to players
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
            m_Deck.AdditionalCards(*pPlayer);

        // reveal house's first card
        m_House.FlipFirstCard();
        cout << endl
             << m_House;

        // deal additional cards to house
        m_Deck.AdditionalCards(m_House);

        if (m_House.IsBusted())
        {
            // everyone still playing wins
            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
                if (!(pPlayer->IsBusted()))
                    pPlayer->Win();
        }
        else
        {
            // compare each player still playing to house
            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
                if (!pPlayer->IsBusted())
                    if (pPlayer->GetTotal() > m_House.GetTotal())
                        pPlayer->Win();
                    else if (pPlayer->GetTotal() < m_House.GetTotal())
                        pPlayer->Lose();
                    else
                        pPlayer->Push();
        }

        // remove everyone's cards
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
            pPlayer->Clear();
        m_House.Clear();
    }

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};

ostream &operator<<(ostream &os, const Card &aCard)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.m_IsFaceUp)
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    else
        os << "XX";

    return os;
}

ostream &operator<<(ostream &os, const GenericPlayer &aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";

    if (!aGenericPlayer.m_Cards.empty())
    {
        for (vector<Card *>::const_iterator pCard = aGenericPlayer.m_Cards.begin();
             pCard != aGenericPlayer.m_Cards.end();
             ++pCard)
            os << *(*pCard) << "\t";

        if (aGenericPlayer.GetTotal() != 0)
            cout << "(" << aGenericPlayer.GetTotal() << ")";
    }
    else
        os << "<empty>";

    return os;
}

int main()
{
    cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    // the game loop
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}
