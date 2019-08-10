#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct sumOfPartitions{
    int sum1 = 0,sum2 = 0;
};

sumOfPartitions* minSumPartition(int arr[], int n){
    
    if(n == 1){
        sumOfPartitions* minSum = new sumOfPartitions();
        minSum->sum1 = arr[0];
        minSum->sum2 = 0;
        return minSum;
    }
    else{
        sumOfPartitions* minSum = minSumPartition(arr+1, n-1);
    }
    
}

int main() {
	int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        sort(arr, arr+n);
        
        sumOfPartitions* minSum = minSumPartition(arr, n);

    }
	return 0;
}