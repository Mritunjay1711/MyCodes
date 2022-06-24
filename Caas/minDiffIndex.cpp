/*
Find the minimum difference between the index of two given elements present in an array:
Given an integer array nums and two integers x and y present in it, find the minimum absolute difference between indices of x and y in a single traversal of the array.

For example,

Input:
 
arr = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 }
x = 3, y = 2
 
Output: 2
 
Explanation: Element 3 is present at index 1 and 7, and element 2 is present at index 5. Their minimum absolute difference is min(abs(1-5), abs(7-5)) = 2
 
Input:
 
arr = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 }
x = 2, y = 5
 
Output: 3
 
Explanation: Element 2 is present at index 5, and element 5 is present at index 2 and 9. Their minimum absolute difference is min(abs(5-2), abs(5-9)) = 3
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min(int a, int b){
    return a < b ? a : b;
}

int mod(int a){
    return a < 0 ? -1*a : a;
}

int findDistance(int arr[], int n, int x, int y){
    int a = -1, b = -1, ans = 676575;
    for(int i = 0; i < n; i++){
        if(arr[i] == x)
            a = i;
        if(arr[i] == y)
            b = i;
        if(a != -1 && b != -1){
            ans = min(ans, mod(a - b));
        }
    }
    return ans;
}

int main(){
    int arr[] = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 };
    int x = 3, y = 2;
    int n = sizeof(arr)/sizeof(int);
    cout << findDistance(arr, n, x, y);
    return 0;
}