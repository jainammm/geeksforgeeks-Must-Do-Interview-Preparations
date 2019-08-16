#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void check(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > &minHeap){

    //cout << "came here" << maxHeap.size() << " " << minHeap.size()<< endl;

    int maxMinusMin = maxHeap.size() - minHeap.size() ;
    int minMinusMax = minHeap.size() - maxHeap.size() ;

    //cout << maxMinusMin << " ewf " << minMinusMax << endl;
    
    if( maxMinusMin >= 2){
        //cout << "going to min"<<endl;
        minHeap.push( maxHeap.top() );
        maxHeap.pop();
    }
    else if( minMinusMax >= 2){
        //cout << "going to max"<<endl;
        maxHeap.push( minHeap.top() );
        minHeap.pop();
    }

    //cout << "came here" << maxHeap.size() << " " << minHeap.size()<< endl;

}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    cout<< arr[0] << endl;
    maxHeap.push(arr[0]);

    bool addedEle = false;

    for(int i=1; i<n; i++){
        if(!maxHeap.empty()){
            if(arr[i] < maxHeap.top()){
                maxHeap.push(arr[i]);
                //cout << "going to max *****"<<endl;
                addedEle = true;
            }
        }
        
        if(addedEle == false){
            minHeap.push(arr[i]);
            //cout << "going to min *****"<<endl;
        }

        check(maxHeap, minHeap);

        //cout << " here" << maxHeap.size() << " " << minHeap.size()<< endl;

        if(i%2 == 0){
            if(maxHeap.size() > minHeap.size()){
                cout << maxHeap.top() << endl;
            }
            else{
                cout << minHeap.top() << endl;
            }
        }
        else{
            cout<< (maxHeap.top() + minHeap.top()) / 2 << endl;
        }
        //cout << "camedsgf here" << maxHeap.size() << " " << minHeap.size()<< endl;

        addedEle = false;

    }

	//code
	return 0;
}