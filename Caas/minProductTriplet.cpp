/*
Find minimum product among all combinations of triplets in an array

Given an integer array, find the minimum product among all combinations of triplets in the array.

For example,

Input:  { 4, -1, 3, 5, 9 }
Output: The minimum product is -45 (-1, 5, 9)
 
Input:  { 1, 4, 10, -2, 4 }
Output: The minimum product is -80 (10, 4, -2)
 
Input:  { 3, 4, 1, 2, 5 }
Output: The minimum product is 6 (3, 1, 2)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minProduct(int arr[], int n){
    sort(arr, arr+n);
    int a = arr[0], b, c;
    if(arr[0] < 0){
        b = arr[n - 1];
        c = arr[n - 2];
    }
    else{
        b = arr[1];
        c = arr[2];
    }
    return a * b * c;
}
int main(){
    // int arr[] = {4, -1, 3, 5, 9};
    // int arr[] = {1, 4, 10, -2, 4};
    int arr[] = {3, 4, 1, 2, 5};
    int n = sizeof(arr)/sizeof(int);
    cout << minProduct(arr, n); 
    return 0;
}