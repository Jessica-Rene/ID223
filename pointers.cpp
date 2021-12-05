// Jessica Reyes ID223
// Fall 2021 Pointers Code Creation

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
// & changed to * for dereferencing, and const board
void displayBoard(const vector<char>* const board);
char winner(const vector<char>* const board);
bool isLegal(const vector<char>* const board, int move);
int humanMove(const vector<char>* const board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);




int main() {
    int move;
    // (0-8)
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);

    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    
    displayBoard(&board);
   
    while (winner(&board) == NO_ONE)
    {
        
        if (turn == human)
        {
            move = humanMove(&board, human);
            board[move] = human;
        }
        
        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
       
        displayBoard(&board);
        turn = opponent(turn);
    }
    
    announceWinner(winner(&board), computer, human);
    return 0;
} 

// The game instructions.
void instructions()
{
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
    cout << "--where human brain is pit against silicon processor\n\n";

    cout << "Make your move known by entering a number, 0 - 8. The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";

    cout << "0 | 1 | 2\n";
    cout << "---------\n";
    cout << "3 | 4 | 5\n";
    cout << "---------\n";
    cout << "6 | 7 | 8\n";

    cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

// Wants a 'y' or 'n' response from the question asked. (will keep asking until the response entered  is a 'y' or 'n')
char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << "(y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');
    return response;
}

// In the prototype it uses 0 as default, wants you to pick a number within range(0-8)
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

// determines the 'X' and 'O' value by answering 'y' to the question == 'X' and 'n' to the question == 'O'
char humanPiece()
{
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y')
    {
        cout << "\nThen take the first move. You will need it.\n";
        return X;
    }
    else
    {
        cout << "\nYour bravery will be your undoing...I will go first.\n";
        return O;
    }
}

// Calculates the opponent piece, if 'X' is entered, then opponent is 'O' when it's their turn, and vice versa.
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

void displayBoard(const vector<char>* const board)
{
    cout << "\n\t" << (*board)[0] << " | " << (*board)[1] << " | " << (*board)[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*board)[3] << " | " << (*board)[4] << " | " << (*board)[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*board)[6] << " | " << (*board)[7] << " | " << (*board)[8];
    cout << "\n\n";
}


char winner(const vector<char>* const board)
{
    // all possible winning rows, made with a constant 2-D array
    const int WINNING_ROWS[8][3] = { {0, 1, 2},
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };

    const int TOTAL_ROWS = 8;


    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ( ((*board)[WINNING_ROWS[row][0]] != EMPTY) &&
             ((*board)[WINNING_ROWS[row][0]] == (*board)[WINNING_ROWS[row][1]]) &&
             ((*board)[WINNING_ROWS[row][1]] == (*board)[WINNING_ROWS[row][2]]) )
        {
            return (*board)[WINNING_ROWS[row][0]];
        }
    }
 
    if (count(board->begin(), board->end(), EMPTY) == 0)
        return TIE;

    return NO_ONE;
}

// pointer
inline bool isLegal(int move, const vector<char>* const &board)
{
 
    return ((*board)[move] == EMPTY);
}
// pointer
int humanMove(const vector<char>* const board, char human)
{
    int move = askNumber("Where will you move?", (board->size() - 1));

    while (!isLegal(move, board))
    {
       
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", (board->size() - 1));
    }
    
    cout << "Fine...\n";
   
    return move;
}

// Calculates and returns the computer's move. 
int computerMove(vector<char> board, char computer)
{
    unsigned int move = 0;
    bool found = false;

  
    while (!found && move < board.size())
    {
        // first is looking to win the game and get three in a row.
        // &board!
        if (isLegal(move, &board))
        {
            board[move] = computer;
            found = winner(&board) == computer;
            board[move] = EMPTY;
        }
        if (!found)
        {
            ++move;
        }
    }
    // otherwise, if human can win on next move, that's the move to make
    if (!found)
    {
        move = 0;
        char human = opponent(computer);
        // loop through all possible moves, (0-8)
        // blocking the human to 'win' the game
        while (!found && move < board.size())
        {
            // computer checks for a legal move for human to win the game, then computer blocks
            // pointer &board
            if (isLegal(move, &board))
            {
                board[move] = human;
                found = winner(&board) == human;
                board[move] = EMPTY;
            }
            if (!found)
            {
                ++move;
            }
        }
    }
    // otherwise, moving to the best open square is the move to make
    // the best empty square move after checking for win, blocking the human from winning, and finally 'computers' best move available.
    if (!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

        while (!found && i < board.size())
        {
            move = BEST_MOVES[i];
          
            if (isLegal(move, &board))
            {
                found = true;
            }
            ++i;
        }
    }
    
    cout << "I shall take square number " << move << endl;
   
    return move;
}

// Congratulates the winner or delclares a tie!
void announceWinner(char winner, char computer, char human)
{
    // Computer WINS!
    if (winner == computer)
    {
        cout << winner << " 's won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }
    // Human WINS!!!
    else if (winner == human)
    {
        cout << winner << " 's won!\n";
        cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
        cout << "But never again! I, the computer, so swear it!\n";
    }
    // TIE!!!!!
    else
    {
        cout << "It's a tie!\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate...for this is the best you will ever achieve.\n";
    }
}
