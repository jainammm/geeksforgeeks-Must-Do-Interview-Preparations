#include <iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        
        stack<int> ans;
        if(ans.empty()){
            ans.push(arr.back());
        }
        for(int i=n-2; i>=0; i--){
            if(ans.top() <= arr[i]){
                ans.push(arr[i]);
            }
        }
        while( !ans.empty() ){
            cout<<ans.top()<<" ";
            ans.pop();
        }
        cout<<endl;
    }
    
}