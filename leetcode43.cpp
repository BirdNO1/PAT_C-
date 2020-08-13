#include<iostream>
#include<string>

using namespace std;
/*

string num1,num2;

int n1[111],n2[111];
int m[111][222];
int result[222];
int len1,len2;


void string_to_num(string s,int n[]){
    int len = s.size();
    for(int i = 0; i<len; i++){
        n[i] = s[len-i-1] - '0';
    }
    return;
}

void num1_multi_num2(){
    
    int i,j;
    for( i=0; i<len2; i++){
        int flag = 0;
        for(j=0; j<len1; j++){
            m[i][j+i] = (flag + n2[i] * n1[j])%10;
            flag = (flag + n2[i] * n1[j])/10;
        }
        m[i][j+i] = flag;
    }
}

void add(){
    int i=0;
    int flag = 0;
    for(; i<(len1+len2); i++){
        int t=0;
        for(int j = 0; j<len2; j++){
            t += m[j][i];
        }
        result[i] = (flag+t) % 10;
        flag = (flag+t) / 10;
    }
    if(flag !=0 ){
        result[i] = flag;
    }
    
}
string paste_string(){
    string s = "";
    int i;
    for(i = 221; i>=0; i--){
        if(result[i]!=0) break;
    }
    for(;i>=0; i--){
        s += (result[i]+'0'); 
    }
    return s;
}

int main(){
    cin>>num1>>num2; len1 = num1.size(); len2 = num2.size();
    string_to_num(num1,n1);
    string_to_num(num2,n2);

    num1_multi_num2();

    add();

    cout<<paste_string(); 

    system("pause");
    return 0;
}
*/
class Solution {
public:

        int n1[111],n2[111];
        int m[111][222];
        int result[222];
        int len1,len2;

    void string_to_num(string s,int n[]){
        int len = s.size();
        for(int i = 0; i<len; i++){
            n[i] = s[len-i-1] - '0';
        }
        return;
    }

    void num1_multi_num2(){
        
        int i,j;
        for( i=0; i<len2; i++){
            int flag = 0;
            for(j=0; j<len1; j++){
                m[i][j+i] = (flag + n2[i] * n1[j])%10;
                flag = (flag + n2[i] * n1[j])/10;
            }
            m[i][j+i] = flag;
        }
    }

    void add(){
        int i=0;
        int flag = 0;
        for(; i<(len1+len2); i++){
            int t=0;
            for(int j = 0; j<len2; j++){
                t += m[j][i];
            }
            result[i] = (flag+t) % 10;
            flag = (flag+t) / 10;
        }
        if(flag !=0 ){
            result[i] = flag;
        }
        
    }
    string paste_string(){
        string s = "";
        int i;
        for(i = 221; i>=0; i--){
            if(result[i]!=0) break;
        }
        for(;i>=0; i--){
            s += (result[i]+'0'); 
        }
        return s;
    }

    string multiply(string num1, string num2) {
        string_to_num(num1,n1);
        string_to_num(num2,n2);

        num1_multi_num2();

        add();
        
        string s = paste_string(); 
        return s;
    }





};

int main(){
    Solution l;
    string k = l.multiply("78","54");
    system("pause");
    return 0;
}


