

#include <bits/stdc++.h>
using namespace std;

//----------BFS-----------
vector<int> connectedPath(int **edges, int n, int s, bool *visited){
    vector<int>smallOutput;
    queue<int>pv;
    pv.push(s);
    while(!pv.empty()){
        int front=pv.front();
        pv.pop();
        visited[front]=true;
        smallOutput.push_back(front);
        for(int i=0;i<n;i++){
            if(i==front) continue; //self loop
            if(edges[front][i] && !visited[i]){
                pv.push(i);
                visited[i]=true;
            }
        }
    }
    return smallOutput;
}


vector<vector<int>>connected(int **edges, int n){
    vector<vector<int>>output;
    bool *visited=new bool[n]();
    for(int i=0;i<n;i++){
        vector<int>smallOutput;
        if(!visited[i]){
           smallOutput= connectedPath(edges,n,i,visited);
        }
        output.push_back(smallOutput);
    }
    return output;
}

// --------below is DFS---------------------
void connectedPathDFS(int **edges, int n, int sv, bool *visited, vector<int> &smallOutput) {
    visited[sv] = true;
    smallOutput.push_back(sv);

    for(int i=0; i<n; i++) {
        if(i != sv && !visited[i] && edges[i][sv])
           connectedPathDFS(edges, n, i, visited, smallOutput);
    }
}

vector<vector<int>>connectedDFS(int **edges, int n){
    vector<vector<int>>output;
    bool *visited=new bool[n]();
    for(int i=0;i<n;i++){
        vector<int>smallOutput;
        if(!visited[i]){
            connectedPathDFS(edges,n,i,visited, smallOutput);
        }
        output.push_back(smallOutput);
    }
    return output;
}



// -------main-------------
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
    
    //getting all connected graph
    vector<vector<int>>output=connectedDFS(edges,n);
    //printing
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[i].size();j++){
            sort(output[i].begin(),output[i].end());
            cout<<output[i][j]<<" ";
        }
        cout << endl;
    }
    
    //free memory
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete edges;
}





