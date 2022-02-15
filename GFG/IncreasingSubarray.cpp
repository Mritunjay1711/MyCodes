#include<iostream>
using namespace std;

class Solution{
    public:
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
    int mingcd(int A[] , int N)
    {
        // Your code goes here  
        int arr[N], len = 0;;
        int ans[N*N], k = 0, flag = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(A[j - 1] <= A[j])
                {
                    arr[len] = A[j - 1];
                    len++;
                    if(j == N-1)
                    {
                        arr[len] = A[j];
                        len++;
                    }
                }
                else
                {
                    arr[len] = A[j];
                    len++;
                    break;
                }
            }
            int result = arr[0];
            flag = 0;
            if(len > 1)
            {
                for(int i = 0; i < len; i++)
                {
                    result = gcd(arr[i], result);
                    cout << result << "*" << endl;
                    if(result == 1)
                    {
                        ans[k] = 1;
                        k++;
                        flag = 1;
                    }
                    if(flag)
                    {
                        break;
                    }
                }
            }
            
            if(!flag)
            {
                ans[k] = result;
                k++;
            }
            cout << len << "***" << endl;
            len = 0;
        }
        int min = 100000;
        for(int i = 0; i < k; i++)
        {
            cout << ans[i] << "**" << endl;
            if(min > ans[i])
            {
                min = ans[i];
            }
        }
        return min;
    }
};

int main(){
    Solution ob;
    int A[] = {11, 9, 15, 14};
    cout << "Ans: " << ob.mingcd(A, 4) << endl;
    return 0;
}