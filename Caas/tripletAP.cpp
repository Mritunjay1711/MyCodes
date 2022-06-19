/*
Print all triplets that form an arithmetic progression

Given a sorted array of distinct positive integers, print all triplets that forms an arithmetic progression with an integral common difference.

An arithmetic progression is a sequence of numbers such that the difference between the consecutive terms is constant. For instance, sequence 5, 7, 9, 11, 13, 15, … is an arithmetic progression with a common difference of 2
 
For example,

Input:  A[] = { 5, 8, 9, 11, 12, 15 }
 
Output:
5 8 11
9 12 15
 
Input:  A[] = { 1, 3, 5, 6, 8, 9, 15 }
 
Output:
1 3 5
1 5 9
3 6 9
1 8 15
3 9 15
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void tripletAp(int arr[], int n){
    unordered_set<int> st;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int diff = arr[j] - arr[i];
            if(st.find(arr[i] - diff) != st.end()){
                cout << arr[i] - diff << " " << arr[i] << " " << arr[j] << endl;
            }
        }
        st.insert(arr[i]);
    }
}

int main(){
    // int arr[] = {5, 8, 9, 11, 12, 15};
    int arr[] = {1, 3, 5, 6, 8, 9, 15} ;
    int n = sizeof(arr)/sizeof(int);
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         for(int k = j + 1; k < n; k++){
    //             if(arr[k] - arr[j] == arr[j] - arr[i]){
    //                 cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
    //             }
    //         }
    //     }
    // }

    tripletAp(arr, n);
    return 0;
}
