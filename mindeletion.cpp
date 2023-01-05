#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int ans =numsDivide[0];
        sort(nums.begin(),nums.end());
       
        for(int i=1;i<numsDivide.size();i++){
            ans=__gcd(ans,numsDivide[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(ans%nums[i]==0){
                return i;
            }
           
        }
        return -1;

    }
};