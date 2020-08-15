#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size()==0) return s.empty();
        bool first = !s.empty()&&(s[0] == p[0]||p[0] == '.');
        if(p.size()>1&&p[1] == '*'){
            return isMatch(s,p.substr(2)) || first && isMatch(s.substr(1),p);
        }else{
            return first && isMatch(s.substr(1),p.substr(1));
        }
    }
};

int main(){
    string s,p;
    s = "aa";
    p = "a";
    Solution t;
    cout<<t.isMatch(s,p);
    //cout<<s.substr(3).size();
    system("pause");
    return 0;
}