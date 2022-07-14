#include<bits/stdc++.h>
using namespace std;

vector<string> findItinerary(vector<vector<string>> tickets) {
    unordered_map<string, vector<string>> mp; 
    
    for(auto tick: tickets){
        mp[tick[0]].push_back(tick[1]);
    }
    
    for(auto &x:mp){
        sort(x.second.begin(), x.second.end());
    }
    
    vector<string> ans;
    ans.push_back("JFK");
    string temp = "JFK";
    
    while(mp.find(temp) != mp.end()){
        auto itr = mp.find(temp);
        temp = itr->second[0];
        itr->second.erase(itr->second.begin());
        if(mp[itr->first].size() == 0){
            mp.erase(itr->first);
        }
        // cout << temp << " ";
        ans.push_back(temp);
    }
    return ans;
}


int main(){
    vector<vector<string>> arr 
    {
        {"MUC", "LHR"}, 
        {"JFK", "MUC"}, 
        {"SFO", "SJC"}, 
        {"LHR", "SFO"}
    };
    vector<string> ans = findItinerary(arr);

    for(auto x:ans){
        cout << x << " ";
    }
    return 0;
}