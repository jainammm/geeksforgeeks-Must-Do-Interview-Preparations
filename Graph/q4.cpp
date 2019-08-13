#include <bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool isCyclicComponent(int v,vector<int> adj[],bool vis[], bool recStack[]){
    
    if(vis[v] == false)
        vis[v] = true; 
    
    recStack[v] = true; 

    for(int i = 0; i != adj[v].size(); i++) 
    { 
        if ( !recStack[adj[v][i]]  ){
            if(isCyclicComponent(adj[v][i], adj, vis, recStack)){
                //cout<<"from here";
                return true;
            }
        } 
        else {
            //cout<<"no, from here";
            return true; 
        }
    }

    recStack[v] = false;  

    return false; 
}

bool isCyclic(int V, vector<int> adj[])
{
    bool vis[V], recStack[V];
    for(int i=0; i<V; i++){
        vis[i]=false;
        recStack[i]=false;
    }

    for(int i = 0; i < V; i++) 
        if(!vis[i])
            if (isCyclicComponent(i, adj, vis, recStack)) 
                return true; 
    return false;

}

//Position this line where user code will be pasted.
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}

