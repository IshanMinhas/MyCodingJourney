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
/*What I have figured out after 3 hours is that :  
1 ) Why we are taking no of elements  <= mid ? Because if no of elements <= mid is equal to reqd count then it is sure that this mid is not going to be the answer. becoz either that mid is not part of matrix or that mid is part of matrix but has only 3 elements lesser than it (acc to this problem). So to discard this mid we consider count to be <= mid.

2) Why we take last low as answer?  becoz for the element at that low position , we have made sure that no of elements lesser than it are greater than reqd count. We can n't take any element greater than that because obviously it will have greater count. But there is chance that if we eliminate count of elements equal to it from that count,  we can have count = required count. for ex in this case 6 was answer for which we got count =7 and if we elminate all 6's from that 7 no's we will get exactly  4 no's less than 6.
