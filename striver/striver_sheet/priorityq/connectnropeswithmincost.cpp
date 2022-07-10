long long connectRopes(int* arr, int n)
{
    // Your code goes here
    priority_queue<int , vector<int > , greater<int > > minh;
    for(int i=0 ; i< n ;i++){
        minh.push(arr[i]);
    }
    int cost = 0;
    
    while( minh.size() >= 2 ){
        int first = minh.top(); 
        minh.pop();
        int second = minh.top(); 
        minh.pop();
        cost += first + second ; 
        int third = first + second ; 
        minh.push(third);
    }
    return cost;
}
