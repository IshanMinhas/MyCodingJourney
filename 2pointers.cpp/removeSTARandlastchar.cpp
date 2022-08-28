    class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto it : s){
            if(it == '*'){
                ans.pop_back();
            }else{
                ans+=it;
            }
           // cout <<ans<<endl;
        }
        return ans;
    }
};

static const auto speedup =[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();