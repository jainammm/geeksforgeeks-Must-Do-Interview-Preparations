#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
/*  Function to check if elements returned by user 
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}
// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
       
    }
}

/*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/

void topologicalSortUtil(int v, vector<int> adj[], bool visited[], 
                                stack<int>& Stack) 
{ 
    visited[v] = true; 
  
    vector<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, adj, visited, Stack); 
  
    Stack.push(v); 
} 

int* topoSort(int V, vector<int> adj[])
{
    stack<int> Stack; 
  
    bool visited[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, adj, visited, Stack); 

    int *ans=new int[V], n=0;
  
    while (Stack.empty() == false) { 
        ans[Stack.top()] = n;
        n++; 
        Stack.pop(); 
    }

    return ans;
}
