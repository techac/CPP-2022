#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N= 1e6+10;
ll isPrime[N];
vector<ll> hp(N);
map<ll, ll> ans;
void sieve(){
	for(ll i=2;i<N;i++){
		if(isPrime[i]){
			hp[i]=i;
			for(ll j= 2*i;j<N;j+=i){
				isPrime[j]=0;
				hp[j]=i;
			}
		}
	}
}

void primeFactors(ll n){
	ll num=n;
	while(num>1){
		ll pf = hp[num];
		while(num%pf==0){
			num/=pf;
			ans[pf]++;
		}
	}
}

int main(int argc, char const *argv[])
{
	ll t;
	cin>> t;
	memset(&isPrime, 1, sizeof(isPrime));
	sieve();

	while(t--){
		ans.clear();
		ll n;
		cin >> n;
		for(ll i=0;i<n;i++){
			ll temp;
			cin >> temp;
			primeFactors(temp);
		}
		ll finalAns=1;
		for(auto m:ans){
			finalAns *= (m.second+1);
		}
		cout << finalAns <<endl;

	}
	return 0;
}