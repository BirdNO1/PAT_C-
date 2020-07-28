#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int N,K;
struct  node
{
    string id;
    int time;
    int flag;
};

bool cmp1(node a,node b){
    if(a.id<b.id||(a.id==b.id&&a.time<b.time)){
        return true;
    }else{
        return false;
    }
}

bool cmp2(node a,node b){
    return a.time<b.time;
}

int main(){
    cin>>N>>K;
    vector<node> record,clear_R;
    for(int i=0; i<N; i++){
        node t1;
        string s1,s2;
        int h,m,s;
        cin>>s1>>h; getchar(); cin>>m; getchar(); cin>>s>>s2;
        t1.id = s1;
        t1.time = h*3600 + m*60 + s;
        t1.flag = (s2 == "in")? 1:-1;
        record.push_back(t1);
    }
    sort(record.begin(),record.end(),cmp1);
    map<string,int> cnt_time;
    int max_time=0;
    for(int i=0; i<record.size()-1; i++){
        if(record[i].id==record[i+1].id&&record[i].flag==1&&record[i+1].flag==-1){
            clear_R.push_back(record[i]);  clear_R.push_back(record[i+1]);
            cnt_time[record[i].id] += record[i+1].time - record[i].time;
            if(cnt_time[record[i].id]>max_time){
                max_time =  cnt_time[record[i].id];
            }
        }
    }
    record.clear();
    sort(clear_R.begin(),clear_R.end(),cmp2);
    int index=0,cnt = 0;
    for(int i=0; i<K; i++){
        int h,m,s; 
        cin>>h; getchar(); cin>>m; getchar(); cin>>s;
        int time_s = h*3600 + m*60 + s;
        for(int j=index; j<clear_R.size(); j++){
            if(time_s < clear_R[j].time){
                cout<<cnt<<endl;
                index = j;
                break;
            }
            cnt += clear_R[j].flag;
        }
        if(time_s>=clear_R[clear_R.size()-1].time){   //注意等号以及最后一次记录以后的多次查询
                cout<<cnt<<endl;
        }
    }
    for(map<string,int>::iterator k = cnt_time.begin(); k!=cnt_time.end(); k++){
        if((*k).second==max_time){
            cout<<(*k).first<<" ";
        }
    }
    printf("%02d:%02d:%02d",max_time/3600,(max_time%3600)/60,max_time%60);
//    system("pause");
    return 0;
}