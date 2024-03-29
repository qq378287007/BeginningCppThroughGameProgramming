#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    enum fields
    {
        WORD,
        HINT,
        NUM_FIELDS
    };
    const int NUM_WORDS = 5; // 单词列表以及提示
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
        {
            {"wall", "Do you feel you're banging your head against something?"},
            {"glasses", "These might help you see the answer."},
            {"labored", "Going slowly, is it?"},
            {"persistent", "Keep at it."},
            {"jumble", "It's what the game is all about."}};

    // 随机选择单词
    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD]; // word to guess
    string theHint = WORDS[choice][HINT]; // hint for word

    // 单词乱序
    string jumble = theWord; // jumbled version of word
    int length = jumble.size();
    for (int i = 0; i < length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    // 欢迎界面
    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is: " << jumble;

    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;

    // 游戏主循环
    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
        }
        else
        {
            cout << "Sorry, that's not it.";
        }

        cout << "\n\nYour guess: ";
        cin >> guess;
    }

    // 游戏结束
    if (guess == theWord)
    {
        cout << "\nThat's it!  You guessed it!\n";
    }

    cout << "\nThanks for playing.\n";

    return 0;
}
