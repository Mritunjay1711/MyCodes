/*
Find duplicates within a range k in an array

Given an array and a positive number k, check whether the array contains any duplicate elements within the range k. If k is more than the array’s size, the solution should check for duplicates in the complete array.

For example,

Input:
 
nums[] = { 5, 6, 8, 2, 4, 6, 9 }
k = 4
 
Output: Duplicates found
 
(element 6 repeats at distance 4 which is <= k)
 
Input:
 
nums[] = { 5, 6, 8, 2, 4, 6, 9 }
k = 2
 
Output: No duplicates were found
 
(element 6 repeats at distance 4 which is > k)
 
Input:
 
nums[] = { 1, 2, 3, 2, 1 }
k = 7
 
Output: Duplicates found
 
(element 1 and 2 repeats at distance 4 and 2, respectively which are both <= k)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool findDuplicate(vector<int> nums, int k){
    int n = nums.size();
    map<int, int> mp;
    for(int i = 0; i < n; i++){
       
       if(mp.find(nums[i]) != mp.end()){
            if(i - mp[nums[i]] <= k){
                return true;
            }
       }
       mp[nums[i]] = i;
    }
    return false;
}

int main(){
    vector<int> arr = { 5, 6, 8, 2, 4, 6, 9 };
    int k = 2;
    cout << findDuplicate(arr, k) << endl;
    return 0;
}