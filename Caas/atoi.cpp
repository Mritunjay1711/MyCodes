/*
Implement atoi to convert a string to an integer.

Example :

Input : "9 2704" Output : 9 

Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

Questions:

Q1. Does string contain whitespace characters before the number?
A. Yes

Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it.

Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0.

Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise.
*/


#include<iostream>
#define INT_MAX 2147483647
using namespace std;

bool isLetter(char ch){
    if((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

bool isNumber(char ch){
    if(ch >= '0' && ch <= '9')
        return true;
    return false;
}

int convertInt(string s){
    int n = s.length(), count = 0;
    bool num = false;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(count == 0 && !isLetter(s[i]) && !isNumber(s[i]) && s[i] != ' ')
            return 0;

        if(num && !isNumber(s[i]))
            break;

        if(isNumber(s[i]))
            num = true;

        if(num){
            count++;
            int temp = s[i] - '0';
            ans *= 10;
            ans += temp;
        }
        
        if(ans > INT_MAX)
            return INT_MAX;
        
    }
    
    return (int)ans; 
}

int main(){
    string str = "ghfghgh 98974323ghgfhgfh 434343";
    // cout << isNumber('9') << endl;
    cout << convertInt(str) << endl;
    return 0;
}