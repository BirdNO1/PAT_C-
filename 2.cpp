#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string s1,s2;  //s1 origine
vector<char> t1;

bool find(char t){
    if(t>='a'&&t<='z'){
        t = t-'a'+'A';
    }
    for(int k=0;k<t1.size();k++){
        if(t1[k]==t) return true;
    }
    return false;
}

int main(){
    cin>>s1>>s2;
    int j=0;
    for(int i=0; i<s1.size();){
        if(s1[i]==s2[j]){
            i++;j++;
        }else{
            if(!find(s1[i])){
                if(s1[i]>='a'&&s1[i]<='z'){
                    t1.push_back(s1[i]-'a'+'A');
                }else{
                    t1.push_back(s1[i]);
                }
            }
            i++;
        }
    }
    for(int i=0; i<t1.size();i++){
        cout<<t1[i];
    }

    //system("pause");
    return 0;
}