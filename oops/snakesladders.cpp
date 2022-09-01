#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Board{
    



};



class Player{
    private:
        int startpos ;
        string name;
    public: 
        Player(int startpos , string name){
            this->name = name;
            this->startpos = startpos;
        }

    int getpos(){
        return startpos;
    }

    void setpos(int posi){
        startpos = posi;
    }

};


class Game{


};


class SpecialEntity{
    int startPos;
    int endPos;

};  


class Ladder : SpecialEntity {

};
class Snake :SpecialEntity{

};


class Dice{

};
