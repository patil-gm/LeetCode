/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/

class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<long> st;
        for(auto it:arr){
            long sc,fr,ans;

            if(it=="+"){
                sc=st.top();
                st.pop();
                fr=st.top();
                st.pop();

                ans=fr+sc;
                st.push(ans);
            }
            else if(it=="-"){
               sc=st.top();
                st.pop();
                fr=st.top();
                st.pop();

                ans=fr-sc;
                st.push(ans);
            }
            else if(it=="*"){
                sc=st.top();
                st.pop();
                fr=st.top();
                st.pop();

                ans=fr*sc;
                st.push(ans);
            }
            else if(it=="/"){
                sc=st.top();
                st.pop();
                fr=st.top();
                st.pop();
                
                ans=fr/sc;
                st.push(ans);

            }
            else{
                long x=stol(it);
                st.push(x);
            }
        }

        return st.top();
    }
};