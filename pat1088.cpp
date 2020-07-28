#include<iostream>

using namespace std;

long long a,b,c,d,e,f;

long long s1,s2,s3;
long long gcd(long long h1,long long h2){
    if(h2==0) return h1;
    else return gcd(h2,h1%h2);
}

void dataprocess(long long t1,long long t2){
    s1 = t1 / t2;
    s2 = t1 - s1*t2;
    s3 = t2;
    s2 = s2*s3/abs(s3);
    s3 = abs(s3);
    long long k = gcd(abs(s2),abs(s3));
    s2 = s2/k; s3 = s3/k;
}

void output(){
    if(s1>0){
        cout<<s1;
        if(s2>0){
            cout<<" "<<s2<<'/'<<s3;
        }
    }else if(s1==0){
        if(s2>0){
            cout<<s2<<'/'<<s3;
        }else if(s2==0){
            cout<<0;
        }else
        {
            cout<<'('<<s2<<'/'<<s3<<")";
        }
        
    }else{
        cout<<'(';
        cout<<s1;
        if(s2!=0){
            s2 = abs(s2);
            cout<<" "<<s2<<'/'<<s3;
        }
        cout<<')';
        
    }
    //cout<<endl;
}

void add(){
    e = a*d+b*c; f = b*d;
    dataprocess(a,b);
    output();
    cout<<" + ";
    dataprocess(c,d);
    output();
    cout<<" = ";
    dataprocess(e,f);
    output();
    cout<<endl;
}

void difference(){
    e = a*d-b*c; f = b*d; 
    dataprocess(a,b);
    output();
    cout<<" - ";
    dataprocess(c,d);
    output();
    cout<<" = ";
    dataprocess(e,f);
    output();
    cout<<endl;
}

void product(){
    e = a*c; f = b*d; 
    dataprocess(a,b);
    output();
    cout<<" * ";
    dataprocess(c,d);
    output();
    cout<<" = ";
    dataprocess(e,f);
    output();
    cout<<endl;
}

void quotient(){
    e = a*d; f = b*c; 
    dataprocess(a,b);
    output();
    cout<<" / ";
    if(c==0){
        cout<<"0 = Inf";
        return;
    }
    dataprocess(c,d);
    output();
    cout<<" = ";
    dataprocess(e,f);
    output();
    cout<<endl;
}

int main(){
    char ss1,ss2;
    cin>>a>>ss1>>b>>c>>ss2>>d;
    add();
    difference();
    product();
    quotient();
    return 0;
}