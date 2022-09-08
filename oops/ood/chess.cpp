#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class chess{

};
class Piece{ // abstract class / interface
    
    Position currentPosition;
    public :

    void Move(Position destination){
        if(isValid(currentPosition ,destination)){
            currentPosition = destination;
        }
    }
    bool isValid(Position start, Position end){
        Board temp = new Board();
        temp.MakeMove(this->piece , end);
        if(currentKingInCheck(temp))return false;
        else return true;
    }
    
    virtual void getAllPossibleMoves();

    bool currentKingInCheck(Board board){
        return false;
    }


};
class Board{
    public :
    void MakeMove(Piece x , Position destination){

    }
};

class Position{

};


class Pawn{
    
    public: 
    void enpessant(){

    }
    void doubleMove(){

    }
    void Promotion(){

    }
};
class King{
    public :
    void castle(){

    }
};
class Queen{

};
class Rook{

};
class Bishop{

};
class Knight{

};
