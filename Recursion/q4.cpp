#include <iostream>
using namespace std;

void maxNum(int dp[]){
    for(int i=0; i<6; i++){
        dp[i] = i+1;
    }

    for(int i=7; i<=75; i++){
        dp[i-1] = 0;
        for(int b=i-3; b >=1; b--){
            int curr = (i-b-1) * dp[b-1];
            if(curr > dp[i-1]){
                dp[i-1] = curr;
            } 
        }
    }
}

int main() {
	//code

    int *dp = new int[75];

    maxNum(dp);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n-1] << endl;
    }

	return 0;
}