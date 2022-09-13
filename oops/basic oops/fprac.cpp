#include<iostream>
#include<bits/stdc++.h> 
// #include"Hero.cpp"
using namespace std;

class Hero{
   public:
    int level; 
    char charr;
    const char * name;
    static int time;
    Hero(){
        cout << "this is default constr" << endl;

    }
    Hero(int level , char charr ,const char * name){
        this->level = level;
        this->charr = charr;
        this->name = name;
        cout << this << endl;


    }
    Hero(Hero &temp){

        this->charr= temp.charr;
        this->name = temp.name;
        this-> level = temp.level;
    }
    void setterlevel(int level){
        this->level = level;
    }

    int gettername(){
        return level;
    }
    void settername(char charr){
        this->charr = charr;
    }
    char gettercharr(){
        return charr;
    }
    ~Hero(){
        cout << "hakai" <<endl;
    }

};
int Hero::time = 5;


int main(){
    // Hero h1;
    // cout << h1.gettername() <<endl;
    // h1.settername('c');
    // cout << h1.gettercharr();
    // Hero * b = new Hero();
    // cout << (*b).gettername() <<endl;
    // Hero ram(11 , 'c', "sheesh");
    // cout << ram.name <<endl;
    // cout << ram.gettername() <<endl;

    
    // b->setterlevel(56);
    // Hero R(ram);
    // cout << R.name <<endl;
    // cout << R.gettername() <<endl;
    // ram.name = "ishann";
    // cout << R.name <<endl;
    // cout << ram.name <<endl;
    // delete b ;
    cout << Hero::time;
}









