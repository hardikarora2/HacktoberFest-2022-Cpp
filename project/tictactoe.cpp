#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char CurrentMarker;
int CurrentPlayer;
void DrawBoard()
{
    cout << "\t" << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl;
    cout << "     ------------\n";
    cout << "\t" << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl;
    cout << "     ------------\n";
    cout << "\t" << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl;
}
bool PlaceMarker(int slot)
{
    int row = slot / 3;
    int clm;
    if (slot % 3 == 0)
    {
        row = row - 1;
        clm = 2;
    }
    else
    {

        clm = (slot % 3) - 1;
    }
    if (board[row][clm] != 'X' && board[row][clm] != 'O')
    {
        board[row][clm] = CurrentMarker;
        return true;
    }
    return false;
}
int winner()
{
    for (int i = 0; i < 3; i++)
    {
        //For Row
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return CurrentPlayer;
        // For Clm
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return CurrentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return CurrentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return CurrentPlayer;
    return 0;
}
void swap_player_and_Marker()
{
    if (CurrentMarker == 'X')
    {
        CurrentMarker = 'O';
    }
    else
    {
        CurrentMarker = 'X';
    }

    if (CurrentPlayer == 1)
    {
        CurrentPlayer = 2;
    }
    else
    {
        CurrentPlayer = 1;
    }
}
void game()
{
    int win;
    cout << "Player one, choose your marker(Please choose X or O):";
    char markerP1;
    cin >> markerP1;
    CurrentPlayer = 1;
    CurrentMarker = markerP1;
    DrawBoard();
    for (int i = 0; i < 9; i++)
    {
        cout << "It's player " << CurrentPlayer << "'s turn. Enter your slot:";
        int slot;
        cin >> slot;
        if (slot < 1 || slot > 9)
        {
            cout << "That Slot is not found try another Slot:";
            i--;
            continue;
        }

        if (PlaceMarker(slot) != true)
        {
            cout << "That Slot is already Occupied try another Slot:";
            i--;
            continue;
        }

        system("CLS");
        DrawBoard();
        win = winner();
        if (win == 1)
        {
            cout << "Player One is the winner,Congratulations!";
            break;
        }
        if (win == 2)
        {
            cout << "Player Two is the winner,Congratulations!";
            break;
        }

        swap_player_and_Marker();
    }
    if (win == 0)
    {
        cout << "This is the tie match!";
    }
}

int main()
{
    game();
}
