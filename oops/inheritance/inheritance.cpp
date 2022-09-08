#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
class Human{
    private: 
    int weight;
    int height;
    int age;
    public:
    int getAge(){
        return this->age;
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
    cout << m1.getAge()<< endl;
}