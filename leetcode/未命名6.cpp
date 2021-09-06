#include<bits/stdc++.h>
using namespace std;
int main(){
	int a = 500, b=300;
	int* aa = &a;
	int* bb = aa;
	aa = &b;
	cout<<*bb<<endl;
}
