#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int x = n;
        int arr[n+1] = {0};
        while (--n)
        {
            int temp;
            cin>>temp;
            arr[temp]++;
        }
        for(int i=1; i<x+1; i++){
            if(arr[i] == 0){
                cout<<i<<endl;
                break;
            }
        }
    }
}