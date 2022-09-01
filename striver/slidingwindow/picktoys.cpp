 //https://leetcode.com/problems/fruit-into-baskets/submissions/
 // only 2 chars can be repeated sliding window
 // we use map cuz we only have 2 types of tpys and humne line se khilone uthanan hai

 // eg - > a a b c b b -> ans = 4;
 /*
    pehle a ko map mai daalo
    phir b ko
    jab c pe pahunche tab map ka size 2 tha
    to hum i ko move karenge tab tak jab tak map ka size less than 2 hojaye matlab 1 hojaye
    cnt store karke rakhna jab bhi map ka size 2 tha 
 */
 class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0 ; int j = 0 ;
        unordered_map<int , int > mpp;
        int cnt = 0 ;
        while(j < fruits.size()){
               
            if(mpp.find(fruits[j]) != mpp.end() || mpp.size() <2){
                 mpp[fruits[j]]++;
                cnt = max(j-i +1 ,cnt);
                j++;
            }else if(mpp.find(fruits[j]) == mpp.end()){
                
                while(mpp.size() == 2 ){
                    mpp[fruits[i]]--; 
                    if(mpp[fruits[i]]== 0 )mpp.erase(fruits[i]);
                    i++;
                }
                mpp[fruits[j]]++;
                j++;
                
            }
        }
    return cnt;
    }
    
};