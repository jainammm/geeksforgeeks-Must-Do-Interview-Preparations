#include <iostream>
using namespace std;

int nCm(int n, int m){
    if(m==0)
        return 1;

    return n * nCm(n-1, m-1) / m ;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        cout << nCm(n+m-2, n-1) << endl;
    }
	//code
	return 0;
}