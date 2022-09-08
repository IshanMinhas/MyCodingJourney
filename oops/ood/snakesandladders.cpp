#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;


class Snake
{
    private:
        int head;
        int tail;

    public:
        Snake(int head, int tail)
        {
            this->head = head;
            this->tail = tail;
        }

        int getSnakeHead()
        {
            return this->head;
        }

        int getSnakeTail()
        {
            return this->tail;
        }

};

class Ladder
{
    private:
        int head;
        int tail;

    public:
        Ladder(int head, int tail)
        {
            this->head = head;
            this->tail = tail;
        }

        int getLadderHead()
        {
            return this->head;
        }

        int getLadderTail()
        {
            return this->tail;
        }

};

class Dice
{
    private:
        int numberOfDice;

    public:

        Dice()
        {
            this->numberOfDice = 1;
        }

        Dice(int numberOfDice)
        {
            this->numberOfDice = numberOfDice;
        }

        int getScore()
        {
            int totalScore = 0,presentScore;

            for( int i = 0; i < this->numberOfDice; i++ )
            {
                presentScore = 1 + ( rand()%6 );
                totalScore += presentScore;
            }

            return totalScore;
        }

};

class Player
{
    private:
        int id;
        string name;
        int currentPosition;

    public:

        Player(int id,string name)
        {
            this->id = id;
            this->name =name;
            this->currentPosition = 0;
        }

        int getPlayerID()
        {
            return this->id;
        }


        string getPlayerName()
        {
            return this->name;
        }

        int getPlayerCurrentPosition()
        {
            return this->currentPosition;
        }

        void setPlayerCurrentPosition(int nextPosition)
        {
            this->currentPosition = nextPosition;
        }

        bool checkWin()
        {
            if( this->currentPosition == 100 ) return true;
            else return false;
        }

};


class Board
{
    private:
        int boardsize;
        int numberOfSnakes;
        int numberOfLadders;
        std::tr1::unordered_map<int,Snake*>snakeList;
        std::tr1::unordered_map<int,Ladder*>ladderList;

    public:

        Board(int numberOfSankes, int numberOfLadder,std::tr1::unordered_map<int,Snake*>snakeList,std::tr1::unordered_map<int,Ladder*>ladderList)
        {
            this->numberOfSnakes = numberOfSankes;
            this->numberOfLadders = numberOfLadder;
            this->snakeList = snakeList;
            this->ladderList = ladderList;
        }

        Board(int boardsize,int numberOfSankes, int numberOfLadder,std::tr1::unordered_map<int,Snake*>snakeList,std::tr1::unordered_map<int,Ladder*>ladderList)
        {
            this->boardsize = boardsize;
            this->numberOfSnakes = numberOfSankes;
            this->numberOfLadders = numberOfLadder;
            this->snakeList = snakeList;
            this->ladderList = ladderList;
        }

        int geteExpectedPosition(Player* player, int score)
        {
            int currentPosition = player->getPlayerCurrentPosition();
            int expectedPosition = currentPosition+score;

            bool isSnakeOrLadder = true;
            int jump;

            while( isSnakeOrLadder )
            {
                if( (this->snakeList).find(expectedPosition) == (this->snakeList).end() )
                {
                    if( (this->ladderList).find(expectedPosition) == (this->ladderList).end() )
                    {
                        isSnakeOrLadder = false;
                    }
                    else
                    {
                        jump = (this->ladderList[expectedPosition])->getLadderTail();
                        expectedPosition = expectedPosition+jump;
                        isSnakeOrLadder = true;
                    }
                }

                if(  isSnakeOrLadder || (this->ladderList).find(expectedPosition) == (this->ladderList).end() )
                {
                    if( (this->snakeList).find(expectedPosition) == (this->snakeList).end() )
                    {
                        isSnakeOrLadder = false;
                    }
                    else
                    {
                        jump = (this->snakeList[expectedPosition])->getSnakeTail();
                        expectedPosition = expectedPosition+jump;
                        isSnakeOrLadder = true;
                    }
                }

            }

            return expectedPosition;
        }

        void updatePosition(Player* player, int score )
        {
            int currentPosition = player->getPlayerCurrentPosition();
            int expectedPosition = this->geteExpectedPosition(player,score);

            if( expectedPosition > 100 )
            {
                expectedPosition = currentPosition;
            }

            cout<<player->getPlayerName()<<" rolled "<<score<<" and moved from "<<currentPosition<<" to "<<expectedPosition<<endl;
            player->setPlayerCurrentPosition(expectedPosition);

        }
};



int main()
{
    int numberOfSnakes,numberOfLadders,numberOfPlayers;
    std::tr1::unordered_map<int,Snake*>snakeList;
    std::tr1::unordered_map<int,Ladder*>ladderList;
    vector< pair<Player*,bool> >allPlayers;

    cout<<"Enter Number of Snakes"<<endl;
    cout<<endl;
    cin>>numberOfSnakes;

    for( int i = 0; i < numberOfSnakes; i++ )
    {
        int head,tail;
        cout<<"Enter Snake-"<<(i+1)<<" Head & Tail "<<endl;
        cin>>head>>tail;
        if( head > tail )
        {
            Snake* snake = new Snake(head,tail);
            snakeList.insert({head,snake});
        }
    }

    cout<<"Enter Number of Ladders"<<endl;
    cout<<endl;
    cin>>numberOfLadders;

    for( int i = 0; i < numberOfLadders; i++ )
    {
        int head,tail;
        cout<<"Enter Ladder-"<<(i+1)<<" Head & Tail "<<endl;
        cin>>head>>tail;
        if( head < tail )
        {
            Ladder* ladder = new Ladder(head,tail);
            ladderList[head] = ladder;
        }
    }

    cout<<"Enter Number of Players"<<endl;
    cout<<endl;
    cin>>numberOfPlayers;

    for( int i = 0; i < numberOfPlayers; i++ )
    {
        cout<<"Enter Player-"<<(i+1)<<" Name: "<<endl;
        string name;
        cin>>name;

        Player* player = new Player(i,name);
        allPlayers.push_back({player,true});
    }

    cout<<"Initializing Board....."<<endl;
    cout<<endl;
    Board* board = new Board(numberOfSnakes,numberOfLadders,snakeList,ladderList);

    cout<<"Initializing Dice....."<<endl;
    cout<<endl;
    Dice* dice = new Dice();

    int currentPlayer = 0;
    int participants = numberOfPlayers;

    cout<<"Lets start the Game ....."<<endl;
    cout<<endl;

    while( participants > 1 )
    {
        if( allPlayers[currentPlayer].second == false )
        {
            currentPlayer = (currentPlayer+1)%numberOfPlayers;
        }
        else
        {
            int score = dice->getScore();
            board->updatePosition(allPlayers[currentPlayer].first,score);

            if( allPlayers[currentPlayer].first->checkWin() == true )
            {
                cout<<(allPlayers[currentPlayer].first)->getPlayerName()<<" wins the game"<<endl;
                cout<<endl;
                allPlayers[currentPlayer].second = false;
                participants--;
            }

            currentPlayer = (currentPlayer+1)%numberOfPlayers;

        }
    }

    return 0;

}