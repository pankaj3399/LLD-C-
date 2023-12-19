#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

enum PieceType
{
    E, // for empty state
    X,
    O
};

class PlayingPiece
{
public:
    PieceType pieceType;
    PlayingPiece() {}
    PlayingPiece(PieceType pType)
    {
        pieceType = pType;
    }
};

class PlayingPieceX : public PlayingPiece
{
public:
    PlayingPieceX():PlayingPiece(X){}
};

class PlayingPieceO : public PlayingPiece
{
public:
    PlayingPieceO():PlayingPiece(O){}
};;

class Board
{
public:
    int size;
    vector<vector<PieceType> > board;
    Board(int sz){
       size = sz;
       board.resize(sz, vector<PieceType>(sz,E));
    }

    bool hasFreeCells(){
        bool ans = false;
        for(int i = 0; i <size; i++){
            for(int j= 0; j<size;j++){
                if(board[i][j] == 0){
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }

    bool addPiece(int row, int col, PlayingPiece * piece){
        if(board[row][col] == 0){
            board[row][col] = piece->pieceType;
            return true;
        }
        return false;
    }
};

class Player {
    public:
        string name;
        PlayingPiece* piece;
        Player(string nm, PlayingPiece* pc){
            name = nm;
            piece = pc;
        }
        string getName() {
            return name;
        };

        PlayingPiece* getPlayingPiece(){
            return piece;
        }

};

class TicTacToeGame {
    public:
        Board *gameBoard;
        deque<Player*> players;
        TicTacToeGame() {
            initializeGame();
        }

        void initializeGame(){
            gameBoard = new Board(3);
            deque<Player*> dq;
            Player* p1 = new Player("Pankaj", new PlayingPieceX());
            Player* p2 = new Player("Prashant", new PlayingPieceO());
            dq.push_back(p1);
            dq.push_back(p2);
            players = dq;
        }

        bool isWinner(int row, int col, PlayingPiece* piece){
            bool rowMatch = true;
            bool colMatch = true;
            bool diagonalMatch = true;
            bool antiDiagonalMatch = true;
            int size = gameBoard->size;
            for(int i=0;i<size;i++){
                if(gameBoard->board[row][i] == 0 || gameBoard->board[row][i] != piece->pieceType){
                    rowMatch = false;
                    break;
                }
            }

            for(int i=0; i<size;i++){
                if(gameBoard->board[i][col] == 0 || gameBoard->board[i][col] != piece->pieceType){
                    colMatch = false;
                    break;
                }
            }
            for(int i=0,j=0; i<size;i++,j++){
                if(gameBoard->board[i][j] == 0 || gameBoard->board[i][j] != piece->pieceType){
                    diagonalMatch = false;
                    break;
                }
            }
            for(int i=0,j=0; i<size;i++,j--){
                if(gameBoard->board[i][j] == 0 || gameBoard->board[i][j] != piece->pieceType){
                    antiDiagonalMatch = false;
                    break;
                }
            }
            return rowMatch || colMatch || diagonalMatch || antiDiagonalMatch;

        }

        string startGame(){
            bool winnerDeclared = false;
            while(!winnerDeclared){
                Player * playerToPlay = players.at(0);
                players.pop_front();
                bool isBoardFree = gameBoard->hasFreeCells();
                if(!isBoardFree){
                    winnerDeclared = true;
                    continue;
                }

                int row, col;

                cout << "Turn is of player " << playerToPlay->getName() << endl;
                cout << "Enter Row: " << endl;
                cin >> row ;
                cout << "Enter Column: "<< endl; 
                cin >> col;

                bool addPieceSuccessful = gameBoard->addPiece(row,col, playerToPlay->getPlayingPiece());
                if(!addPieceSuccessful){
                    cout << "Wrong move! Try again! " << endl;
                    players.push_front(playerToPlay);
                    continue;
                }
                players.push_back(playerToPlay);

                bool isWin = isWinner(row,col,playerToPlay->getPlayingPiece());
                if(isWin){
                    winnerDeclared = true;
                    return playerToPlay->getName();
                }
            }
            return "TIE";
        }

};

int main()
{
    TicTacToeGame * game = new TicTacToeGame();
    cout << game->startGame() << endl;
    return 0;
}