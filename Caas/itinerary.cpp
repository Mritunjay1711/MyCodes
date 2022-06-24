/*
Find itinerary from the given list of departure and arrival airports
Given a list of departure and arrival airports, find the itinerary in order. It may be assumed that departure is scheduled from every airport except the final destination, and each airport is visited only once, i.e., there are no cycles in the route.

For example,

Input:
 
HKG —> DXB
FRA —> HKG
DEL —> FRA
 
Output: DEL —> FRA —> HKG —> DXB 
 
Input:
 
LAX —> DXB
DFW —> JFK
LHR —> DFW
JFK —> LAX
 
Output: LHR —> DFW —> JFK —> LAX —> DXB
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string getItinerary(string str[][2], int n){
    string ans = "";
    map<string, string> mp1, mp2;
    for(int i = 0; i < n; i++){
        mp1.insert(make_pair(str[i][0], str[i][1]));
        mp2.insert(make_pair(str[i][1], str[i][0]));
    }

    string source, dest;
    for(auto i = mp1.begin(); i != mp1.end(); i++){
        if(mp2.find(i->first) == mp2.end()){
            source = i->first;
        }
    }

    auto i = mp1.find(source);
    ans+=source;
    while(i != mp1.end()){
        ans += ("->"+i->second);
        i = mp1.find(i->second);
    }
    return ans;
}

int main(){
    string  input[][2] ={
                {"LAX", "DXB"},
                {"DFW", "JFK"},
                {"LHR", "DFW"},
                {"JFK", "LAX"}};

    cout << getItinerary(input, 4);
    return 0;
}