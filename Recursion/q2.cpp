#include <iostream>
using namespace std;

void removeColor(int *A[], int N, int M, int i, int j, int k, int alreadyPresent){
    A[i][j]=k;
    
    if(i>0 ){
        if(A[i-1][j]==alreadyPresent){
            removeColor(A, N, M, i-1, j, k, alreadyPresent);
        }
    }
    
    if( j < M-1 ){
        if(A[i][j+1]==alreadyPresent){
            removeColor(A, N, M, i, j+1, k, alreadyPresent);
        }
    }
    
    if( i < N-1 ){
        if(A[i+1][j]==alreadyPresent){
            removeColor(A, N, M, i+1, j, k, alreadyPresent);
        }
    }
    
    if( j > 0 ){
        if(A[i][j-1]==alreadyPresent){
            removeColor(A, N, M, i, j-1, k, alreadyPresent);
        }
    }
}

int main() {
    int t;
    cin >>t;

    while (t--){
        int n, m;
        cin >> n >> m;

        int *arr[n];
        for(int i=0; i<n; i++){
            arr[i] = new int[m];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];
            }
        }

        int x, y, k;
        cin >> x >> y >> k;
        removeColor(arr, n, m, x, y, k, arr[x][y]);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
	//code
	return 0;
}