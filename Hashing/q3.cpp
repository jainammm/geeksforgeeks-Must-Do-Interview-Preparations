#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[],int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<maxLen(A,N)<<endl;
    }
}


/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function*/
int maxLen(int A[],int n)
{
    unordered_map<int, int> presum; 
  
    int sum = 0; 
    int max_len = 0; 
  
    for (int i = 0; i < n; i++) { 
        sum += A[i]; 
  
        if (A[i] == 0 && max_len == 0) 
            max_len = 1; 
        if (sum == 0) 
            max_len = i + 1; 
  
        if (presum.find(sum) != presum.end()) { 
            max_len = max(max_len, i - presum[sum]); 
        } 
        else { 
            presum[sum] = i; 
        } 
    } 
  
    return max_len; 
  //Your code here
}