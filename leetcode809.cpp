#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int cnt = 0;
        for(int i =1; i<= words.size(); i++){
            cnt += is_shot(S, words[i-1]);
        }
        return cnt;
    }

    int is_shot(string &s, string w){
        char c1 = s[0],c2 = w[0];
        int tag1 = 0, tag2 = 0;
        while(c1 == c2&&tag1 < s.size()&&tag2 < w.size()){
            int cnt1=0,cnt2=0;
            while(s[tag1] == c1 && tag1 < s.size()) {cnt1++; tag1++;}
            if(tag1 != s.size()) c1 = s[tag1];
            while(w[tag2] == c2 && tag2 < w.size()) {cnt2++; tag2++;}
            if(tag2 != w.size())c2 = w[tag2];
            if(cnt2>cnt1 || (cnt2<cnt1&&cnt1<3)) return 0;
        }
        if(tag1 == s.size()&&tag2 == w.size()) return 1;
        return 0;
    }
};

int main(){
    string s = "heeellooo";
    vector<string> words = {{"hello"},{"hi"},{"hilo"}};
    Solution t;
    t.expressiveWords(s,words);
    system("pause");
    return 0;
}