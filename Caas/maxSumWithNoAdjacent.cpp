/*
Find the maximum sum of a subsequence with no adjacent elements

Given an integer array, find the maximum sum of subsequence where the subsequence contains no element at adjacent positions.

Please note that the problem specifically targets subsequences that need not be contiguous, i.e., subsequences are not required to occupy consecutive positions within the original sequences.

For example,

Input:  { 1, 2, 9, 4, 5, 0, 4, 11, 6 }
Output: The maximum sum is 26
 
The maximum sum is formed by subsequence { 1, 9, 5, 11 }
*/
#include<iostream>
#include<vector>
using namespace std;

int findMaxSumSubsequence(vector<int> const &num, int i, int n, int prev)
{
    if(i == n)
        return 0;

    int exclu = findMaxSumSubsequence(num, i + 1, n, prev);// recur by excluding the current element

    int inclu = 0;

    //Including current element when it is not adjacent to prev element
    if(prev + 1 != i){
        inclu = findMaxSumSubsequence(num, i + 1, n , i) + num[i];
    }
    return max(inclu, exclu);
}

int main(){
    vector<int> num = {1, 2, 9, 4, 5, 0, 4, 11, 6};
    int n = num.size();
    cout << findMaxSumSubsequence(num, 0, n, -1943);
    return 0;
}