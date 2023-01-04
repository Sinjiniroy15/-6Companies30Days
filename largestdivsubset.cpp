#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return vector<int>();
        }
        vector<int> a(n, 1);
        vector<int> subset(n, -1);
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] % nums[j] == 0 && a[j] + 1 > a[i]) {
                    a[i] = a[j] + 1;
                    subset[i] = j; 
                }
            }
        }
        int maxIndex = 0, maxLen = 0;
        for(int i=0;i<n;i++) {
            if(a[i] > maxLen) {
                maxLen = a[i];
                maxIndex = i;
            }
        }
        vector<int> ans(maxLen);
        int x = maxLen-1;
        while(maxIndex != -1) { 
            ans[x] = nums[maxIndex];
            maxIndex = subset[maxIndex];
            x--;
        }
        return ans;
    }
};