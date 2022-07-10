#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class point{
    public:
    int x;
    int y;
    
    point(int x , int y ){
        this ->x = x;
        this ->y = y;

    }
};


class compare{
    public:
    bool operator()(const point p1, point p2){
        if(p1.x == p2.x){
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }
};



int count_rectangles(vector<point> points ){

    set<point , compare> s;
    
    for(point p: points){
        s.insert(p);
    }
    int ans = 0;
    // brute force for first 2 points and then lookup for the last two
    for(auto it = s.begin(); it!=prev(s.end()); it++){
        for(auto jt = next(it); jt!= s.end(); jt++){
            point p1 = *it;
            point p2 = *jt;
            // small check to prevent any unwanted points
            if(p1.x == p2.x or p1.y == p2.y){
                continue;
            }
            point p3(p1.x , p2.y);
            point p4(p2.x , p1.y);
            // lookup
            if(s.find(p3)!= s.end() and s.find(p4)!=s.end()){
                ans +=1;
            }
        }
    }
    return ans/2;
// due to double counting along the diagonals






    
}
int main(){
    int N;
    cin >> N;
    int x , y;
    vector <point> points;
    for(int i = 0 ; i<N; i++){
        cin >> x>> y;
        point p(x,y);
        points.push_back(p);
    }
    cout << count_rectangles(points) << endl;



}