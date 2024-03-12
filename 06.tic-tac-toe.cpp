#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// function prototypes
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char> &board);
char winner(const vector<char> &board);
bool isLegal(const vector<char> &board, int move);
int humanMove(const vector<char> &board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

// main function
int main()
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY); // 空棋盘

    instructions();                  // 规则介绍
    char human = humanPiece();       // 人类选择先后手
    char computer = opponent(human); // 计算机取对手
    char turn = X;                   // X先手
    displayBoard(board);             // 显示棋盘

    while (winner(board) == NO_ONE) // 未分胜负
    {
        // 当前轮次
        if (turn == human)
        {
            move = humanMove(board, human); // 人类移动
            board[move] = human;            // 下棋
        }
        else
        {
            move = computerMove(board, computer); // 计算机移动
            board[move] = computer;               // 下棋
        }

        displayBoard(board);   // 显示棋盘
        turn = opponent(turn); // 轮次交替
    }

    announceWinner(winner(board), computer, human); // 宣布获胜情况

    return 0;
}

// 显示游戏操作指南
void instructions()
{
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
    cout << "--where human brain is pit against silicon processor\n\n";

    cout << "Make your move known by entering a number, 0 - 8.  The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";

    cout << "       0 | 1 | 2\n";
    cout << "       ---------\n";
    cout << "       3 | 4 | 5\n";
    cout << "       ---------\n";
    cout << "       6 | 7 | 8\n\n";

    cout << "Prepare yourself, human.  The battle is about to begin.\n\n";
}

// 一直询问，直到输入y或n
char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

// 一直询问，直到输入范围内的数值
int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number;
}

// 是否先手
char humanPiece()
{
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y')
    {
        cout << "\nThen take the first move.  You will need it.\n";
        return X;
    }
    else
    {
        cout << "\nYour bravery will be your undoing... I will go first.\n";
        return O;
    }
}

// 返回对手棋子
char opponent(char piece)
{
    if (piece == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

// 显示棋盘
void displayBoard(const vector<char> &board)
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t"
         << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t"
         << "---------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

// 返回获胜情况
// 玩家获胜，X或O
// 方格已填满且无人获胜，T
// 方格未填满且无人获胜，N
char winner(const vector<char> &board)
{
    // 8种获胜情况
    const int WINNING_ROWS[8][3] = {{0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {0, 4, 8},
                                    {2, 4, 6}};
    const int TOTAL_ROWS = 8;

    // if any winning row has three values that are the same (and not EMPTY),
    // then we have a winner
    for (int row = 0; row < TOTAL_ROWS; ++row)
    {
        // 非空且三个棋子相同，玩家获胜
        if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
            (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
            (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
        {
            return board[WINNING_ROWS[row][0]];
        }
    }

    // since nobody has won, check for a tie (no empty squares left)
    // 棋盘填满，平局
    if (count(board.begin(), board.end(), EMPTY) == 0)
        return TIE;

    // since nobody has won and it isn't a tie, the game ain't over
    // 未分胜负
    return NO_ONE;
}

// 棋盘上某个位置能否下棋（是否为空的）
inline bool isLegal(int move, const vector<char> &board)
{
    return (board[move] == EMPTY);
}

// 询问人类玩家输入方格号，直到合理且空位
int humanMove(const vector<char> &board, char human)
{
    int move = askNumber("Where will you move?", (board.size() - 1));
    while (!isLegal(move, board))
    {
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", (board.size() - 1));
    }
    cout << "Fine...\n";

    return move;
}

// 计算机获取最优下棋位置
int computerMove(vector<char> board, char computer)
{
    const unsigned NUM = board.size();
    // 遍历查找计算机能一步获胜的方格位置
    for (unsigned move = 0; move < NUM; move++)
    {
        if (isLegal(move, board)) // 当前位置为空
        {
            // 尝试移动
            board[move] = computer;
            // 测试计算机能否获胜
            if (winner(board) == computer)
                return move;
            // 撤销移动
            board[move] = EMPTY;
        }
    }

    // 遍历查找人类能一步获胜的方格位置
    char human = opponent(computer);
    for (unsigned move = 0; move < NUM; move++)
    {
        if (isLegal(move, board)) // 当前位置为空
        {
            // 尝试移动
            board[move] = human;
            // 测试人类能否获胜
            if (winner(board) == human)
                return move;
            // 撤销移动
            board[move] = EMPTY;
        }
    }

    // 中心》四边》四角
    const int BEST_MOVES[NUM] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
    for (unsigned move = 0; move < NUM; move++)
        if (isLegal(BEST_MOVES[move], board))
            return BEST_MOVES[move];

    return -1; // 不可能
}

// 宣布获胜情况
void announceWinner(char winner, char computer, char human)
{
    if (winner == computer)
    {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }

    else if (winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "No, no!  It cannot be!  Somehow you tricked me, human.\n";
        cout << "But never again!  I, the computer, so swear it!\n";
    }

    else
    {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achieve.\n";
    }
}
