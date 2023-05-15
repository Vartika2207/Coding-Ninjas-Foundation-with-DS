#include <bits/stdc++.h>
using namespace std;

//correct,  time: 0(n^2), space: O(n)
vector<int> approach1(int *arr, int n) {
    vector<int> ans={-1,-1};
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]]  = i;
    }

    int maxLen = 0;

    for(int i=0; i<n; i++) {
        int currEle = arr[i], len = 0;
        while(mp.find(currEle) != mp.end()) {
            currEle++;
            len++;
        }

        if(maxLen <= len) {
            if(maxLen == len) {
                // seq's start appeared first
                if(mp[ans[0]] > mp[arr[i]]) {
                    ans[0] = arr[i];
                    ans[1] = currEle-1;
                }
          }
            else {
                maxLen = len;
                ans[0] = arr[i];
                ans[1] = currEle-1;
            }
        }
    }
 
    if(maxLen > 1)
       return ans;
    return {ans[0]};   
}

//correct, time: O(n), space: 0(2n)
vector<int> approach2(int *arr, int n) {
    
    unordered_map<int, bool> visitedElements;
    unordered_map<int, int> elementToIndexMapping;
    for (int i = 0; i < n; i++) {
        elementToIndexMapping[arr[i]] = i;
        if (visitedElements.count(arr[i]) == 0) {
             visitedElements[arr[i]] = true;
        }
    }
    vector<int> longestSequence;
    int globalMaxSequenceLength = 1;
    int globalMinStartIndex = 0;
    
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int currentMinStartIndex = i;
        int count = 0;
        int tempNum = num;
        // Forward
        while (visitedElements[tempNum] == true) {
            visitedElements[tempNum] = false;
            count++;
            tempNum++;
        }
        // Backward
        tempNum = num - 1;
        while (visitedElements[tempNum] == true) {
            visitedElements[tempNum] = false;
            count++;
            currentMinStartIndex = elementToIndexMapping[tempNum];
            tempNum--;
        }
        if (count > globalMaxSequenceLength) {
            globalMaxSequenceLength = count;
            globalMinStartIndex = currentMinStartIndex;
        } else if (count == globalMaxSequenceLength) {
            if (currentMinStartIndex < globalMinStartIndex) 
            globalMinStartIndex = currentMinStartIndex;
          }
        }

        int globalStartNum = arr[globalMinStartIndex];
        longestSequence.push_back(globalStartNum);
        if (globalMaxSequenceLength > 1) {
            longestSequence.push_back(globalStartNum + globalMaxSequenceLength - 1);
        }
        return longestSequence;
}

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    return approach2(arr, n);
}
