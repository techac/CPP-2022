#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >>n >> m;
		int input[n+1];
		memset(&input,0,sizeof(input));
		for(int i=0;i<m;i++){
			int v1,v2;
			cin >>v1>>v2;
			input[v1]++;
			input[v2]++;

		}
		int can=1;
		for(int i=1;i<=n;i++){
			if(input[i]>1) can=0;
		}
		cout << (can ?"YES" : "NO") <<endl;
	}
	return 0;
}