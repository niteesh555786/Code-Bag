#include<bits/stdc++.h>
using namespace std;

class Graph{  
public:  
    int V;
    list<int> *adj;
    int allVertUtil(int src,int dest,bool visited[],int &pathCount);

    Graph(int v);
    void addEdge(int src,int dest);
    int allVert(int src,int dest);
};

Graph::Graph(int v){
    this->V=v;
    adj=new list<int>[v];
}

void Graph::addEdge(int src,int dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

int Graph::allVertUtil(int src,int dest,bool visited[],int &pathCount){
    visited[src]=true;

    if(src==dest){
        pathCount++;
    }
    else{
        list<int>::iterator i;
        for(i=adj[src].begin();i!=adj[src].end();i++){
            if(!visited[*i])
                allVertUtil(*i,dest,visited,pathCount);
        }
    }

    visited[src]=false;
    return pathCount; 
}

int Graph::allVert(int src,int dest){
    bool  *visited=new bool[V];

    for(int i=0;i<V;i++)
        visited[i]=false;
    int pathCount=0;
    
    return allVertUtil(src,dest,visited,pathCount); 
}

int main(){
    int t;
    cin>>t;
    int vert,edge;

    while(t--){
        cin>>vert>>edge;
        Graph g(vert);
        int u,v;
        for(int i=0;i<edge;i++){
            cin>>u>>v;
            g.addEdge(u-1,v-1);
        }

        int maxPath=0;
        for(int i=1;i<vert;i++){
            maxPath=max(maxPath,g.allVert(0,i));
        }

        cout<<maxPath<<endl;
    }

    return 0;
}
