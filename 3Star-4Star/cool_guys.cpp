#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(int argc, char const *argv[])
{
	ll t;
	cin >>t;
	while(t--){
		ll n;
		cin >> n;
		ll ans=0;
		ll nn = n*n;
		ll root = sqrt(n);
		for(ll i=1;i<=root;i++){
			ans+= n/i;
		}
		ans = 2 * ans - (root * root);
		ll gcd = __gcd(ans, nn);

		cout <<ans/gcd << "/" <<  nn/gcd <<endl;

	}
	return 0;
}