/*******************/
/*******************/
// time: O(2^(n))
int knapsack_recursion(int *w, int *val, int n, int W){
    //base case
    if(n == 0 || W == 0){
        return 0;
    }
    
    if(W >= w[0]){
        int chose = knapsack_recursion(w+1, val + 1, n - 1, W - w[0]) + val[0];
        int not_chose = knapsack_recursion(w+1, val + 1, n - 1, W);
        return max(chose, not_chose);
    }
    else
        return knapsack_recursion(w+1, val + 1, n - 1, W);
}
/*******************/

/*******************/
// time: O(n*m)
int knapsack_memo(int *w, int *val, int n, int W, int** memo){
    //base case
    if(n == 0 || W == 0){
        return 0;
    }
    
    if(memo[n][W] != -1)
        return memo[n][W];
    
    if(W >= w[0]){
        int chose = knapsack_memo(w+1, val + 1, n - 1, W - w[0], memo) + val[0];
        int not_chose = knapsack_memo(w+1, val + 1, n - 1, W, memo);
        memo[n][W] = max(chose, not_chose);
    }  
    else
        memo[n][W] = knapsack_memo(w+1, val + 1, n - 1, W, memo);
    
    return memo[n][W];
}

int knapsack_memo_(int* w, int* val, int n, int W){
    int **memo = new int*[n+1];
    for(int i=0; i<=n; i++){
        memo[i] = new int[W+1];
        for(int j=0; j<=W; j++)
            memo[i][j] = -1;
    }
    
    //base case
    for(int i=0; i<=n; i++)
        memo[i][0] = 0;
    
    for(int i=0; i<=W; i++)
        memo[0][i] = 0;
    
    int ans = knapsack_memo(w, val, n, W, memo);
    
    //delete space
    for(int i=0; i<=n; i++)
        delete memo[i];
    delete[] memo;
    
    return ans;
}
/*******************/

/*********************/
// time: O(nxm)
int knapsackDP(int* weight, int* value, int n, int W) {
	if(n == 0 || W == 0){
        return 0;
    }

    int** dp = new int*[n+1];
    for(int i=0; i<=n; i++)
        dp[i] = new int[W+1]();
        
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            if(weight[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j],  dp[i-1][j - weight[i-1]] + value[i-1]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int val = dp[n][W];
    //delete space
     for(int i=0; i<=n; i++)
        delete dp[i];
    delete[] dp;

    return val;

}

/********************/

int knapsack(int* weight, int* value, int n, int maxWeight) {
	return knapsackDP(weight, value, n, maxWeight);
}






