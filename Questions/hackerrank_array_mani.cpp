#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];

int main(){
	int n,q;
	cin >>n >>q;
	while(q--){
		int l,r,v;
		cin >> l >>r >>v;
		a[l]=a[l] + v;
		a[r+1] = a[r+1] -v; 


	}
	for(int i=1;i<=n;i++){
		a[i] = a[i] + a[i-1];
	}
	int maxValue = INT_MIN;
	for(int i=1;i<=n;i++){
		if(a[i]>maxValue){
			maxValue = a[i];
		}
	}
	cout <<maxValue<<endl;


}