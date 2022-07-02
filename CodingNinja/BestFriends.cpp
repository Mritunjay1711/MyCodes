/*
students are arranged according to rank and they are friends if they are in range k
Best friends if they are in range k and length of name is same
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll BestFriends(vector<string> arr, ll k){
    ll n = arr.size();
    ll ans = 0;
    
    map<int, int> mp;
    for(int i = 0; i <= k; i++){
        int temp = arr[i].length();
        mp[temp]++;
    }
    
    int i = 0, j = k+1;
    
    while(i < n){
        if(mp[arr[i].length()]>1)
        	mp[arr[i].length()]--;
        else
            mp.erase(arr[i].length());
        auto temp = mp.find(arr[i].length());
        if(temp != mp.end() && temp->second > 0){
            // cout << temp->second;
            ans += temp->second;
            // cout << ans << " \n";
        }
        i++;
        
        if(j < n){
            mp[arr[j].length()]++;
            j++;
        }
    }
    
    return ans;
    
}


int main() {
	
	// Write your code here
    ll N, K;
    cin >> N >> K;
    
    vector<string> arr(N);
    ll ans = 0;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    cout << BestFriends(arr, K);
    
    return 0;
}