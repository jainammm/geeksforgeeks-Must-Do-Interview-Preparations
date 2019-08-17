#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int k, n;
	    cin >> k >> n;
	    
	    vector<int> arr(n);
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    
	    priority_queue<int, vector<int>, greater<int> > minHeap;
	    
	    for(int i=0; i<k-1; i++){
	        minHeap.push(arr[i]);
	        cout << -1 << " ";
	    }
	    
	    minHeap.push(arr[k-1]);
	    cout << minHeap.top() << " ";
	    
	    for(int i=k; i<n; i++){
	        if(arr[i] > minHeap.top()){
	            minHeap.pop();
	            minHeap.push(arr[i]);
	        }
	        cout << minHeap.top() << " ";
	    }
	    
	    cout << endl;
	}
	//code
	return 0;
}