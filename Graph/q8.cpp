#include <iostream>
#include <vector>
using namespace std;

// bool isCyclic(int V, vector<int> g[]){

// }

bool isCyclicComponent(int v,vector<int> adj[],bool vis[], bool recStack[]){
    
    if(vis[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        vis[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        vector<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !vis[*i] && isCyclicComponent(*i, adj, vis, recStack) ) 
                return true; 
            else if (recStack[*i]) 
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


int main() {
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        vector<int> graph[26]; 
        for(int i=0; i<n; i++){
            string s;
            cin >> s;

            int firstChar = s[0]-'a', lastChar = s[s.size()]-'a';
            //cout << firstChar << endl;
            graph[firstChar].push_back(lastChar);
        }

        if(isCyclic(26, graph)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
	//code
	return 0;
}