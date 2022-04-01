// https://www.codechef.com/problems/GCDQ
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int a[N];
int gcdFromStart[N];
int gcdFromEnd[N];
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >>q;
		gcdFromStart[0]=0;
		gcdFromEnd[0]=0;
		for(int i=1;i<=n;i++){
			cin >>a[i];
			gcdFromStart[i] = __gcd(a[i], gcdFromStart[i-1]);
		}
		for(int i=n;i>0;i--){
			gcdFromEnd[n-i+1] = __gcd(a[i], gcdFromEnd[n-i]);
		}
		// for(int i=0;i<=n;i++){
		// 	cout << gcdFromStart[i] <<" ";
		// }
		// cout<<endl;
		// for(int i=0;i<=n;i++){
		// 	cout << gcdFromEnd[i] <<" ";
		// }
		while(q--){
			int l,r;
			cin >>l >>r;
			int ans;
			ans = __gcd(gcdFromStart[l-1], gcdFromEnd[n-r]);
			cout<< ans <<endl;

		}
	}
	return 0;
}