#include "bits/stdc++.h"

int approach_naive(int* arr, int n) {
    // time: O(n*n)
}

//time: O(n), space: O(1)
int approach_better(int* arr, int n) {
    unordered_map<int, int> mp;

    for(int i=1; i<n; i++)
       arr[i] += arr[i-1];

    int maxLen = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            if(maxLen < (i+1))
               maxLen = i+1; //i+1, bcz i is 0-indexed
        }
        else if(mp.count(arr[i])) {
            //[re-order sum: 6 _ _ _ _ ____________  6_
            //                         <-sum b/t them is 0-->
            if(maxLen < (i-mp[arr[i]]))
               maxLen = i-mp[arr[i]];
        }
        else {
            mp[arr[i]] = i;
        }
    }
    return maxLen;
}


int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    return approach_better(arr, n);
}
