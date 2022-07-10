class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       vector<int>ans;
        int x_or=0  ; 
        for(int i=0;i<nums.size();i++)
        {
            x_or=x_or^nums[i]; //xor of array  
        }
        int pos=0;
        int temp=x_or;
        while((temp&1)==0)//finding the rightmost set bit
        {
            pos++;
            temp=temp>>1;
        }
        int mask=1<<pos;//making the mask with set bit at pos index
        int num1=0;
        int num2=0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&mask)>0)//container1
            {
                num1^=nums[i];
            }
            else
            {
                num2^=nums[i];//container2
            }
        }
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
       
    
    }
};