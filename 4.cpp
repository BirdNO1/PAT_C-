// 1090.cpp : 定义控制台应用程序的入口点。
// 并查集搜索从叶搜根

#include <iostream>
#include <cmath>
using namespace std;
int n;
double p, r;
int a[100005];
int d[100005];
int deep(int i) {
    if (i == -1) return -1;
    if (d[i]) return d[i];
    else return d[i] = 1 + deep(a[i]);
}
int main()
{
    cin >> n >> p >> r;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int max = -1, num = 0;
    for (int i = 0; i < n; i++) {
        int tmp=deep(i);
        if (tmp > max) { max = tmp; num = 1; }
        else if (tmp == max) num++;
    }
    cout<<max;
    printf("%.2f %d", p*pow(1 + r / 100.0, max), num);
    system("pause");
    return 0;
}