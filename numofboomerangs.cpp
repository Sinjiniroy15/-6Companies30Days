#include<bits/stdc++.h>
using namespace std;

    int dist(vector<int>& p1,vector<int>& p2){
           //creating dist funct here
        return (p2[0] - p1[0])*(p2[0] - p1[0]) + (p2[1] - p1[1])*(p2[1] - p1[1]);
    }
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n = p.size(),ans = 0;
        for(int i = 0; i < n; i++){
            map<int,int> mp;
            for(int j = 0; j < n; j++){
               if(i == j) 
                continue;
               int distance = dist(p[i],p[j]);
               if(mp.find(distance) != mp.end()) ans += mp[distance]*2;
               mp[distance]++;
            }
        }
        return ans;
    } 