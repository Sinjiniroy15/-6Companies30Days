#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int flag=0;
        int res=INT_MAX;
        unordered_map<int,int>c;
        for(int i=0;i<n;i++){
            if(c.count(cards[i])){
            res=min(res,i-c[cards[i]]+1);
            flag=1;
            }
               c[cards[i]]=i;
        }
     
        if(flag==0) return -1;
        return res;
        
    }
};