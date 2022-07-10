#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class car{
    public:
    string id;
    int x,y;
    car(string id , int x ,int y){
        this->id =id;
        this->x = x;
        this->y = y;
    }
    int dist() const{
        return x*x +y*y;
    }

};

class carCompare{
    public:
    bool operator()(const car A , const car B){ // const cuz we are not changing data
        return A.dist() < B.dist(); // max heap
    }
};


void printNearestCars(vector<car> cars , int k){
    // create a max heap of size k
    priority_queue<car , vector<car> , carCompare> max_heap(cars.begin() , cars.begin() + k );
    // iterate over remaining cars
    for(int i = k; i < cars.size(); i++){
        auto Car = cars[i];
        if(Car.dist() < max_heap.top().dist()){
            max_heap.pop();
            max_heap.push(Car);
        }}
        while(!max_heap.empty()){
           cout <<  max_heap.top().id<< endl;
            max_heap.pop();
        }
        return;
    
}


int main(){ 
    int N,K;
    cin>>N>>K;
    string id;
    int x,y;
    vector <car> cars;
  
    for(int i=0  ;i<N ; i++){
        cin >> id>> x>> y;
          car Car(id,x,y);
        cars.push_back(Car);
    }
printNearestCars(cars,K);
}