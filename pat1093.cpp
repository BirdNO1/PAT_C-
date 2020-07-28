#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct node
{
    int na,nt;
};

vector<node> np;

int main(){
    string s;
    cin>>s;
    for(int i=0; i<s.size();i++){
        if(s[i] == 'P'){
            node t1;
            t1.na = t1.nt = 0;
            np.push_back(t1);
        }else if(s[i] == 'A'){
            vector<node>::iterator t1 = np.begin();
            while(t1!=np.end()){
                (*t1).na++;
                t1++;
            }
        }else if(s[i] == 'T'){
            vector<node>::iterator t1 = np.begin();
            while(t1!=np.end()){
                (*t1).nt++;
                t1++;
            }
        }
    }
    double cnt;
    vector<node>::iterator t1 = np.begin();
    while(t1!=np.end()){
        //cnt+=min((*t1).na,(*t1).nt);
        cnt+=(*t1).na*(*t1).nt;
        t1++;
    }
    cout<<int(cnt)%1000000007;
    system("pause");
    return 0;
}
