class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       int n = wordList.size();
        unordered_set<string > sett;
        
        bool f =false; 
        for(auto word :wordList ){
            if(endWord == word)f= true;
            sett.insert(word);
        }
       
        if(f == false)return 0;
        queue<string >q ; 
        int depth = 0 ;
        q.push(beginWord);
        while(!q.empty()){
            depth++;
            int size = q.size();
            while(size--){
                string cur= q.front();
                q.pop();
                for(int i=0;i<cur.length();i++){
                    string t = cur; 
                    for(char c= 'a'; c<='z' ;c++){
                        t[i] = c;
                        if(endWord.compare(t)==0)return depth +1 ;
                         if(cur.compare(t)==0)continue;
                         if(sett.find(t)!= sett.end()){
                            q.push(t);
                            sett.erase(t);
                        }
                    }
                }               
            }
             
        }        
        return 0;
        
    }
};
