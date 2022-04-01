#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
map<int, int> divisors;

// https://www.spoj.com/problems/DIVSUM/
int main(int argc, char const *argv[])
{
	int t;
	cin >>t;
	for(int i=1;i<N;i++){
		for(int j=2*i;j<N;j+=i){
			divisors[j]+=i;
		}
	}
	while(t--){
		int n;
		cin >>n ;
		cout <<divisors[n]<<endl;

	}
	return 0;
}