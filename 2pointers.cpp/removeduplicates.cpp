class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int i =n -2  ; int j= n - 1 ; int count = 0 ;
        int k = n-1 ;
        while(i>=0){
            if(a[i] != a[j]){
                i--; j-- ;
            }else if(a[i]== a[j]){
                swap(a[j] , a[k]);
                k-- ; i-- ; j--;
            }
        }
       
        sort(a.begin() , a.begin() + k+1);
         cout << a[k] << endl;
        return k+1;
    }
};