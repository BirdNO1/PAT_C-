#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4+5;

struct node{
    string s;
    int num = 0;
};

bool cmp(node &a,node &b){
    if(a.num!=b.num){
        return a.num>b.num;
    }else 
    {
        return a.s<b.s;
    }

}

int N,M;
node data[maxn];


int main(){
    //初始化
    cin>>N>>M;
    for(int i=0;i <N; i++){
        cin>>data[i].s; 
        scanf("%d",&data[i].num);
    }

    string tem; int t;
    for(int i=0; i<M;i++){
        int tag = 0;
        cin>>t>>tem;
        printf("Case %d: %d ",i+1,t);
        cout<<tem<<endl;

        if(t==1){
            vector<node> N1; 
            for(int j=0; j<N; j++){
                if(data[j].s[0] == tem[0]){
                    N1.push_back(data[j]);
                    tag = 1;
                }
            }
            if(tag){
                sort(N1.begin(),N1.end(),cmp);
                for(int j=0; j<N1.size(); j++){
                    cout<<N1[j].s;
                    printf(" %d\n",N1[j].num);
                }
            }
        }else if(t == 2){
            int tol_num=0,tol_sco=0;
            for(int j=0; j<N; j++){
                if(data[j].s.substr(1,3) == tem){
                    tol_num++;
                    tol_sco += data[j].num;
                    tag = 1;
                }
            }
            if(tag) {printf("%d %d\n",tol_num,tol_sco);}//cout<<<<" "<<<<endl;
        }else{
            vector<node> N3; 
            unordered_map<string,int> n3;
            for(int j=0; j<N; j++){
                if(data[j].s.substr(4,6) == tem){   
                    string s = data[j].s.substr(1,3);
                    n3[s]++;
                    tag = 1;  
                }
            } 
            if(tag){
                for(auto it:n3){
                    node temnode{it.first,it.second};
                    N3.push_back(temnode);
                }
                sort(N3.begin(),N3.end(),cmp);
                for(int j=0; j<N3.size(); j++){
                    cout<<N3[j].s;
                    printf(" %d\n",N3[j].num);
                }
            }
        }
        if(tag == 0){
            printf("NA\n");
        }
    }
   //system("pause");
    return 0;
}