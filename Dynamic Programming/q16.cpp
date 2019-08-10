#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;
        
        string x,y;
        cin >> x;
        cin >> y;
        int arr[n][m] = {0};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = 0;
            }
        }

        for(int j = 0; j<m; j++){
            if(x[0] == y[j]){
                arr[0][j]++;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(x[i] == y[j]){
                    if(j==0){
                        arr[i][j]=1;
                    }
                    else{
                        arr[i][j] = arr[i-1][j-1] + 1;
                    }
                }
            }
        }

        int max = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] > max){
                    max = arr[i][j];
                }
            }
        }
        cout<<max<<endl;
    }
	return 0;
}