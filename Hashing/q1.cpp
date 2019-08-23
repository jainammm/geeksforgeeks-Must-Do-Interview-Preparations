#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        unordered_map<int, int> mp;
        vector<int> arr1(n), arr2(m);
        for(int i=0; i<n; i++){
            cin >> arr1[i];
            mp[arr1[i]]++;
        }       
        for(int i=0; i<m; i++){
            cin >> arr2[i];
        }

        vector<int> ans;
        for(int i=0; i<m; i++){
            while(mp[arr2[i]]){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        int currSize = ans.size();

        for(int i=0; i<n; i++){
            while(mp[arr1[i]]){
                mp[arr1[i]]--;
                ans.push_back(arr1[i]);
            }
        }

        sort(ans.begin()+currSize, ans.end());
        for(int i=0; i<ans.size() ; i++){
            cout << ans[i] << " ";
        }
        cout << endl;

    }
    
	//code
	return 0;
}