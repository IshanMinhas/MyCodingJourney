#include<iostream>
using namespace std;
// function overloading
class A {

    public:
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }
    
    int sayHello(char name) {
        cout << "Hello Babbar" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout << "Hello " << name  << endl;
    }

};
// operator overloading
class B {
    public:
    int a;
    int b;

    public: 
    int add() {
        return a+b;
    }

    void operator + (B &obj ) {
        int val1 = this->a;
        int val2 = obj.a;
      
        cout << val2 - val1 <<endl;

       cout << "Hello Babbar" << endl;
    }

    void operator() () {
        cout << "main Bracket hu " << this->b << endl;
    }

};
// method overriding , run time polymorphism
class Animal {
    public:
    void speak() {
        cout << "Speaking "<< endl;
    }
};

class Dog: public Animal {

    public:
    void speak() {
        cout << "Barking " << endl;
    }


};



int main() {

    // Dog obj;
    // obj.speak();





    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;
    obj1.b = 7;
    cout << obj1.add() <<endl;
    
    obj1 + obj2;
    obj1();






// Function Overloading


    // A obj;
    // obj.sayHello( 1);
    


    // return 0;
}