#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int counttriangles(vector <pair<int , int>> &points  ){
    unordered_map<int, int> freq_x; // (value , freq)
    unordered_map<int, int> freq_y;
    for(auto p: points){
        int xaxisvalue = p.first;
        int yaxisvalue = p.second;
        freq_x[xaxisvalue]++;
        freq_y[yaxisvalue]++;

    }
    // count
    int count = 0;
    for(auto p: points){
        int x = p.first;
        int y = p.second;
        int fx = freq_x[x];
        int fy = freq_y[y];
        count += (fx-1)*(fy-1);
    }
    return count;
    // OVERALL COMPLEXITY IS O(N) TIME
}
int main(){
    int N;
    cin >> N;
    int x,y;
    vector <pair <int , int>> points;
    for(int i = 0 ; i<N ; i++){
        cin >> x >> y;
        points.push_back({x,y});
    }
    cout << counttriangles(points) << endl;
}