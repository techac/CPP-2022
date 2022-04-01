#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+5;

vector<int> factors(N,0);
vector<int> BIT(N,0);
int ans[N][11];

void sieve(){
	for(int i=2;i<N;i++){
		if(factors[i]==0){
			for(int j=i;j<N;j+=i){
				factors[j]++;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	sieve();
	
	for(int i=0;i<=N;i++){
		int j=factors[i];
		ans[i][j]++;
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<11;j++){
			ans[i][j] += ans[i-1][j];
		}
	}
	cin >>t;
	while(t--){
		int a,b,c;
		// int ans=0;
		cin >>a >>b >>c;
		cout << ans[b][c] - ans[a-1][c]<<endl; 
		// cout <<ans<<endl;

	}
	return 0;
}