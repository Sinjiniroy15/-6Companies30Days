#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     int n = nums.size();
        int end = -1,start =-1;
        int maxi = nums[0], mini = nums[n-1];
        for(int i=1;i<n;i++)
        {
            maxi = max(maxi, nums[i]);
            if(nums[i]<maxi) end = i;
        }
        for(int i=n-2;i>=0;i--)
        {
            mini = min(mini, nums[i]);
            if(nums[i]>mini) start = i;
        }
        if(end==-1 || start==-1) return 0;
        return end-start+1;
        
    }
};