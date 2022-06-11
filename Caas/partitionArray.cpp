/*

Partition an array into two subarrays with the same sum

Given an integer array, partition it into two subarrays having the same sum of elements.

For example,

Input:  {6, -4, -3, 2, 3}
 
Output: The two subarrays are {6, -4} and {-3, 2, 3} having equal sum of 2
 
Input:  {6, -5, 2, -4, 1}
 
Output: The two subarrays are {} and {6, -5, 2, -4, 1} having equal sum of 0
*/

#include<iostream>
#include<iterator>
#include<numeric>

using namespace std;

int partition(int arr[], int n){
    int sum_so_far = 0;
    int total = accumulate(arr, arr+n, 0);

    for(int i = 0; i < n; i++)
    {
        if(sum_so_far == total-sum_so_far)
            return i;
        sum_so_far += arr[i];
    }
    return -1;
}


int main(){
    int arr[] = {6, -4, -3, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    int i = partition(arr, n);
    if(i != -1){
        copy(arr, arr+i, ostream_iterator<int>(cout, " "));
        cout << endl;
        copy(arr+i, arr+n, ostream_iterator<int>(cout, " "));
    }
    else{
        cout << "The array can't be partitioned!";
    }
    return 0;
}