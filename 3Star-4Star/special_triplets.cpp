#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> divisors[N];
int divisorCount[N];

void sieve(){
	for(int i=1;i<N;i++){
		for(int j=2*i;j<N;j+=i){
			divisors[j].push_back(i);
			divisorCount[j]++;
		}
	}
}

int main(int argc, char const *argv[])
{
	int t ;
	cin >> t;
	sieve();
	while(t--){
		int n;
		cin >>n;
		int ans=0;
		for(int b=2;b<=n;b++){
			int segments = n/b;
			ans += (segments*divisorCount[b]);
			//calculation for partial segments at last
			int lastSegment = segments*b;
			for(auto divisor : divisors[b]){
				if(lastSegment+divisor <=n){
					ans++;
				}
			}
		}
		cout << ans <<endl;

	}
	return 0;
}