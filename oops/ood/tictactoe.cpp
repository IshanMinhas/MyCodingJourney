#include<bits/stdc++.h>
using namespace std;

class Position
{
    private:
        int xValue,yValue;

    public:

        Position(int xValue, int yValue){
            this->xValue = xValue;
            this->yValue = yValue;
        }

        int getPositionXvalue()
        {
            return this->xValue;
        }

        int getPositionYvalue()
        {
            return this->yValue;
        }
};

class Player
{
    private:
        string name;
        char symbol;

    public:

        Player(string name, char symbol){
            this->name = name;
            this->symbol = symbol;
        }

        string getPlayerName()
        {
            return this->name;
        }

        char getPlayerSymbol()
        {
            return this->symbol;
        }

};

class Board
{
    private:
        int boardSize;
        int moves;
        int totalPossibleMoves;
        bool winnerFound;
        vector< vector<char> >board;

    public:

        Board(){
            this->boardSize = 3;
            this->moves = 0;
            this->totalPossibleMoves = 3*3;
            this->winnerFound = false;
            board.resize(3,vector<char>(3,'-'));
        }

        Board(int boardSize){
            this->boardSize = boardSize;
            this->moves = 0;
            this->totalPossibleMoves = boardSize*boardSize;
            this->winnerFound = false;
            board.resize(boardSize,vector<char>(boardSize,'-'));
        }

        bool isMovePossible()
        {
            if( this->moves < this->totalPossibleMoves ) return true;
            else return false;
        }

        bool isValidMove(int xValue, int yValue)
        {
            if( xValue < 0 || xValue >= this->boardSize || yValue < 0 || yValue >= this->boardSize ) return false;
            if( this->board[xValue][yValue] != '-' ) return false;
            return true;
        }


        bool isRowMatch(int xValue, int yValue, char playerSymbol)
        {
            for( int i = 0; i < this->boardSize; i++ )
            {
                if( this->board[xValue][i] != playerSymbol ) return false;
            }
            return true;
        }

        bool isColMatch(int xValue, int yValue, char playerSymbol)
        {
            for( int i = 0; i < this->boardSize; i++ )
            {
                if( this->board[i][yValue] != playerSymbol ) return false;
            }
            return true;
        }

        bool isDiagonalMatch(int xValue, int yValue, char playerSymbol)
        {
            int boradSize = this->boardSize;
            if( xValue - yValue == 0 )
            {
                for( int i = 0; i < boardSize; i++ )
                {
                    if( this->board[i][i] != playerSymbol ) return false;
                }
                return true;
            }
            return false;
        }

        bool isAntiDiagonalMatch(int xValue, int yValue, char playerSymbol)
        {
            int boradSize = this->boardSize;
            if( xValue + yValue == boardSize-1 )
            {
                for( int i = 0; i < boardSize; i++ )
                {
                    if( this->board[i][boardSize-i-1] != playerSymbol ) return false;
                }
                return true;
            }
            return false;
        }

        void updateBoard(Player* player, Position* position)
        {
            int xValue = position->getPositionXvalue();
            int yValue = position->getPositionYvalue();
            int symbol = player->getPlayerSymbol();
            this->board[xValue][yValue] = symbol;

            if( this->isRowMatch(xValue,yValue,symbol) || this->isColMatch(xValue,yValue,symbol) ) this->winnerFound = true;
            if( this->isDiagonalMatch(xValue,yValue,symbol) || this->isAntiDiagonalMatch(xValue,yValue,symbol) ) this->winnerFound = true;

            this->moves = (this->moves) + 1;
        }

        bool isWinnerFound()
        {
            if( this->winnerFound == true ) return true;
            else return false;
        }

        void showBoard()
        {
            for( int i = 0; i < boardSize; i++ )
            {
                for( int j = 0; j < boardSize; j++ )
                {
                    cout<<board[i][j];
                }
                cout<<endl;
            }
        }


};


void introducePlayers(vector<Player*>& playersQueue)
{
    int totalPlayers = playersQueue.size();
    cout<<"Welcome to Tic-Tac Toe Game :- "<<endl;

    for( int i = 0; i < totalPlayers; i++ )
    {
        cout<<"Player - "<<(i+1)<<" :-"<<endl;
        cout<<"Name : "<<playersQueue[i]->getPlayerName()<<endl;
        cout<<"Playing symbol : "<<playersQueue[i]->getPlayerSymbol()<<endl;
        cout<<endl;
    }

}


int main()
{
    int numberOfPlayers = 2;
    vector<Player*>playersQueue;
    string playerSymbol = "XO";
    int winnerID = -1;
    int currentPlayer = 0;

    for( int i = 0; i < numberOfPlayers; i++ )
    {
        string name;
        cout<<"Enter Player - "<<i+1<<" Name :"<<endl;
        cin>>name;

        Player* player = new Player(name,playerSymbol[i]);
        playersQueue.push_back(player);
    }

    introducePlayers(playersQueue);

    cout<<"Initializing Board"<<endl;
    Board* gameBoard = new Board();
    gameBoard->showBoard();

    while( gameBoard->isMovePossible() )
    {
        int xValue,yValue;
        bool validMove = false;

        while( validMove != true )
        {
            cout<<"Player - "<<(currentPlayer+1)<<" : Enter x co-ordinate and y co-ordinate in 0 based Indexing, where you want to play"<<endl;
            cin>>xValue>>yValue;

            if( gameBoard->isValidMove(xValue,yValue) == true )
            {
                validMove = true;
                cout<<"Valid Move, Processing...."<<endl;
            }
            else
            {
                cout<<"Please Retry,current Move is not valid. Check the board, and then enter"<<endl;
                gameBoard->showBoard();
                cout<<endl;
            }

        }

        Position* position = new Position(xValue,yValue);
        gameBoard->updateBoard(playersQueue[currentPlayer],position);

        if( gameBoard->isWinnerFound() )
        {
            winnerID = currentPlayer;
            break;
        }

        gameBoard->showBoard();
        currentPlayer = (currentPlayer+1)%numberOfPlayers;
    }

    if( winnerID == -1 )
    {
        if( gameBoard->isMovePossible() == true ) cout<<"Unexpected Error - Game Terminated"<<endl;
        else cout<<"Game Tied"<<endl;
    }
    else
    {
        cout<<"Player - "<<(winnerID+1)<<" is Winner"<<endl;
        cout<<"Congrats "<<playersQueue[winnerID]->getPlayerName()<<endl;
    }

    gameBoard->showBoard();

    return 0;
}