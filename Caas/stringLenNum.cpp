/*
Given a string that (may) be appended with a number at last. You need to find whether the length of string excluding that number is equal to that number. For example for “helloworld10”, answer is True as helloworld consist of 10 letters. Length of String is less than 10, 000.

Examples : 

Input:  str = "hello5"
Output:  Yes
Explanation : As hello is of 5 length and at last number is also 5.

Input:  str = "kiituniversity15"
Output:  No
Explanation: As kiituniversity is of 14 length and at last number is 15
*/

#include<iostream>
using namespace std;

bool isEqual(string str){
    int n = str.length();
    int i = n - 1, num = 0, count = 0, x = 1;
    while(str[i] >= '0' && str[i] <= '9')
    {
        int temp = str[i] - '0';
        num = temp * x + num;
        i--;
        count++;
        x*=10;
    }
    if((n - count) == num)
        return true;
    return false;
}

int main(){
    string str = "kiituniversity14";
    cout << isEqual(str) << endl;
    return 0;
}
