#include<iostream>
#include<string>

using namespace std;

double np,na,nt;

int main(){
    string s;
    cin>>s;
    for(int i=0; i<s.size();i++){
        if(s[i]=='P'){
            np++;
        }else if(s[i]=='A'){
            na += np;
        }else{
            nt += na;
        }
    }
    cout<<int(nt)%1000000007;
    system("pause");
    return 0;
}