void findpermutations(int index, string&s, vector<string>&ans)
{
	if(index==s.size())
	{
		ans.push_back(s);
		return;
	}
	for(int i=index;i<s.size();i++)
	{
		swap(s[index],s[i]);
		findpermutations(index+1,s,ans);
		swap(s[index],s[i]);
	}
}

vector<string> findPermutations(string &s) {
    // Write your code here.
	   vector<string>ans;
       int index=0;
	findpermutations(index,s,ans);
	return ans;
}
void helper(string &ds , int freq[] , vector<string> &ans , string &s){
  
    if(ds.length()== s.length()){ 
        ans.push_back(ds);
        return;
     }
        
    for(int i =0; i< s.length(); i++){
        
            if(!freq[i]){
                ds.push_back(s[i]);
                freq[i] = 1;
                helper(ds, freq , ans, s);
                freq[i] = 0;
                ds.pop_back();
                }               
    }   
}
       

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string > ans; string ds = ""; 
    int freq[s.length()+1] = {0};    
   
    helper(ds , freq , ans, s);
    return ans;
}