#include<map>
#include<iostream>
#include<map>

using namespace std;

string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int N;

map<string,int> m1,m2;

void func1(string t){
    int t1 = atoi(t.c_str());
    int tag = 1;
    if(t1==0){
        cout<<a[0];
    }
    while(t1!=0){
        if(tag){
            if(t1>12){
                cout<<b[t1/13];
                t1 = t1%13;
            }else{
                cout<<a[t1%13];
                t1 = 0;
            }
            tag = 0;
        }else{
            cout<<" "<<a[t1];
            t1 = t1/13;
        }
    }
}

int func2(string t,int th){
    if(th){
        return m2[t];
    }else
    {
        if(m1.find(t)!=m1.end()){
            return m1[t];
        }
        return 13*m2[t];
    }
    
}

int main(){
    for(int i=0;i<13;i++){
        m1[a[i]] = i;
        m2[b[i]] = i;
    }
    cin>>N;
    string s;
    char h;
    for(int i=0; i<N; i++){
        int sum = 0;
        do{
            cin>>s; h = getchar();
            if(s[0]>='0'&&s[0]<='9'){
                func1(s);
            }else{
                sum = 13*sum + func2(s,h==' '? 1:0);
                if(h=='\n'){
                    cout<<sum;
                }
            }
        }while(h!='\n');

        cout<<endl;
    }
    system("pause");
    return 0;
}


