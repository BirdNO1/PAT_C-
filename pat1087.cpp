#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<cstdio>

using namespace std;

const int maxn = 210;
const int inf = 1e9;

int ad[maxn][maxn];
bool vis[maxn];
int tr[maxn];
int dis[maxn];
int num_n[maxn];
int hap[maxn];
int tag[maxn];

struct node{
    int id;
    int hp;
};

map<string, node>  id1;

string id2[maxn];

int N,K;
string tem;
node tem2;

void dj(){
    for(int i=1; i<=N; i++){
        int u=-1,min =inf;
        for(int j=1;j<=N;j++){
            if(vis[j]==false&&dis[j]<min){
                u = j;
                min = dis[j];
            }
        }
        if(u==-1) return;
        vis[u] = true;
        for(int j=1; j<=N; j++){
            if(vis[j]==false&&ad[u][j]!=inf){
                if(dis[u]+ad[u][j]<dis[j]){
                    dis[j] = dis[u]+ad[u][j];
                    tr[j] = u;
                    tag[j]=tag[u];
                    num_n[j] = num_n[u]+1;
                    hap[j] = hap[u]+id1[id2[j]].hp;
                }else if(dis[u]+ad[u][j]==dis[j]){
                    tag[j]+=tag[u];
                    if(hap[u]+id1[id2[j]].hp>hap[j]){
                        hap[j] = hap[u]+id1[id2[j]].hp;
                        tr[j] = u;
                        num_n[j] = num_n[u]+1;
                    }else if(hap[u]+id1[id2[j]].hp==hap[j]){
                        if(num_n[u]+1<num_n[j]){
                            tr[j] = u;
                            num_n[j] = num_n[u]+1;
                        }
                    }
                }
            }
        }
    }
}


int main(){
    fill(ad[0],ad[0]+maxn*maxn,inf);
    cin>>N>>K;
    cin>>tem;
    id2[1] = tem;
    if(tem == "ROM"){
		printf("1 0 0 0\n");
		cout<<"ROM"<<endl;
	}
    tem2.id = 1;
    tem2.hp = 0;
    id1[tem] = tem2;
    int tem3;
    for(int i=2;i<=N;i++){
        cin>>tem>>tem3;
        tem2.id = i;tem2.hp = tem3;
        id1[tem] = tem2;
        id2[i] = tem;
    }
    string s1,s2;
    int cost;
    for(int i=1;i<=K;i++){
        cin>>s1>>s2>>cost;
        ad[id1[s1].id][id1[s2].id] = cost;
        ad[id1[s2].id][id1[s1].id] = cost;
    }
    /*
    if(id2[1] == "ROM"){
		printf("1 0 0 0\n");
		cout<<"ROM"<<endl;
	}
    */
   fill(num_n,num_n+maxn,false);
   fill(tr,tr+maxn,-1);
    fill(vis,vis+maxn,false);
    fill(dis,dis+maxn,inf);
    fill(tag,tag+maxn,0);
    dis[1] = 0; tr[1] = -1; num_n[1] = 0; hap[1] = 0; tag[1]=1;
    dj();
    //cout<<hap[id1["ROM"].id]<<" "<<num_n[id1["ROM"].id];
    cout<<tag[id1["ROM"].id]<<" "<<dis[id1["ROM"].id]<<" "<<hap[id1["ROM"].id]<<" "<<int(hap[id1["ROM"].id]/num_n[id1["ROM"].id])<<endl;
    stack<int> route;
    int l = id1["ROM"].id;
    while(l!=-1){
        route.push(l);
        l = tr[l];
    }
    cout<<id2[route.top()]; route.pop();
    while(!route.empty()){
        cout<<"->"<<id2[route.top()];
        route.pop();
    }
    system("pause");
    return 0;
}