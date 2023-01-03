#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     vector<int> prefix_function(string s){
        int n=s.size();
        vector<int> a(n,0);
        for(int i=1;i<n;++i){
            int j = a[i-1];

            while(j>0 && s[i]!=s[j]) 
                j=a[j-1];

            if(s[i]==s[j])
                 ++j;

            a[i]=j;
        }
        return a;
    }
    string longestPrefix(string s) {
       vector<int> prefix = prefix_function(s);
        string str="";
        int n=s.size();
        str = s.substr(0,prefix[n-1]);
        return str;
    }
};