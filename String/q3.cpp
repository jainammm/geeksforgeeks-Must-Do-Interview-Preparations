#include <iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    int t;
    cin >> t;
    string str;
    getline(cin, str);
    while (t--)
    {
        string s;
        getline (cin, s); 
        int arr[256]={0};
        for(int i=0; i<s.length(); i++){
            if(arr[s[i]]==0){
                cout<<s[i];
                arr[s[i]]=1;
            }
        }
        
        cout<<endl;
        
    }
}
