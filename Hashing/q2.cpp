#include <iostream>
#include<vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>

using namespace std;

bool sortingExpression(pair<int, int> p1, pair<int, int> p2){
	if(p1.second > p2.second){
		return true;
	}
	if(p1.second == p2.second){
		return p1.first < p2.first;
	}
	return false;
}

int main() {
    int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> arr(n);
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		unordered_map<int,int> mp;
		for(int i=0; i<n; i++){
			mp[arr[i]]++;
		}

		vector< pair<int, int > > freqArr;
		for(unordered_map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++){
			freqArr.push_back(make_pair(itr->first, itr->second));
		}

		sort(freqArr.begin(), freqArr.end(), sortingExpression);
		for(int i=0; i<freqArr.size(); i++){
			for(int j=0; j<freqArr[i].second; j++){
				cout << freqArr[i].first << " ";
			}
		}

		cout << endl;
	}
	//code
	return 0;
}