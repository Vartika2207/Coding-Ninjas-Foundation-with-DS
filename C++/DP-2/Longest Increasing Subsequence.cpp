#include <bits/stdc++.h>
using namespace std;

// time: O(n^2)
int longestIncreasingSubsequence(int* arr, int n) {
	int *dp=new int[n]();
    dp[0]=1;

    for(int i=1; i<n; i++){
        dp[i]=1;

        for(int j = i-1; j>=0; j--){
            if(arr[j] >= arr[i]){
                continue;
            }
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int best = *max_element(dp, dp + n);
   
    delete[] dp;

    return best;
}
