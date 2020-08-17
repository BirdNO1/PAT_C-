#include<iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int num[n+1];
        num[0] = 1;
        num[1] = 1;
        for(int i=2; i<=n;i++){
            num[i] = getnum(num,i);
        } 
        return num[n];
    }

    int getnum(int* const num,int t){
        int sum =0;
        for(int i=0; i<t; i++){
            sum += num[0]*num[t-1-i];
        }
        return sum;
    }
};

int main(){
    int s = 3;
    Solution a;
    a.numTrees(s);
    system("pause");
    return 0;
}