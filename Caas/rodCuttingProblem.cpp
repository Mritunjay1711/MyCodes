//Wt[] = length[]
//val[] = price[]
// W = N(length of rod)

#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int rodLen, int n, int length[], int price[]){
    int dp[rodLen + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= rodLen; i++){
        for(int j = 0; j < n; j++){
            if(length[j] <= i)
                dp[i] = max(dp[i], dp[i - length[j]] + price[j]);
        }
    }
    return dp[rodLen];
}

int main(){
    int N = 4;
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(price)/sizeof(price[0]);

	cout << unboundedKnapsack(N, n, length, price);
    return 0;
}