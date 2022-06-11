#include<iostream>
using namespace std;

int maxSubarray(int arr[], int n)
{
    int max_so_far = -1234353, max_ending_here = 0;
    for(int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = maxSubarray(arr, n);
    cout << ans;
    return 0;
}