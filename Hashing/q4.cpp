#include <iostream>

using namespace std;

bool findCommon(long long int ar1[], long long int ar2[], long long int ar3[], int n1, int n2, int n3) 
{ 
    // Initialize starting indexes for ar1[], ar2[] and ar3[] 
    int i = 0, j = 0, k = 0; 
    int returnAns=false;
  
    // Iterate through three arrays while all arrays have elements 
    while (i < n1 && j < n2 && k < n3) 
    { 
         // If x = y and y = z, print any of them and move ahead  
         // in all arrays 
         if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) 
        {
            cout << ar1[i] << " ";   i++; j++; k++;
            returnAns = true;

        } 
  
         // x < y 
         else if (ar1[i] < ar2[j]) 
             i++; 
  
         // y < z 
         else if (ar2[j] < ar3[k]) 
             j++; 
  
         // We reach here when x > y and z < y, i.e., z is smallest 
         else
             k++; 
    } 
    return returnAns;
} 

int main(){
    int t;
    cin >> t;

    while(t--){
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;

        long long int arr1[n1], arr2[n2], arr3[n3];

        for(int i=0; i<n1; i++){
            cin >> arr1[i];
        }

        for(int i=0; i<n2; i++){
            cin >> arr2[i];
        }

        for(int i=0; i<n3; i++){
            cin >> arr3[i];
        }

        if(!findCommon(arr1, arr2, arr3, n1, n2, n3)){
            cout <<"-1 ";
        }
        cout << endl;
    }
}