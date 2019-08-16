#include <iostream>
#include <queue>
using namespace std;

const int MAX_CHAR = 26; 
  
struct Key 
{ 
    int freq; 
    char ch; 
  
    bool operator<(const Key &k) const
    { 
        return freq < k.freq; 
    } 
}; 
  
void rearrangeString(string str) 
{ 
    int n = str.length(); 
  
    int count[MAX_CHAR] = {0}; 
    for (int i = 0 ; i < n ; i++) 
        count[str[i]-'a']++; 
  
    priority_queue< Key > pq; 
    for (char c = 'a' ; c <= 'z' ; c++) 
        if (count[c-'a']){ 
			Key x={count[c-'a'], c};
            pq.push(x); 
		}
  
    str = "" ; 
  
    Key prev = {-1, '#'} ; 
  
    while (!pq.empty()) 
    { 
        Key k = pq.top(); 
        pq.pop(); 
        str = str + k.ch; 
  
        if (prev.freq > 0) 
            pq.push(prev); 
  
        (k.freq)--; 
        prev = k; 
    } 
  
    if (n != str.length()) 
        cout << 0 << endl;
  
    else 
        cout << 1 << endl; 
} 
  
int main() 
{ 
	int t;
	cin >> t;
	while(t--){
		string str ;
		cin >> str; 
		rearrangeString(str); 
	}
    return 0; 
} 