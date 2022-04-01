#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >>t;
	while(t--){
		long long n;
		cin >>n;
		// cout << n <<endl;
		while((n&1) ==0){
			n = n>>1;
			// cout << n << " ";
		}
		cout << n <<endl;
	}
	return 0;
}