#include<bits/stdc++.h> 
#include <iostream>
#include<vector>
#include<stack>

using namespace std;

void leftrotate(string &s, int d) 
{ 
    reverse(s.begin(), s.begin()+d); 
    reverse(s.begin()+d, s.end()); 
    reverse(s.begin(), s.end()); 
} 
  
// In-place rotates s towards right by d 
void rightrotate(string &s, int d) 
{ 
   leftrotate(s, s.length()-d); 
} 
  

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1.length() != s2.length()){
            cout<<"0"<<endl;
            continue;
        }
        leftrotate( s2 , 2);
        if(s1 == s2){
            cout<<1<<endl;
            continue;
        }
        rightrotate( s2 , 4);
        if(s1 == s2){
            cout<<1<<endl;
            continue;
        }
        cout<<0<<endl;
    }
    
}