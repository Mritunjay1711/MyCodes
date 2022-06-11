#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = 0, k, ind;
    cout << "Enter the size of subarray: ";
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
            ind = i;
        }
    }
    cout << max << " ";
    for(int i = k; i < n; i++)
    {
        if(max < arr[i] && ind > (i - k))
        {
             max = arr[i];
             ind = i;
        }
           
        else if(ind <= i - k)
        {
            max = arr[ind+1];
            ind+=1;
            for(int j = i - k + 1; j < i + 1; j++)
            {
                if(max < arr[j])
                {
                    max = arr[j];
                    ind = j;
                }
                    
            }
        }
        cout << max << " ";
    }
    return 0;
}