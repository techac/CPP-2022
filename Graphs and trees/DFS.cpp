#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex){
	cout << vertex << " ";
	vis[vertex]=true;
	for(int child: g[vertex]){
		if(!vis[child]){
			dfs(child);
		}

	}
}


int main(int argc, char const *argv[])
{
	int n,m;
	cin >>n >>m;
	for(int i=0;i<m;i++){
		int v1,v2;
		cin >>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);

	}
	dfs(1);
	return 0;
}