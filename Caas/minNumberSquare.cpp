#include<iostream>
#include<cmath>
using namespace std;

int minNumSquare(int n){
    int count = 0;
    while(n){
        int temp = (int)sqrt(n);
        count++;
        // cout << temp << " ";
        n -= (temp * temp);
    }
    return count;
}

int main(){
    cout << minNumSquare(63) << endl;
    return 0;
}