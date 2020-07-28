#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct node
{
    int left;
    int right;
    int lnum=0,rnum=0;   //left,right tree number
    int father;   //father id
    int tag = -1;   //tag = 0,left child  ,tag = 1,right chile
    int data;
};

const int maxn = 110;
node tr[maxn];
int n[maxn];
int N;
bool cmp(int a,int b){
    return a<=b;
}

void create(int start,int end,int id){
    if(id < 0||id>N) {return;}
    tr[id].data = n[start+tr[id].lnum];
    create(start,start+tr[id].lnum-1,tr[id].left);
    create(start+tr[id].lnum+1,end,tr[id].right);
}

int main(){
    tr[0].father = -1;
    int l,r;
    cin>>N;
    if(N==0) return 0;
    for(int i=0; i<N; i++){
        cin>>l>>r;
        tr[i].left = l; tr[i].right = r;
        if(l>0)  {tr[l].father = i; tr[l].tag = 0;}
        if(r>0)  {tr[r].father = i; tr[r].tag = 1;}
        int t0 = tr[l].father;
        int t1 = tr[r].father;
        while(t0!=-1&&l>0){
            if(tr[l].tag == 0) {tr[t0].lnum++;}
            else{ tr[t0].rnum++;}
            l = t0;
            t0 = tr[l].father; 
        }
        while(t1!=-1&&r>0){
            if(tr[r].tag == 1) {tr[t1].rnum++;}
            else{tr[t1].lnum++;}
            r = t1;
            t1 = tr[r].father;
        }
    }
     
    for(int i=1;i<=N; i++){
        cin>>n[i];
    }
    
    sort(n+1,n+N+1,cmp);
    
    create(1,N,0);
    
    queue<int> q;
    q.push(0);
    int flag = 1;
    
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(flag){cout<<tr[t].data; flag = 0;}
        else{cout<<" "<<tr[t].data;}
        if(tr[t].left>0) q.push(tr[t].left);
        if(tr[t].right>0) q.push(tr[t].right);
    }

    system("pause");
    return 0;
}
