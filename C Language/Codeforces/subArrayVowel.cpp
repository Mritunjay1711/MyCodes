#include<iostream>
using namespace std;

void vowelSubArray(string s, int k)
{
    char ch[k - 1];
    int temp = 0;
    for(int i = 0; i < s.length() - k; i++)
    {
        int count = 0;
        for(int j = i; j < k + i; j++)
        {
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' ||  s[j] == 'o' || s[j] == 'u')
                count++;
        }
        if(count > temp)
        {
            temp = count;
            int counter = 0;
            for(int j = i; j < k + i; j++)
            {
                ch[counter++] = s[j];
            }
            ch[counter] = '\0';
        }
    }
    if(temp)
        cout << ch << endl;
    else
        cout << "Not found!\n";
}

int main(){
    string s = "aeiouia";
    vowelSubArray(s, 3);    
    return 0;
}