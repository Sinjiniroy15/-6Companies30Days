#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    #define ll long long
    int m = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto r : roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<ll> dis(n,LLONG_MAX),ways(n,0);
        ways[0] = 1,dis[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            ll dist = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                ll adjNode = it.first;
                ll ed = it.second;
                if(dist + ed < dis[adjNode]){
                    dis[adjNode] = dist + ed;
                    pq.push({dist + ed,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist + ed == dis[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % m;
                }
            }
        }
        return ways[n-1];
    }
};