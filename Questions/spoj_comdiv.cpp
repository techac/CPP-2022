#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// https://www.spoj.com/problems/COMDIV/
const int N = 1e6+5;
int divisorsCount[N];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >>t;
	for(int i=1;i<N;i++){
		for(int j=i;j<N;j+=i ){
			divisorsCount[j]+=1;
		}
	}
	// for(int i=1;i<20;i++){
	// 	cout << divisorsCount[i] <<endl;
	// }
	while(t--){
		int a,b;
		cin >> a>>b;
		int largestDivisor = __gcd(a,b);
		cout << divisorsCount[largestDivisor] <<"\n";

	}
	return 0;
}