#include <iostream>
#include<queue>
using namespace std;

// ----------WORKING below is bfs----------
void islandCountBFS(int **edges, int n, int s, bool *visited){ //or u can use dfs
    queue<int>pv;
    pv.push(s);
    while(!pv.empty()){
        s=pv.front();
        visited[s]=true;
        pv.pop();
        for(int i=0; i<n; i++){
            if(i==s) continue;
            if(edges[s][i] && !visited[i]){
                pv.push(i);
            }
        }
    }
}

// --WORKING below is dfs------
void islandCountDFS(int **edges, int n, int s, bool *visited){ //or u can use dfs
    visited[s] = true;

    for(int i=0; i<n; i++) {
        if(!visited[i] && i != s && edges[i][s]) {
            islandCountDFS(edges, n, i, visited);
        }
    }
}

// ---------main count------
int islandCount(int **edges, int n){
    bool *visited=new bool[n]();
    int count=0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            islandCountDFS(edges,n,i,visited);
            count++;
        }
    }

    // delete
    delete[] visited;
    return count;
}


int main() {
    int n,noOfEdges;
    cin>>n>>noOfEdges;
    int **edges=new int*[n];//adjacency matrix
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<noOfEdges;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    //write my code
   cout<<islandCount(edges,n);
    
    //free memory
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete edges;
}




