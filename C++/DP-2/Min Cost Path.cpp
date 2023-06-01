// time: O(3^(n*m))
int minCostPathRecHelper(int **input, int n, int m, int i, int j) {
	if(i == n-1 && j == m-1)
	   return input[i][j];

	if(i >= n || j >= m)
	   return INT_MAX;

    int right = minCostPathRecHelper(input, n, m, i, j+1);
	int diagonal = minCostPathRecHelper(input, n, m, i+1, j+1);
	int down = minCostPathRecHelper(input, n, m, i+1, j);

	int minPath = min({right, diagonal, down});

	return minPath + input[i][j];
}

int minCostPathRec(int **input, int n, int m) {
	return minCostPathRecHelper(input, n, m, 0, 0);
}

//  ---------------------
// time: O(n*m)
int minCostPathMemoHelper(int **input, int n, int m, int i, int j, int **memo) {
	if(i == n-1 && j == m-1)
	   return input[i][j];

	if(i >= n || j >= m)
	   return INT_MAX;

	if(memo[i][j] != -1)
	   return memo[i][j];   

    int right =  minCostPathMemoHelper(input, n, m, i, j+1, memo); if(right<INT_MAX) memo[i][j+1]=right;
	int diagonal = minCostPathMemoHelper(input, n, m, i+1, j+1, memo); if(diagonal<INT_MAX) memo[i+1][j+1]=diagonal;
	int down = minCostPathMemoHelper(input, n, m, i+1, j, memo); if(down<INT_MAX) memo[i+1][j]=down;

	int minPath = min({right, diagonal, down});

	memo[i][j] = minPath + input[i][j];
	return memo[i][j];
}

int minCostPathMemo(int **input, int n, int m) {

   int **memo = new int*[n+1];
   for (int i = 0; i <= n; i++) {
      memo[i] = new int[m + 1];
	  for(int j=0; j<=m; j++)
	    memo[i][j] = -1;
    }

    int minCost = minCostPathMemoHelper(input, n, m, 0, 0, memo);

	// delete space
	for(int i=0; i<=n; i++)
	   delete[] memo[i];
	delete[] memo;   

	return minCost;
}

// ------------------------
// time: O(n*m)
int minCostDP(int **input, int n, int m) {
	int **dp = new int*[n+1];
   for (int i = 0; i <= n; i++) {
      dp[i] = new int[m+1]();
    }

	dp[n-1][m-1]=input[n-1][m-1]; //filing last box, since m-1, n-1 filled lets start from m-2, n-2

    //last row
    for(int j=m-2;j>=0;j--){
        dp[n-1][j]=input[n-1][j]+dp[n-1][j+1];
    }
   //last column
    for(int i=n-2;i>=0;i--){
        dp[i][m-1]=input[i][m-1]+dp[i+1][m-1];
    }
    
    for(int i=n-2;i>=0;i--){
      for (int j = m - 2; j >= 0; j--) {
          dp[i][j]=input[i][j]+min({dp[i][j+1], dp[i+1][j+1],dp[i+1][j] });
        }
    }
    int minCost = dp[0][0];
     
    // delete space
	for(int i=0; i<=n; i++)
	   delete[] dp[i];
	delete[] dp;  

	return minCost;
}



int minCostPath(int **input, int n, int m) {
	return minCostDP(input, n, m);
}
