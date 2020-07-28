#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 100010;
const int mn = 10010;

struct node
{
    int data;
    int next;
    /* data */
};

node no[maxn];
bool v[mn];

int origin_add;
int remove_add = -1;
int node_num;

int main(){
    fill(v,v+mn,0);
    cin>>origin_add>>node_num;
    for(int i=0;i<node_num;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        no[t1].data = t2; no[t1].next = t3;
    }
    int tem_add = origin_add,tem2_add = -1,last_add = -1;
    int tag = 1;  //用来获取第一个remove
    while(tem_add!=-1){
        if(v[abs(no[tem_add].data)]){   //mn==1  已经存在该数
            if(tag){   //第一次
                remove_add = tem_add;
                tem2_add = remove_add;
                no[last_add].next = no[tem_add].next;
                tag = 0;
                tem_add = no[tem_add].next;
                continue;
            }//不是滴一次
            no[tem2_add].next = tem_add;  tem2_add = tem_add;
            no[last_add].next = no[tem_add].next;
            tem_add = no[tem_add].next;
        }else{
            v[abs(no[tem_add].data)] = 1;   
            last_add = tem_add;
            tem_add = no[tem_add].next;
        }  
    }
    no[tem2_add].next = -1;
    while(origin_add!=-1){
        if(no[origin_add].next!=-1){
            printf("%05d %d %05d\n",origin_add,no[origin_add].data,no[origin_add].next);}
        else{
            printf("%05d %d %d\n",origin_add,no[origin_add].data,no[origin_add].next);
        }
        origin_add = no[origin_add].next;
    }
    if(remove_add==-1){
        system("pause");
        return 0;
    }
    while(remove_add!=-1){
        if(no[remove_add].next!=-1){
            printf("%05d %d %05d\n",remove_add,no[remove_add].data,no[remove_add].next);}
        else{
            printf("%05d %d %d\n",remove_add,no[remove_add].data,no[remove_add].next);
        }
        remove_add = no[remove_add].next;
    }

    system("pause");
    return 0;
}
