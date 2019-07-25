#include <iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1.length() != s2.length()){
            cout<<"NO"<<endl;
            continue;
        }
        int arr1[128]={0}, arr2[128]={0};
        for(int i=0; i<s1.length(); i++){
            arr1[s1[i]]++;
            arr2[s2[i]]++;
        }

        bool check = true;
        for(int i=50; i<128; i++){
            if(arr1[i] != arr2[i]){
                check = false;
                break;
            }
        }

        if(check)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    
}