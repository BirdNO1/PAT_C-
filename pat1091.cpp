#include<iostream>
#include<queue>

using namespace std;

const int Mm = 1286, Nm = 128,Lm = 60;

int a[Lm][Mm][Nm];
bool v[Lm][Mm][Nm];
int M,N,L,T;
/*
int nis(int t1,int t2,int t3){
    if(t1<0||t2<0||t3<0||t1>=L||t2>=M||t3>=N){
        return 0;
    }
    if(!a[t1][t2][t3]){
        return 0;
    }else{
        return 1;
    }
}

int vis(int t1,int t2,int t3){
    if(!a[t1][t2][t3]){
        return 0;
    }else  if(nis(t1,t2,t3-1)||nis(t1,t2,t3+1)\
            ||nis(t1,t2-1,t3)||nis(t1,t2+1,t3)\
            ||nis(t1-1,t2,t3)||nis(t1+1,t2,t3)
            ){
            return 1;
    }else{
        return 0;
    } 
}
*/
struct  node{
    int x,y,z;
};

bool flag(int x,int y,int z){
    if(x>=0&&x<L&&y>=0&&y<M&&z>=0&&z<N){
    if(!v[x][y][z]&&a[x][y][z]){
        return true;
    }
    }
    return false;
}

int bfs(int x,int y,int z){
    node t1;
    t1.x = x; t1.y = y; t1.z = z;
    queue<node> q;
    q.push(t1);
    int cnt = 0;
    v[x][y][z] = true;
    while(!q.empty()){
        t1 = q.front();
        q.pop();
        cnt++;
        node t2;
        if(flag(t1.x,t1.y,t1.z-1)) {t2.x=t1.x,t2.y=t1.y,t2.z=t1.z-1; q.push(t2); v[t1.x][t1.y][t1.z-1]=true;}
        if(flag(t1.x,t1.y,t1.z+1)) {t2.x=t1.x,t2.y=t1.y,t2.z=t1.z+1; q.push(t2); v[t1.x][t1.y][t1.z+1]=true;}
        if(flag(t1.x,t1.y-1,t1.z)) {t2.x=t1.x,t2.y=t1.y-1,t2.z=t1.z; q.push(t2); v[t1.x][t1.y-1][t1.z]=true;}
        if(flag(t1.x,t1.y+1,t1.z)) {t2.x=t1.x,t2.y=t1.y+1,t2.z=t1.z; q.push(t2); v[t1.x][t1.y+1][t1.z]=true;}
        if(flag(t1.x-1,t1.y,t1.z)) {t2.x=t1.x-1,t2.y=t1.y,t2.z=t1.z; q.push(t2); v[t1.x-1][t1.y][t1.z]=true;}
        if(flag(t1.x+1,t1.y,t1.z)) {t2.x=t1.x+1,t2.y=t1.y,t2.z=t1.z; q.push(t2); v[t1.x+1][t1.y][t1.z]=true;}
    }
    if(cnt>=T){
        return cnt;
    }
    return 0;

}

int main(){
    cin>>M>>N>>L>>T;
    for(int i=0; i<L; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<N; k++){
                cin>>a[i][j][k];
            }
            getchar();
        }
    }
    fill(v[0][0],v[0][0]+Lm*Mm*Nm,false);
    int sum = 0;
    for(int i=0; i<L; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<N; k++){
                if(!v[i][j][k]&&a[i][j][k]){
                    sum+=bfs(i,j,k);
                }
            }
        }
    }
    cout<<sum;
    
//    system("pause");
    return 0;
}