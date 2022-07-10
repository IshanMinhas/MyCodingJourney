int f(int val , vector<int > rown){
    int l = 0; int h = rown.size()- 1;
    while(l <=h){
        int mid = (l+h)/2;
        if(rown[mid] >val ) h = mid- 1;
        else{l = mid+1;}    
    }
    return l;  
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 1;
    int high = 1e5;
    int n = matrix.size();
    int m = matrix[0].size();
    while(high>=low){
        int mid = (low+ high)/2; int cnt = 0;
        for(int i= 0; i<n; i++){
            cnt += f(mid , matrix[i]); 
        }
        if(cnt <= (n*m)/2) low = mid+1;
        else high = mid -1;        
    }
    return low;
}