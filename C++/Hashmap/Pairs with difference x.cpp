#include<bits/stdc++.h>

//correct, time: O(n). space: O(n)
int approach1(int *arr, int n, int x) {
	int numPair=0;
    unordered_map<int,int>m;
    
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    
    if(x == 0 && m.size()==1) return ((m[arr[0]]-1)*m[arr[0]])/2;
    
    for(int i=0;i<n;i++){
        int num1=m[arr[i]+x]; int num2=m[arr[i]-x];
        if(num1>0) numPair+=num1*m[arr[i]];
        if(num2>0) numPair+=num2*m[arr[i]];
        m[arr[i]]=0;
    }
    return numPair;
}

//correct, time: O(n). space: O(n)
int approach2(int *arr, int n, int k) {
    unordered_map<int, int> freq;
    int pairCount = 0;

    for (int i = 0; i < n; ++i) {
        int complement = arr[i] + k;
        pairCount += freq[complement];
        if (k != 0) {
            complement = arr[i] - k;
            pairCount += freq[complement];
        }
        ++freq[arr[i]];
    }
    return pairCount;
}


int getPairsWithDifferenceK(int *arr, int n, int x) {
  return approach1(arr, n, x);
}
