#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        string pattern;
        cin>>pattern;
        stack<char> parenthesisStack;
        bool check = true;
        for(int i=0; i<pattern.length(); i++){
            if(pattern[i] == '[' || pattern[i] == '{' || pattern[i] == '('){
                parenthesisStack.push(pattern[i]);
            }
            else if (parenthesisStack.empty())
            {
                cout<< "not balanced" << endl;
                check = false;
                break;
            }
            else if (pattern[i] == ']')
            {
                if (parenthesisStack.top() != '['){
                    cout<< "not balanced" << endl;
                    check = false;
                    break;
                }
                parenthesisStack.pop();
            }
            else if (pattern[i] == '}')
            {
                if (parenthesisStack.top() != '{'){
                    cout<< "not balanced" << endl;
                    check = false;
                    break;
                }
                parenthesisStack.pop();
            }
            else if (pattern[i] == ')')
            {
                if (parenthesisStack.top() != '('){
                    cout<< "not balanced" << endl;
                    check = false;
                    break;
                }
                parenthesisStack.pop();
            }  
        }
        if (check){
            if(parenthesisStack.empty())
                cout<<"balanced"<<endl;
            else
            {
                cout<<"not balanced"<<endl;
            }
            
        }
    }

	return 0;
}