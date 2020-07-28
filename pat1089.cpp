#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 110;

int main(){
    int N;
    cin>>N;
    int a[maxn];
    int b[maxn];
    for(int i=1; i!=N+1; i++){
        cin>>a[i];
    }
    for(int i=1; i!=N+1; i++){
        cin>>b[i];
    }
    int tag=1,i;
    for(;tag!=(N)&&b[tag] <= b[tag+1]; tag++);
    for(i=tag+1; i<=N&&a[i] == b[i]; i++);
    if(i==(N+1)){
        cout<<"Insertion Sort"<<endl;
        sort(a+1,a+tag+2);
    }else{
        cout<<"Merge Sort"<<endl;
        int t1 = 0,k=1;
        while(t1!=N){
            t1 = 0;
            int t=1;
            while(a[t] == b[t]&&t!=(N+1)){
                t1++;
                t++;
            };
            k=k*2;
            for(i =0; i<N/k; i++){
                sort(a+1+i*k,a+1+(i+1)*k);
            }
            sort(a+1+(N/k)*k,a+N+1);  
        }
    }
    cout<<a[1];
    for(int i=2; i!=N+1; i++){
        cout<<" "<<a[i];
    }
    system("pause");
    return 0;
}