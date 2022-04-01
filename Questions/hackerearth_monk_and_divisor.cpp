
// https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/
#include<bits/stdc++.h>
using namespace std;

#define N 2*1e5+10
long long int findgcd(long long a, long long b){
	if(b==0){
		return a;
	}
	return findgcd(b,a%b);
}
int main(){
	int n;
	cin >>n;
	vector<int> a(N,0);
	vector<int> ct(N,0);
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		a[temp]++;
	}
	for(int i=1;i<N;i++){
		for(int j=i;j<N;j+=i){
			if(a[j]!=0){
				ct[i]+=a[j];
			}
		}
	}
	int t;
	int p,q;
	long long ans;
	cin >>t;
	while(t--){
		cin >>p>>q;
		
		ans = ct[p] +ct[q];
		long long int ans2 = (p*1LL*q)/__gcd(p,q);
		if(ans2<N){
			ans = ans - ct[ans2];
		}
		

		// cout <<ans2 <<endl;
		cout << ans <<endl;
		// cout <<endl;

	}

}