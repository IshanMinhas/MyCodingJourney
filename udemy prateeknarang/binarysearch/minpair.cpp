#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//O(MlogM + NlogM)
// M is sorted array length and N is the comparing array and we used lower bound fnc
void min_pair(vector<int> a1 , vector<int> a2){
    sort(a2.begin() , a2.end());
    int p1 , p2;
    int diff =INT_MAX;
    for(int x : a1){
        auto lb =lower_bound(a2.begin(), a2.end() , x) -a2.begin();
        // left
        if(lb>=1 and x-a2[lb-1] <diff){
            diff  = x-a2[lb-1];
            p2 =x;
            p1 = a2[lb-1];

        }
// right greater
    if(lb!=a2.size() and a2[lb] -x<diff ){
        diff =a2[lb] -x;
        p1 = x;
        p2 = a2[lb];
    }
}
    cout<< "min pair" << p1 << "and "<< p2;
    return ;

}
int main(){
    vector <int> a1{ -1,5,20,10,3};
    vector<int>a2{26,134,135,15,17};
    min_pair(a1,a2);

}