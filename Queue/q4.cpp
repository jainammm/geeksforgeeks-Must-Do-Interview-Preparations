#include<iostream>
#include<queue>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int maxIndex = 0;
        queue<int> maxEle;
        maxEle.push(arr[0]);
        
        for(int i=1; i<k; i++){
            while( !maxEle.empty() && arr[i] > maxEle.front()){
                maxEle.pop();
            }
            maxEle.push(arr[i]);
        }

        cout<<maxEle.front()<<" ";
        for(int i=k; i<n; i++){
            if(arr[i-k] == maxEle.front()){
                maxEle.pop();
            }
            while( !maxEle.empty() && arr[i] > maxEle.front()){
                maxEle.pop();
            }

            maxEle.push(arr[i]);
            cout<<maxEle.front()<<" ";
        }

        cout<<endl;
    }
}