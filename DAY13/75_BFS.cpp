#include<bits/stdc++.h>
using namespace std;
void BFS(int** edges, int v, int sv, bool* visited){
    queue<int> rem_vertex;
    rem_vertex.push(sv);
    visited[sv] = true;
    while(!rem_vertex.empty()){
        int c = rem_vertex.front();
        rem_vertex.pop();
        cout<<c<<endl;
        for(int i=0; i<v; i++){
            if(i==c)
            continue;
        
            if(edges[c][i] == 1 && !visited[i]){
            rem_vertex.push(i);
            visited[i] = true;
            }
        }
    
    }
}
int main(){
    int v, e;
    cin>>v>>e;
    
    int ** edges = new int*[v];
    for(int i=0; i<v; i++){
        edges[i] = new int[v];
        for(int j=0; j<v; j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0; i<e; i++){
        int sv, ev;
        cin>>sv>>ev;
        edges[sv][ev]=1;
        edges[ev][sv]=1;
    }
    bool* visited = new bool[v];
    for(int i=0; i<v; i++)
     visited[i] = false;
     BFS(edges, v, 0, visited);
     delete [] visited;
     for(int i=0; i<v; i++)
     delete[] edges[i];
     delete[] edges;
     return 0;
    
}
