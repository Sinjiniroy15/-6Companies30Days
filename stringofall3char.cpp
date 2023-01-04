#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int i = 0 , j = 0 , n = s.size() - 1;
        unordered_map<char,int> map;
        
        int count = 0;
        
        while(j != s.size())
        {
            map[s[j]] += 1; 
            while(map['a'] and map['b'] and map['c'])
            {
                count += 1 + (n - j);
                map[s[i]] -= 1; 
                i++;
            }
            j++;
        }
        return count;
    }
};