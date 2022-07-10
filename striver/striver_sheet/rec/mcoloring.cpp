bool check(vector<vector<int >> &mat, int index,vector<int >&color ,int c ){
    for(int i = 0; i<mat.size(); i++){
        if(mat[index][i] ==1  and color[i] == c )return false;
        // mat[index][i] stores the nodes as 1 and 0 whichever is adjacent or not and color[i] == will ensure taht both index and adj node do not have the same color
    }
    return true;
    
}
bool helper(int index , vector<vector<int >> &mat, int m, vector<int>&color ){
    if(index == mat.size()){
        return true;
    }
    for(int i = 1; i<=m ; i++){
        if(check(mat, index , color, i)){
            color[index] = i;
            if(helper(index +1 , mat ,m, color))return true;
            else color[index] = 0;
        }
    }
    return false;    
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int >Color(mat.size() , 0);
    if(helper( 0 , mat , m , Color) == true)return "YES";
    else return "NO";
    
}