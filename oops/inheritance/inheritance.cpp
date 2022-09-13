#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
class Human{
     public:
    int weight;
    int height;
    int age;

    int getAge(){
        return this->age;
    }
    int getweight(){
        return this->weight;
    }
    void setWeight(int weight){
        this->weight = weight;
    }



};

class Male : public Human{
    public :
    string color;
    void sleep(){
        cout << "male sleeping" << endl;
    }
};
int main(){
    Male m1; 
    cout << m1.age << endl;
    cout << m1.weight << endl;
    cout << m1.color << endl;
    m1.sleep();
    m1.setWeight(84);
    cout << m1.getweight()<< endl;
}