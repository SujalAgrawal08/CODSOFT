#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

void displayBoard(const vector<vector<char>>&board ){
    cout<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<" "<<board[i][j];
            if(j<2){
                cout<<" |";
            }
        }
        cout<<endl;
        if(i<2){
            cout<<"---|---|---"<<endl;
        }
    }
    cout<<endl;
}
void play(vector<vector<char>>&board, char move){
    int row, col;
    bool validMove = false;
    do {
        cout<<"Player "<<move<<", enter your move (row and column): ";
        cin>>row>>col;
        row--;
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = move;
            validMove = true;
        }
        else {
            cout<<"Invalid move. Please try again."<<endl;
        }
    } while(validMove!=true);

}
void switchPlayer(char& currPlayer) {
    currPlayer = (currPlayer == 'X') ? 'O' : 'X';
}
bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
bool winCheck(const vector<vector<char>>&board, char move){
    for(int i=0;i<3;i++){
        if(board[i][0]==move && board[i][1]==move && board[i][2]==move || board[0][i]==move && board[1][i]==move && board[2][i]==move){
            return true;
        }
    }
    if(board[0][0]==move && board[1][1]==move && board[2][2]==move || board[0][2]==move && board[1][1]==move && board[2][0]==move){
        return true;
    }
    return false;
}
bool checkDraw(const vector<vector<char>>& board) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main(){
    do {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currPlayer = 'X';
        bool win = false;
        bool draw = false;
        while (win!=true && draw!=true) {
            displayBoard(board);
            play(board, currPlayer);
            win = winCheck(board, currPlayer);
            if (win!=true) {
                draw = checkDraw(board);
                if (draw!=true) {
                    switchPlayer(currPlayer);
                }
            }
        }
        displayBoard(board);
        if (win==true) {
            cout<<"Player "<<currPlayer<<" wins!"<<endl;
        }
        else if(draw==true) {
            cout<<"The game is a draw!"<<endl;
        }
    }while(playAgain());
    return 0;
}
