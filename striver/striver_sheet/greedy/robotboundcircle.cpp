class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx[4] ={0,1,0,-1};
        int dy[4] ={1,0,-1,0}; // n , s , e, w
        int x = 0 ; int y = 0 ; int it = 0 ; // it is direction we are facing i.e n in the beg
        for(int i = 0 ; i< 4; i++) // 4 times cuz no matter what within 4 iter it has to face n , if not then it will never since we got 4 dire only
        {   
            for(char c : instructions){
                if(c == 'G'){
                    x += dx[it]; y+= dy[it]; // we move in the direction
                }
                else if(c == 'L'){
                    // we gotta change direc and it is our direc param
                    it = (it + 3)% 4;// mod so that it doesnt go past 4 since we got only 4 direc
                }else{
                    it  = (it + 1)%4 ;             
                }
            }
        
        if( x==0 && y == 0)return true ;
    }
        return false;
    }
};