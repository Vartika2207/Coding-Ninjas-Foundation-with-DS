#include <bits/stdc++.h>
using namespace std;



void travelDFS(int **edgePath, int v, int sv, bool *visited){
    visited[sv]=true;
    for(int i=0;i<v;i++){
       // if(sv==i) continue; //self loop
        if(edgePath[sv][i]==1){
            if(visited[i]==true) continue; // vertices is already visited
            travelDFS(edgePath,v,i,visited);
        }   
    }
}

void travelBFS(int **edgePath, int v, int sv, bool *visited){
    queue<int> q;
    q.push(sv);

    while(!q.empty()){
       int front = q.front();
       q.pop();
       visited[front] = true;

       for(int i=0; i<v; i++) {
           if(i == front)
              continue;
            if(!visited[i] && edgePath[i][front])
               q.push(i);
       } 
    }
}

void DFS(int **edgePath, int v){
    //to chheck which vertices are visited
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;  //none vertices are visited
    }
    
    travelBFS(edgePath,v,0,visited);
    for(int i=0;i<v;i++){
     if(!visited[i]){
      cout<<"false"; return;
        }
    }
    cout<<"true";
    delete[] visited;
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
    
    DFS(edges,n);
    
    //free memory
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete edges;
}
