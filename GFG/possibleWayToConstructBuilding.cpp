/*
Given N, the number of plots on either sides of the road. Find the total ways to construct buildings in the plots such that there is a space between any 2 buildings. All plots on one side of the road are continuous.
Lets suppose * represents a plot, then for N=3, the plots can be represented as * * * | | * * *                               

Where | | represents the road.                                                                                                                                                                  
Note: As the answer can be very large, print it mod 1000000007

 

Example 1:

Input: N = 3
Output: 25
Explanation: 3 plots, which means possible
ways for one side are BSS, BSB, SSS, SBS,
SSB where B represents a building and S
represents an empty space Total possible 
ways are 25, because a way to place on one
side can correspond to any of 5 ways on other
side
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    long mod = 1e9+7;
	    long dp[N + 1][2] = {1};
	    /*
        1 0
        0 0
        . .
        0 0
	    */

	    for(int i = 1; i <= N; i++){
	        // i denotes the current plot number
	        for(int j = 0; j < 2; j++){
                // j denotes that if there is building(1) or space(0)	            
	            
	            
	            //if j == 0, there is a space means we can keep the building or the space
	            //if j == 1, there is a building means we can keep the space
	            
	            if(j) dp[i][j] = dp[i - 1][0];
	            else dp[i][j] = (dp[i - 1][0] + dp[i - 1][1])%mod;
	        }
	    }
	    
	    long ans = dp[N][0] + dp[N][1]; // Adding the values to total combination
	    
	    // cout << ans << endl;
	    ans = (ans*ans)%mod; //squaring
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
    cout << "Enter no. of testcases: ";
	cin >> tc;
	while(tc--){
		int N;
        cout << "Enter number: ";
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends