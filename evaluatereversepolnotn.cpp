#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stack; //using stacks to reverse
        for(auto x:tokens){
            if(x=="+" || x=="-" || x=="/" || x=="*"){
                int in =stack.top();
                stack.pop();
                int out =stack.top();
                stack.pop();

                if(x=="+"){
                    stack.push(in+out);
                }
                if(x=="-"){
                    stack.push(out-in);
                }
                if(x=="/"){
                    stack.push(out/in);
                }
                if(x=="*"){
                    stack.push(out*in);
                }

            }
            else{
                stringstream str(x);
                int d;
                str>>d;
                stack.push(d);
            }
        }
        return stack.top();
    }
};
