#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
     int distance(vector<int> &p1, vector<int>&p2){
        return pow((p2[0]-p1[0]),2)+pow((p2[1]-p1[1]),2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12=distance(p1,p2);
        int d23=distance(p2,p3);
        int d34=distance(p3,p4);
        int d41=distance(p4,p1);
        int d24=distance(p2,p4);
        int d13=distance(p1,p3);

        unordered_set<int>s;
        s.insert({d12,d23,d34,d41,d24,d13});

        return !s.count(0) && s.size()==2;
        
    }
};