#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Animal{
    private : 
    int sing;
    int legs;
    bool bark;

    public:
    void print(){
        cout << legs <<endl;
    }

    int getLegs(){
       return legs;
    }

    bool isBark(){
        return bark;
    }

    void setLegs(int l){
        legs = l;
    }
    void setBark(bool x){
        bark = x;
    }
 
};
class Dog : public Animal {
    public:
   
    void Origins(){
        cout << "Germany" <<endl;
    }

};
// multilevel
class Pomi : public Dog{

};
class Tiger : public Animal{
    public : 
    void Roar(){
        cout << "ROARING" <<endl;
    }
};
// multiple
class Hybrid : public Tiger , public Dog{

};



int main(){
    
    Pomi Mini;
    Dog Doggy ;
    Doggy.setBark(true);
    Doggy.setLegs(4);
    //Doggy.Origins(); 
    cout << Doggy.isBark() <<endl;
    cout << Doggy.getLegs() << endl;  
    Mini.Origins() ;
    Hybrid Magic;
    Magic.Roar();
    Magic.Origins();





}















/*
class Animal{
    private : 
    int sing;
    int legs;
    bool bark;

    public:
    void print(){
        cout << legs <<endl;
    }

    int getLegs(){
       return legs;
    }

    bool isBark(){
        return bark;
    }

    void setLegs(int l){
        legs = l;
    }
    void setBark(bool x){
        bark = x;
    }
 
};
class Dog : public Animal {
    public:
   
    void Origins(){
        cout << "Germany" <<endl;
    }

};
// multilevel
class Pomi : public Dog{

};
class Tiger : public Animal{
    public : 
    void Roar(){
        cout << "ROARING" <<endl;
    }
};
// multiple
class Hybrid : public Tiger , public Dog{

};



int main(){
    
    Pomi Mini;
    Dog Doggy ;
    Doggy.setBark(true);
    Doggy.setLegs(4);
    //Doggy.Origins(); 
    cout << Doggy.isBark() <<endl;
    cout << Doggy.getLegs() << endl;  
    Mini.Origins() ;
    Hybrid Magic;
    Magic.Roar();
    Magic.Origins();





}*/