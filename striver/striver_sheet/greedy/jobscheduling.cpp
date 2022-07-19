class Solution 
{
   public:
   
   static bool comp(Job a,Job b){
       
       return a.profit>b.profit;
   }
   
   int findPos(int pos,vector<int> &parent){
       
       if(parent[pos]==0) return -1;
       if(parent[pos] == pos) return parent[pos] = pos-1;
       
       return parent[pos] = findPos(parent[pos],parent);
   }

   vector<int> JobScheduling(Job arr[], int n) 
   { 
        
        vector<int> parent(102);
        
        for(int i=0;i<=101;i++) parent[i] = i;
        
        sort(arr,arr+n,comp);
        
        int mx = 0, count = 0;
        
        for(int i=0;i<n;i++){
            
            int pos = findPos(arr[i].dead,parent);
            
            if(pos==-1) continue;
            
            mx += arr[i].profit;
            count++;
            
        }
        
        return {count,mx};
        
   } 
};