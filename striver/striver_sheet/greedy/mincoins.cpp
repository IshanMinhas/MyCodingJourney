int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int > deno = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n =deno.size(); int coins = 0;
    for(int i=n-1; i>=0 ; i--){
        while(amount >= deno[i]){
            amount  -= deno[i];
            coins++;
        }
    }
    return coins;
}
