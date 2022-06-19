/*
Longest Bitonic Subarray Problem

The Longest Bitonic Subarray (LBS) problem is to find a subarray of a given sequence in which the subarray’s elements are first sorted in increasing order, then in decreasing order, and the subarray is as long as possible. Strictly ascending or descending subarrays are also accepted.

For example,

Longest bitonic subarray of the sequence { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 } is { 4, 5, 9, 10, 8, 5, 3 }
 
For sequences sorted in increasing or decreasing order, the output is the same as the input sequence, i.e.,
 
[1, 2, 3, 4, 5] ——> [1, 2, 3, 4, 5]
[5, 4, 3, 2, 1] ——> [5, 4, 3, 2, 1]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> bitonicSubarrray(int arr[], int n){
    vector<int> ans;
    int incr = 1, decr = 0;
    for(int i = 0; i < n - 1 ; i++)
    {
        int j = i;
        vector<int> temp;
        while(incr){
            if(j != n && arr[j] <= arr[j+1]){
                temp.push_back(arr[j]);
            }
            else
            {
                incr = 0;
                decr = 1;
                break;
            }
            if(j < n - 1)
                j++;
            else
                break;
        }
        while(decr){
            if(arr[j] >= arr[j+1]){
                temp.push_back(arr[j]);
            }
            else{
                temp.push_back(arr[j]);
                decr = 0;
                incr = 1;
            }
            if(j < n - 1)
                j++;
            else   
                break;
        }
        // cout << ans.size() << " " << temp.size() << endl;
        if(ans.size() < temp.size()){
            ans = temp;
        }
        // cout << ans.size() << endl;
    }
    return ans;
}

int main(){
    // int arr[] = {3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4};
    // int arr[] = {1, 2, 3, 4, 5};
    // int arr[] = {5, 4, 3, 2, 1};
    int arr[] = {2, 5, 9, 3, 5, 1, 3, 4, 5, 9, 4, 3, 2 , 1};
    int n = sizeof(arr)/sizeof(int);
    vector<int> ans = bitonicSubarrray(arr, n);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}