#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e5+10;

ll divisorsSum[N];

void sieve(){
	for(int i=1;i<N;i++){
		if(i%2==1){
			for(int j=i;j<N;j+=i){
				divisorsSum[j]+=i;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	sieve();
	for(int i=1;i<N;i++){
		divisorsSum[i] += divisorsSum[i-1];
	}
	// cout << divisorsSum[42];
	while(t--){
		int l,r;
		cin >> l >>r;
		cout << divisorsSum[r] - divisorsSum[l-1]<<endl;

	}
	return 0;
}