#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int isPrime[N];
int countPrimes[N];
vector<int> hp(N);
int ans[N][10];
void sieve(){
	for(int i=2;i<N;i++){
		if(isPrime[i]){
			hp[i]=i;
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=0;
				hp[j]=i;
			}
		}
	}
}
void primeCount(){
	for(int i=2;i<N;i++){
		int num =i;
		while(num>1){
			int current = hp[num];
			countPrimes[i]++;
			while(num%current==0){
				num/=current;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int t;
	cin>> t;
	memset(&isPrime, 1, sizeof(isPrime));
	sieve();
	primeCount();
	for(int i=2;i<N;i++){
		int pCount = countPrimes[i];
		if(pCount>5) continue;
		ans[i][pCount]=1;
	}
	for(int i=2;i<N;i++){
		for(int j=1;j<=5;j++){
			ans[i][j] += ans[i-1][j];
		}
	}


	while(t--){
		int l,r,k;
		cin >>l >>r >>k;
		// cout << countPrimes[l] << " " <<countPrimes[r] <<endl;
		cout << ans[r][k] - ans[l-1][k] <<endl;

	}
	return 0;
}