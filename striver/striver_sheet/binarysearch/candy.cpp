#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
#include<algorithm>
#include<climits>
#define ll long long int
#define MAX 1000000000
using namespace std;

bool isPossible(ll candies, ll arr[], ll total, ll n) {
  for(ll i = 0; i < n; i++) {
    total -= (arr[i] / candies);
  }
  if(total <= 0) 
    return true;
  return false;
}

int main() {
  ll tc, arr[50001];
  cin >> tc;
  
  while(tc--) {
    ll n, k;
    cin >> n >> k;
    
    for(ll i = 0; i < n; i++) {
      cin >> arr[i];
    }
    
    ll start = 1, end = MAX, maxm = LLONG_MIN;
    while(start <= end) {
      ll mid = (start + end) / 2;
      if(isPossible(mid, arr, k, n)) {
        maxm = maxm < mid ? mid : maxm;
        start = mid + 1;
      }
      else {
        end = mid - 1;
      }
    }
    maxm = maxm == LLONG_MIN ? 0 : maxm;
    cout << maxm << endl;
  }
}