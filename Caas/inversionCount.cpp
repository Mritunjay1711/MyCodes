/*
Inversion count of an array:
Given an array, find the total number of inversions of it. If (i < j) and (A[i] > A[j]), then pair (i, j) is called an inversion of an array A. We need to count all such pairs in the array.

For example,

Input:  A[] = [1, 9, 6, 4, 5]
 
Output: The inversion count is 5
 
There are 5 inversions in the array: (9, 6), (9, 4), (9, 5), (6, 4), (6, 5)
*/

#include<iostream>

using namespace std;

int merge(int A[], int B[], int low, int mid, int high){
    // cout << "Calling*" << endl;
    int i = low, j = mid+1, k = low;
    int inversionCount = 0;
    while(i <= mid && j <= high){
        if(A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else{
            B[k] = A[j];
            k++;
            j++;
            inversionCount += (mid - i + 1); //Counting the number of inversions
        }
    }
    while(i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }
    while(j <= high){
        B[k] = A[j];
        k++;
        j++;
    }
    // cout << "Returning*" << endl;
    return inversionCount;
}

int mergeSort(int A[], int B[], int low, int high){
    // cout << "Calling***" << endl;
    if(low>=high)
        return 0;
    int mid = (low + high)/2;
    int inversionCount = 0;
    inversionCount += mergeSort(A, B, low, mid);
    inversionCount += mergeSort(A, B, mid+1, high);

    inversionCount += merge(A, B, low, mid, high);
    // cout << "Returning***" << endl;
    return inversionCount;
}

int main(){
    int A[] = {1, 9, 6, 4, 5};
    int size = sizeof(A)/sizeof(int);
    int B[size];
    int low = 0, high = size - 1, ans;
    ans = mergeSort(A, B, low, high);
    cout << "Number of inversion: " << ans << endl;
    return 0;
}