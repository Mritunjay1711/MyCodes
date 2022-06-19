/*
Given an array of elements and change the array in such a way that all the elements on the array are distinct. if you are replacing a value, then the replacing value should be great than the previous value and after modification sum of the elements should be as less as possible. 
Example: arr[1, 2, 3, 4, 5, 5, 5] and the result should be [1, 2, 3, 4, 5, 6, 7] 
example 2 [1, 2, 5, 7, 8, 8, 7] then the result should be [1, 2, 5, 7, 8, 9, 10] or 1, 2, 5, 7, 8, 10,

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void replaceElement(int A[], int n)
{
    map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        mp[A[i]]++;
    }
    int j = 0;
    for(auto i = mp.begin(); i != mp.end(); i++)
    {
        // cout << i->first << " " << i->second << endl;
        if(j == 0)
        {
            A[j] = i->first;
            j++;
            i->second--;
        }
        if(i->second >= 1 && i->first > A[j-1])
        {
            A[j] = i->first;
            j++;
            i->second--;
        }
        while(i->second != 0)
        {
            A[j] = A[j - 1] + 1;
            j++;
            i->second--; 
        }
    }

}

int main(){
    int arr[] = {1, 2, 3, 7, 7, 3, 8};
    int n = sizeof(arr)/sizeof(int);
    replaceElement(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}