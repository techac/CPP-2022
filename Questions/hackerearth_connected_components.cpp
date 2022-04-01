// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/




#include<bits/stdc++.h>
using namespace std;


const int N = 1e3+10;
bool vis[N];
vector<int> g[N];

void dfs(int vertex){
	vis[vertex] = true;
	for(int child : g[vertex]){
		if(!vis[child]){
			dfs(child);
		}
	}
}
bool allVisited(int n){
	bool result=true;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			result=false;
			break;
		}
	}
	return result;
}
int main(int argc, char const *argv[])
{
	int n,v;
	cin >>n>>v;
	for(int i=0;i<v;i++){
		int v1,v2;
		cin >>v1 >>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	int count =0;
	while(!allVisited(n)){
		count++;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				dfs(i);
				break;
			}
		}
		// for(int i=1;i<=n;i++){
		// 	cout <<vis[i] <<" ";
		// }
		// cout <<endl;
	}
	cout << count <<endl;
	
	return 0;
}