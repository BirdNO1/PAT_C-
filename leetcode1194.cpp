#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

class Solution {
public:
    struct node
    {
        int s,e;
    };
    stack<node> t1;
    queue<node> t;


    string reverseParentheses(string s) {
        int i=0,j=s.size()-1;
        /*
        while (i<j)
        {
            while(s[i]!='('&&i<j) i++;
            while(s[j]!=')'&&j>i) j--;
            if(i<j){
                node tem;
                tem.s = i; tem.e = j;
                t.push(tem);
                i++; j--;
            }
        }
        */
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                node tem;
                tem.s = i;
                t1.push(tem);
            }
            if(s[i]==')'){
                node tem = t1.top();
                tem.e = i;
                t.push(tem); t1.pop();
            }
        }
        while(t.size()){
            node t1 = t.front();
            reverse(s.begin()+t1.s+1,s.begin()+t1.e);
            t.pop();
        }
        string result = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]!='('&&s[i]!=')'){
                result += s[i]; 
            }   
        }
        return result; 
    }


};

int main(){
    Solution exm1;
    string s;
    cin>>s;
    cout<<exm1.reverseParentheses(s);
    system("pause");
    return 0;
}