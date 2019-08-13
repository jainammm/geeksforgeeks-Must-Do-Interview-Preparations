#include <bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
/*you are required to complete this method*/
/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

void removeOnes(vector<int> A[], int N, int M, int i, int j){
    A[i][j]=0;
    if(i>0 && j>0){
        if(A[i-1][j-1]==1){
            removeOnes(A, N, M, i-1, j-1);
        }
    }
    if(i>0 ){
        if(A[i-1][j]==1){
            removeOnes(A, N, M, i-1, j);
        }
    }
    if( i>0 && j < M-1){
        if(A[i-1][j+1]==1){
            removeOnes(A, N, M, i-1, j+1);
        }
    }
    if( j < M-1 ){
        if(A[i][j+1]==1){
            removeOnes(A, N, M, i, j+1);
        }
    }
    if(i < N-1 && j < M-1){
        if(A[i+1][j+1]==1){
            removeOnes(A, N, M, i+1, j+1);
        }
    }
    if( i < N-1 ){
        if(A[i+1][j]==1){
            removeOnes(A, N, M, i+1, j);
        }
    }
    if( i < N-1 && j > 0){
        if(A[i+1][j-1]==1){
            removeOnes(A, N, M, i+1, j-1);
        }
    }
    if( j > 0 ){
        if(A[i][j-1]==1){
            removeOnes(A, N, M, i, j-1);
        }
    }
}

int findIslands(vector<int> A[], int N, int M)
{
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j] == 1){
                removeOnes(A, N, M, i, j);
                ans++;
            }
        }
    }
    
    return ans;
    
}


//Position this line where user code will be pasted.
int main() {
    
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		vector<int> A[N];
		for(int i=0;i<N;i++){
		    vector<int> temp(M);
		    A[i] = temp;
		    for(int j=0;j<M;j++){
		        cin>>A[i][j];
		    }
		}
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}

