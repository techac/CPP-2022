#include<bits/stdc++.h>
using namespace std;
const int N =1e6+10;
int ans[N];
int isPrime[N]={1};
void sieve(){
	for(int i=2;i<N;i++){
		if(isPrime[i]){
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=0;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	memset(&isPrime, 1, sizeof(isPrime));
	sieve();

	// int count=0;
	// for(int i=2;i<N;i++){
	// 	if(isPrime[i]){
	// 		count++;
	// 	}
	// }
	// cout << count <<endl;

	
	ans[0]=ans[1]=ans[2]=0;
	for(int i=3;i<N;i++){
		if(isPrime[i]){
			int newNum = i+2;
			if(newNum<N){
				if(isPrime[newNum]){
					ans[newNum]++;
				}
				
			}
		} 
	}
	for(int i=3;i<N;i++){
		ans[i]+=ans[i-1];
		// cout << ans[i] <<" ";
	}
	// cout <<endl;
	
	while(t--){
		int n;
		cin >>n;
		cout << ans[n]<<endl;
	}
	return 0;
}