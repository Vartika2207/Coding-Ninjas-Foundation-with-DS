// time: O(nm)
int countWaysToMakeChange(int coins[], int numCoins, int value){
	int **dp=new int*[numCoins+1];
    for(int i=0;i<numCoins+1;i++){
        dp[i]=new int[value+1];
    }
    
    dp[0][0]=1;//represent possible ways in which we can make value=0 using zero coins i.e coins=0, coins[]={}
    for(int i=1;i<=numCoins;i++){ //row filling
        dp[i][0]=1;
    }
    for(int i=1;i<=value;i++){//col wise
        dp[0][i]=0;
    }
    
    for(int i=1;i<=numCoins;i++){
        for(int j=1;j<=value;j++){
            if(j<coins[i-1]){
               dp[i][j] = dp[i-1][j];;
            }
            else{
                int choseThatCoin=dp[i][j-coins[i-1]];
                int notChoseThatCoin=dp[i-1][j];    
                dp[i][j]=choseThatCoin+notChoseThatCoin;
            }
        }
    }
    int ways= dp[numCoins][value];
    
    for(int i=0;i<=numCoins;i++){
        delete[] dp[i];
    }
  //  delete[] dp;
    return ways;
}
