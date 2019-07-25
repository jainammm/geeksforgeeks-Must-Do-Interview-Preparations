#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long int> arr;
        long long int sum=0, left = 0, right = 0;
        for(int i=0; i<n; i++){
            long int temp;
            cin>>temp;
            arr.push_back(temp);
            sum+=temp;
        }

        bool equilibriumExists = false;
        
        for(int i=0; i<n; i++){
            right = sum - arr[i] - left;
            if(left == right){
                cout<<i+1<<endl;
                equilibriumExists = true;
                break;
            }
            if(left > right){
                break;
            }
            left += arr[i];
        }
        if(equilibriumExists == false){
            cout<< -1 << endl;
        }
    }
    
}
