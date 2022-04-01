#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
vector<int> graph[N];
vector<int> level(N,0);

void dfs(int vertex, int parent=-1){
	for(auto child: graph[vertex]){
		if(parent==child) continue;
		level[child] = level[vertex]+1;
		dfs(child, vertex);
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >>n;
		for(int i=0;i<N;i++){
			graph[i].clear();
			level[i]=0;
		}
		for(int i=0;i<n-1;i++){
			int v1,v2;
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			cout << (level[i]%2==0? "1 " : "2 ");
		}
		cout <<endl;


	}
	return 0;
}