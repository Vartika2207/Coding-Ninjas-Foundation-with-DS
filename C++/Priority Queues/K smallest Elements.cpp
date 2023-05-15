#include<bits/stdc++.h>
#include <queue>

//correct-old code, time: O(n), space: O(1)
vector<int> kSmallest_approach1(int arr[], int n, int k){
    priority_queue<int>pq;
    vector<int>ans;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    
    for(int i=k;i<n;i++){
        if(pq.top()>arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

//time: O(n(log(k))-> traversing on priority_queue
vector<int> kSmallest_approach2(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto i=0; i<n; i++) 
       pq.push(arr[i]);

    vector<int> kSmallEle;
    for(int i=0; i<k; i++) {
        kSmallEle.push_back(pq.top());
        pq.pop();
    }
    return kSmallEle;
}

vector<int> kSmallest(int arr[], int n, int k){
    return kSmallest_approach2(arr, n, k);
}
