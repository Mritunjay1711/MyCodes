#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool pythagoreanTriplet(int arr[], int n){
    unordered_set<int> st;
    if(n <= 2)
        return false;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
        for(int j = i + 1; j < n; j++){
            int p = sqrt((arr[i] * arr[i]) + (arr[j] * arr[j]));
            // int q = arr[i] > arr[j] ? arr[i] : arr[j];
            if(st.find(p) != st.end() && p != 0 && p != 1){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[] = {1, 2, 3, 4, 8, 9, 5};
    int n = sizeof(arr)/sizeof(int);
    cout << pythagoreanTriplet(arr, n);
    return 0;
}