#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
         int count=1;
        double s;
        int n=p.size();
        for(int i=0;i<n-1;i++){
              unordered_map<double,int>m;
            int a=p[i][0];
           int b=p[i][1];
            for(int j=i+1;j<n;j++){
                int x=p[j][0];
                int y=p[j][1];
                int netx=x-a;
                if(netx==0){
                    s=INT_MAX;
                }
                else{
                 s=(double)((y-b)/(double)(x-a));
                }
                m[s]++;
            }
            for(auto it:m){
            count=max(count,it.second+1);
        }
        }
        return count;
    } 

};