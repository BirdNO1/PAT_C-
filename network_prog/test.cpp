#include<iostream>

using namespace std;

void operator<<(ostream &output, check a){
    output<<a.s1;
}

class check{
 friend void operator<<(ostream &output, check a);
public:
    check(int* b,int* e): beg(b),end(e),curr(b){

    }
    check(istream& input){
        cout<<"please input s1";
        input>>s1;
    }
    void show(int k){
        cout<<*(beg+k)<<endl;
    }
    void show(){
        cout<<s1;
    }
private:
    int *beg, *end, *curr;
    int s1,s2;
};

int main(){
    int* a = new int[10];
    for(int i=0; i<10; i++){
        a[i] = i;
    }
    check t(a,a+10);
    for(int i=0; i<10; i++){
        t.show(i);
    }

    check k(cin);
    //k.show();
    cout<<endl;
    cout<<a;

    system("pause");
    return 0;
    
}