#define intMin -99999

//recursion  T(n) = O(2^n),
int maxMoneyLootedRec(int *arr,int n){
    if (n<=0) return 0;

    if(n <= 2) 
       return n == 1 ? arr[0] : max(arr[0], arr[1]);

    int select = maxMoneyLootedRec(arr,n-2)+arr[n-1]; // for top-to-bottom use (arr+2,n-2)+arr[0]
    int notSelect = maxMoneyLootedRec(arr,n-1); // for top-to-botton use here (arr+1, n-1)
    return max(select,notSelect);
}

/*******************/
// time: 0(N)
int maxMoneyLootedMemoHelper(int *arr,int n, int* memo){
    if (n<=0) return 0;

    if(n <= 2) 
       return n == 1 ? arr[0] : max(arr[0], arr[1]);

    if(memo[n] != -1)   
       return memo[n];

    int select = maxMoneyLootedMemoHelper(arr,n-2, memo)+arr[n-1]; // for top-to-bottom use (arr+2,n-2)+arr[0]
    int notSelect = maxMoneyLootedMemoHelper(arr,n-1, memo); // for top-to-botton use here (arr+1, n-1)
    memo[n] = max(select,notSelect);

    return memo[n];
}

int maxMoneyLootedMemo(int *arr, int n) {
    if (n<=0) return 0;
    if(n <= 2) 
       return n == 1 ? arr[0] : max(arr[0], arr[1]);

    int *memo = new int[n+1];
    for(int i=0; i<=n; i++)
       memo[i] = -1;

    int maxLoot = maxMoneyLootedMemoHelper(arr, n, memo);

    // delete space
    delete[] memo;

    return maxLoot;
}

/*********************/
// time: O(n)
int maxMoneyLootedDP(int *arr, int n) {
    if (n<=0) return 0;
    if(n <= 2) 
       return n == 1 ? arr[0] : max(arr[0], arr[1]);

    int *dp = new int[n+1]();

    // below 0-based house indexing is also correct
    // dp[0] = arr[0];
    // dp[1] = max(arr[0], arr[1]);
    // for(int i=2; i<n; i++) {
    //     dp[i] = max(dp[i-2] + arr[i], dp[i-1]);
    // }
    // int maxLoot = dp[n-1];

    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);

    for(int i=3; i<=n; i++) {
        dp[i] = max(dp[i-2] + arr[i-1], dp[i-1]);
    }

    int maxLoot = dp[n];

    // delete space
    delete[] dp;

    return maxLoot;
}

/*********************/

int maxMoneyLooted(int *arr, int n) {
    return maxMoneyLootedDP(arr, n);
}
