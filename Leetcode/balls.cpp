#include<iostream>
using namespace std;

int main(){
    int T, N, arr[3][3];
    cin >> T;
    int sum = 0;
    while(T)
    {
        cin >> N;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
            }
        }

        sum = 0;
        for(int i = 0; i < 3; i++)
        {
            sum += (N - arr[i][i]);
        }
        T--;
    }
    cout << sum/2;
    return 0;
}