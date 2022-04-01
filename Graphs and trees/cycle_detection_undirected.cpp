#include<bits/stdc++.h>
using namespace std;
const int N =1e3+10;

vector<int> g[N];
bool vis[N];

bool detect_cycle_using_dfs(int vertex, int parent){
	vis[vertex]=true;
	bool cycleExists = false;
	for(int child : g[vertex]){
		if(vis[child] && child ==parent) continue;
		if(vis[child] && child!=parent) return true;

		cycleExists |= detect_cycle_using_dfs(child, vertex);
	}
	return cycleExists;
}
int main(int argc, char const *argv[])
{
	int n,v;
	cin >>n >>v;

	for(int i=0;i<v;i++){
		int v1,v2;
		cin >>v1 >>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	bool result = false;
	for(int i=1;i<=N;i++){
		if(!vis[i]){
			bool haveCycle = detect_cycle_using_dfs(i);
			if(haveCycle){
				result = true;
			}
		}
		
	}
	cout <<result<<endl;
	

	
	return 0;
}