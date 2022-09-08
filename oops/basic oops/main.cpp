#include<iostream>
#include<bits/stdc++.h> 
// #include"Hero.cpp"
using namespace std;

class Hero{
    // properties
    private: 
    int health;
    public : 
    char level;
    char *name;
    //static keyword
    static int timetoComplete;

    // Constructore
    Hero(){
        name = new char[100]; // dynamicallu allocated name to prevent space wastage
        cout << "Default Constructor called" << endl;
    }

    // Parametrised Constructor
    Hero(int health){
        cout << "this ->" <<this <<endl; 
        this->health = health; // this points to Ramesh object and we want the new health from the func to be the health of ramesh 
    }
    Hero(int health, char level){
        cout << "this ->" <<this <<endl;
        // this->level == object's level and level is the input
        this->level = level; 
        this->health = health; // this points to Ramesh object and we want the new health from the func to be the health of ramesh 
    }

    //copy constructor
    Hero(Hero& temp){
        // char array for name for deep copy, if not used then we get shallow copy
        char *ch = new char[strlen(temp.name) +1 ];
        strcpy(ch,  temp.name); 
        this->name = ch;
        cout << "copy cons called" <<endl; 
        this->health = temp.health;
        this->level = temp.level;
    }


    void print(){
        cout << this->name<<endl;
        cout << this->level << endl;
        cout << this->health <<endl;
    }

    // getter
     int getHealth(){
        return health; 
    }
     int getLevel(){
        return level; 
    }

    // setter
    void setHealth(int h){
        health = h;
    }
    void setlevel(char l){
        level = l;
    }
    void setName(char name[]){
        strcpy(this->name, name);
    }
    // static fnc
    static int random(){
        return timetoComplete;
    }
    //destructor
    ~Hero(){
        cout << "destructor called" <<endl;
    }

};

// initalizing static keyword timetocomplete outside class
int Hero:: timetoComplete = 5;
// :: -> scope resolution operator


int main(){
    // //static data member can be accesesd without craeting obj
    // cout << Hero::timetoComplete << endl;
    // // with creating obj
    // Hero h1;
    // cout << h1.timetoComplete <<endl;
    // Hero h2;
    // h2.timetoComplete= 40;
    // cout << h2.timetoComplete <<endl;
    // cout << h1.timetoComplete <<endl;




    // destructor only called once for an object
   Hero a;
    Hero* b  =new Hero();
    // manually call destructor for dynamic craeted object but not for static craeted object
    delete b;


    return 0;




//   // copy assignment operator
//     Hero hero1(20 , 'c');
//     Hero hero(10 , 'a');
//     hero1.print(); hero.print();

//     hero1 = hero;
//     hero1.print();
//     hero.print(); 
  
  
  
  
  

  
  
    //  shallow and deep copy constructor
    // Hero hero1;
    // hero1.setHealth(50);
    // hero1.setlevel('H');
    // char name[6] = "Ishan";
    // hero1.setName(name);
    // hero1.print();
    // creating shallow copy using defalut copy constrructor    
    // Hero hero2(hero1);
    // hero2.print();
    
    // hero1.name[0] = 'K';
    // hero1.print();
    // hero2.print();
    
    
    
    
     
    

    // Copy CONSTRUCTOR
    // Hero suresh(70 , 'S');
    // suresh.print(); 
    // copy constructor
    // Hero R(suresh);
    // this means create object R and copy all vaalues of suresh in it
    // R.print();








    
    // //CONSTRUCTOR
    // // object static created
    // Hero ramesh;
    // ramesh.print();
    // // calling param construc
    // Hero ramesh1(10);
    // ramesh1.print();
    // cout << "address of ramesh1 " << &ramesh << endl;
    // // dynmic
    // Hero *h = new Hero(11);
    // h->print();
    // Hero temp(10 , 't' );
    // temp.print();












//     // creation of objct static allocation
//     Hero h1;
//     // dynammic
//     Hero *b  = new Hero;

//     // use getter
//     cout << "gethealth h1 " << h1.getHealth() << endl;
//     // use setter
//     h1.setHealth(20) ;  
//     h1.level = 'a';

//     // for h1
//     cout << "Health is " << h1.getHealth() << endl;
//     cout << "Level  is " << h1.level << endl;
    
//     // for b
//     b->level = 'B';
//     (*b).setHealth(50);
//     cout << "Health is " << (*b).getHealth() << endl;
//     cout << "Level  is " << (*b).level << endl;

//     // or 
    
//     cout << "Health is " << b->getHealth() << endl;
//     cout << "Level  is " << b->level  << endl;

// 
}








/*
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





int main(){
    Dog Doggy ;
    Doggy.setBark(true);
    Doggy.setLegs(4);
    Doggy.Origins(); 
    cout << Doggy.isBark() <<endl;
    cout << Doggy.getLegs() <<endl;  






}
*/