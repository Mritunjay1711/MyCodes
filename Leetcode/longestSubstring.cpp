/*
Given a string s, find the length of the longest substring without repeating characters.

*Slinding Window*
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int ans = 0, a = 0, b = 0, n = s.length();
        
        
        if(n == 0)
            return 0;
        
        while(a < n && b < n){
            if(mp.find(s[b]) == mp.end()){
                mp[s[b]]  = 1;
                b++;
                ans = max(ans, b - a);
            }
            else{
                mp.erase(s[a]);
                a++;
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    Solution ob;
    cout << ob.lengthOfLongestSubstring(s);
    return 0;
}