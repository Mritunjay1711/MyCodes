/*
Find a pair with a minimum absolute sum in an array
Given a sorted integer array, find a pair in it having an absolute minimum sum.
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the element: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = 0, high = n-1, min = 239483, sum, i , j;
    while(low < high)
    {
        sum = abs(arr[low] + arr[high]);
        if(min > sum)
        {
            min = sum;
            i = low;
            j = high;
        }
            
        if(min == 0)
            break;
        (arr[low] + arr[high]) > 0 ? high-- : low++;
    }

    cout << arr[i] << " " << arr[j] << endl;
    return 0;
}