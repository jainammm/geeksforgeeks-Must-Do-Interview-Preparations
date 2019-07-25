#include <bits/stdc++.h>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxLen(int arr[], int n);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<maxLen(a,n)<<endl;
		
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method*/
int maxLen(int arr[], int n)
{
    if (n == 1){
		return 0;
	}

	int ans = 0, n1 = 0, n0 = 0;
	for(int i=n-1; i>=0; i--){
		if(arr[i]==1)
			n1++;
		else
			n0++;
		if(n1 == n0){
			ans = n - i;
		}
	}
	if(ans == n)
		return n;
	return MAX(ans,maxLen(arr,n-1));

}