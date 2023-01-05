#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
       vector<int> adj[n];
        for(auto it : a){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(n);
        for(int i = 0;i < n;i++){
            for(auto it : adj[i]) indegree[it]++;
        }
        queue<int> q;
        for(int i = 0;i< n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == n) return true;
        return false;
    }
};