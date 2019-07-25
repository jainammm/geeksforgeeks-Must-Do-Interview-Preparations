#include <iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin>>s;
        stack<char> st;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] == '.'){
                while ( !st.empty() )
                {
                    cout<<st.top();
                    st.pop();
                }
                cout<<".";
            }
            else{
                st.push(s[i]);
            }
        }
        while ( !st.empty() )
        {
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
        
    }
}
