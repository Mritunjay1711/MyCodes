#include<iostream>
using namespace std;
int gcd(int a, int b)
    {
        int temp = a < b ? a : b;
        int ans;
        for(int i = 1; i <= temp; i++)
        {
            if(a % i == 0 && b % i == 0)
            {
                ans = i;
            }
        }
        return ans;
    }
int main(){
    cout << gcd(6, gcd(12, 14)) << endl;
    return 0;
}