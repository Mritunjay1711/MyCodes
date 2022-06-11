/*
Count decodings of a given sequence of digits:
Given a positive number, map its digits to the corresponding alphabet in the mapping table [(1, 'A'), (2, 'B'), … (26, 'Z')], and return the count of the total number of decodings possible. Assume that the input number can be split into valid single-digit or two-digit numbers that are present in the mapping table.

For example,

Input:  123
 
Output: 3
 
The possible decodings are [ABC, AW, LC]
 
Input:  1221
 
Output: 5
 
The possible decodings are [ABBA, ABU, AVA, LBA, LU]
*/

#include<iostream>
using namespace std;

int countDecoding(string str){
    int n = str.length();

    int arr[n+1] = {0};
    arr[0] = arr[1] = 1;

    for(int i =  2; i <= n; i++){
        if(str[i - 1] > '0')
            arr[i] = arr[i - 1];
        // cout << "running\n";
        if(str[i - 2] == '1' ||(str[i - 2] == '2' && str[i - 1] < '7'))
            arr[i] += arr[i - 2];
    }
    // for(int i = 0; i <= n; i++)
    //     cout << arr[i] << " ";
    return arr[n];
}

int main(){
    string str = "123";
    int ans = countDecoding(str);
    cout << ans << endl;
    return 0;
}