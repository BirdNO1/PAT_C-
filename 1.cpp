#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> t;
	//int a[10] = {1 ,2 ,3, 3, 4, 5, 6, 7, 8, 9};
	for(int i=0;i<10;i++){
		t.push_back(i);
	}
	int t1 = 1;
	const int &t2 = t1;
	cout<<t2<<endl;
	t1 = 7;
	cout<<t2<<endl;
	system("pause");
	return 0;
}