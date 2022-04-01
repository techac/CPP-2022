#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main(int argc, char const *argv[])
{
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >>n;
		int indegree[N];
		memset(&indegree,0,sizeof(indegree));
		for(int i=0;i<n-1;i++){
			int u,v;
			cin >>u >>v;
			indegree[v]++;
		}
		int count=0;
		for(int i=1;i<=n;i++){
			if(indegree[i]>1){
				count+= indegree[i];
				count-=1;
			}
		}
		cout <<count <<endl;
	}
	return 0;
}