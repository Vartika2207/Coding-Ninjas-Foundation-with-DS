#include <iostream>
using namespace std;

int helper(int **edges, int n, int noOfEdges){
    if(n==0 || noOfEdges<3) return 0;
    
    int count=0; //count of cycles
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(edges[i][j]){
                for(int k=0;k<n;k++){
                    if(k==j || k==i) continue;
                    if(edges[j][k] && edges[i][k]) count++;
                }
            }
        }
    }
    return count/6;
}

//little better
int helperBetter(int **edges, int n, int noOfEdges){
    if(n==0 || noOfEdges<3) return 0;
    
    int count=0; //count of cycles
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(edges[i][j]){
                for(int k=j+1;k<n;k++){
                    if(edges[j][k] && edges[i][k]) count++;
                }
            }
        }
    }
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
    
    //getting 3 cycle
    cout<<helperBetter(edges,n,noOfEdges);
    
    //free memory
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete edges;
}





