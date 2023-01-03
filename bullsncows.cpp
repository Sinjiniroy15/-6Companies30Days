#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
         vector<int> str(10),s(10);
        int bulls=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                str[secret[i]-'0']++;
                s[guess[i]-'0']++;
            }
        }
        int cow=0;
        for(int i=0;i<10;i++)
            cow+=min(str[i],s[i]);
        
        string temp="";
        temp+=to_string(bulls);
        temp+="A";
        temp+=to_string(cow);
        temp+="B";
        return temp;
    }
};