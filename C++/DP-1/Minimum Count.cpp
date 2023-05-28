
//time: O(root(n)^(n))-> not sure tc
int minCountRec(int n) {
	if(n <= 3)
	   return n;

	int count = n; //max possible count will be n, i.e. 1*1 + 1*1 + ...... (n-times)

	for(int i=1; i<= sqrt(n); i++) {
		int rec_count = minCountRec(n - i*i);
		count = min(count, rec_count+1);
	}   
	return count;
}

// ------------------------------
//time: O(n*sqrt(n))
int minCountMemoHelper(int n, int *memo) {
	if(n <= 3)
	   return n;

	if(memo[n] != -1)
	   return memo[n];   

	int count = n;

	for(int i=1; i<= sqrt(n); i++) {
		int rec_count = minCountMemoHelper(n - i*i, memo);
		count = min(count, rec_count+1);
	}   
	memo[n] = count;
}

int minCountMemo(int n) {
	int *memo = new int[n+1]();
    for(int i=0; i<=n; i++)
	   memo[i] = -1;
	memo[0] = 0;

	return minCountMemoHelper(n, memo);  
}


//  -------------------------------
//time: O(n*sqrt(n))
int minCountDP(int n) {
	if(n <= 3)
	   return n;

	int *dp = new int[n+1]();
	dp[1] = 1;

	for(int i=2; i<=n; i++) {
		dp[i] = i;
		for(int j=1; j*j <= i; j++) {
			dp[i] = min(dp[i], dp[i-j*j]+1);
		}
	}   
    int count = dp[n];
	delete dp;
	return count;
}

int minCount(int n) {
	return minCountDP(n);
}
