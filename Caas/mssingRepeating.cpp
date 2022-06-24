/*
Find the missing number and duplicate elements in an array

Given an integer array of size n, with all its elements between 1 and n and one element occurring twice and one element missing. Find the missing number and the duplicate element in linear time and without using any extra memory.

For example,

Input:  arr[] = [4, 3, 6, 5, 2, 4]
 
Output: The duplicate and missing elements are 4 and 1, respectively
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printMissRepeat(int arr[], int n){
    //using element as index make values at index negative

    for(int i = 0; i < n; i++){
        if(arr[abs(arr[i]) - 1] > 0){
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        else
        {
            cout << abs(arr[i]) << " is repeating element\n";
        }
    }

    for(int i = 0; i < n; i++){
        if(arr[i] > 0)
            cout << (i + 1) << " is missing element\n";
    }
}

int main(){
    int arr[] = {4, 2, 3, 6, 5, 4};
    int n = sizeof(arr)/sizeof(n);
    printMissRepeat(arr, n);
    return 0;
}