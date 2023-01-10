#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     #define ll long long int
    ll validPairs(ll l,ll r,vector<ll> &nums,int diff){
        if(l == r) return 0;
        ll m = (l+r) >> 1;
        ll ans = validPairs(l,m,nums,diff) + validPairs(m+1,r,nums,diff);
        vector<ll> merged;
        ll l1 = l,r1 = m,l2 = m+1,r2 = r;
        for(ll j = l2;j <= r2;j++){
            ll mxAllowed = nums[j] + diff;
            ll idx = upper_bound(nums.begin() + l1,nums.begin() + r1 + 1,mxAllowed) - nums.begin() - 1;
            if(idx <= r1) ans += (idx - l1 + 1);
        }
        while(l1 <= r1 && l2 <= r2){
            if(nums[l1] <= nums[l2]) merged.push_back(nums[l1++]);
            else merged.push_back(nums[l2++]);
        }
        while(l2 <= r2) merged.push_back(nums[l2++]);
        while(l1 <= r1) merged.push_back(nums[l1++]);
        for(ll i = l;i <= r;i++) nums[i] = merged[i-l];
        return ans;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ll n = nums1.size();
        vector<ll> nums(n);
        for(int i = 0;i < n;i++) nums[i] = nums1[i] - nums2[i];
        return validPairs(0,n-1,nums,diff);
    }
};