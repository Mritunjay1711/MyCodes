#include<iostream>
#include<string.h>
using namespace std;

void username(string *s, int n)
{
    for(int i = 0; i < n; i++)
    {
        int flag = 0;
        for(int j = 0; j < s[i].length(); j++)
        {
            for(int k = j + 1; k < s[i].length(); k++)
            {
                if((int)s[i][j] > (int)s[i][k])
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            cout << "Yes\n";
        else
            cout << "NO\n";
    }
}

int main(){
    string s[3] = {"bee", "superhero", "ace"};
    username(s, 3);
    return 0;
}