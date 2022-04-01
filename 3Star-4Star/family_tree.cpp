#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N =1e5+5;
const int INF = 1e9+5;
ll value[N];
ll parent[N];
ll minimum[N];
vector<ll> graph[N];

void dfs(int vertex, int parent=-1){
	for(auto child: graph[vertex]){
		if(child== parent) continue;

		dfs(child,vertex);
		minimum[vertex] = min(minimum[vertex], minimum[child]);
	}
	minimum[vertex] = min(minimum[vertex], value[vertex]);
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int root;
	memset(&minimum, INF, sizeof(minimum));
	for(int i=1;i<=n;i++){
		ll temp;
		cin >> temp;
		value[i]= temp;
	}
	for(int i=1;i<=n;i++){
		ll temp;
		cin >>temp;
		if(temp==-1){
			root = i;
		}
		parent[i] =temp;
	}
	for(int i=1;i<=n;i++){
		int v1 = i;
		int v2 = parent[i];
		if(v2==-1) continue;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(root);
	ll ans=-INF;
	for(int i=1;i<=n;i++){
		ans  = max(ans, (value[i] - minimum[i]));
	}
	cout <<ans<<endl;

	return 0;
}