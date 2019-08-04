#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        queue<char> charStream;
        int presentChar[128]={0};
        
        for(int i=0; i<n; i++){
            char nextCharacter;
            cin >> nextCharacter;
            
            if(presentChar[nextCharacter] == 0){
                presentChar[nextCharacter]=1;
                charStream.push(nextCharacter);
            }
            else if (presentChar[nextCharacter] == 1) {
                presentChar[nextCharacter]=-1;
            }
            
            while ( !charStream.empty() && presentChar[charStream.front()] == -1)
            {
                charStream.pop();
            }
            
            if(charStream.empty()){
                cout<<"-1 ";
            }
            else{
                cout<<charStream.front()<<" ";
            }  
        }

        cout<<endl;
    }
}