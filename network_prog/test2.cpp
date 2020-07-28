#include <iostream>
 
using namespace std;
 
int(*func)(int a, int b);
int bar(int a, int b)
{
    return a + b;
}
 
 
 
int foo(int a, int b)
{
    return a;
}
int main()
{
    func = bar;
    cout << func(12, 34) << endl;
    system("pause");
    func = foo;
    cout << func(12, 34) << endl;
    system("pause");
    return 0;
}