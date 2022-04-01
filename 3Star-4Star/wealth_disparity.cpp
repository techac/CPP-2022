#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
const ll INF = 1e9+10;
ll value[N];
ll parent[N];
ll minimum[N];
vector<ll> graph[N];
ll ans=INT_MIN;
pair<int, int> ansVer;

// https://www.codechef.com/LP3TO401/problems/INOI1601

void dfs(int vertex, int parent=-1){
	for(auto child : graph[vertex]){
		if(parent== child) continue;
		// ans = max(ans, );
		// if(value[vertex] - value[child] > ans){
		// 	ans = value[vertex] - value[child];
		// 	ansVer = {vertex,child}; 
		// }
		//going down
		dfs(child, vertex);
		minimum[vertex] = min(minimum[vertex], minimum[child]);
		//going UP
	}
	minimum[vertex] = min(value[vertex],minimum[vertex]);

}

int main(int argc, char const *argv[])
{
	ll n, root;
	cin >> n;
	memset(&minimum, INF, sizeof(minimum));
	for(int i=1;i<=n;i++){
		ll temp;
		cin >> temp;
		value[i] = temp;
	}
	for(int i=1;i<=n;i++){
		ll temp;
		cin >> temp;
		if(temp==-1){
			root= i;
		}
		parent[i] = temp;
	}
	for(int i=1;i<=n;i++){
		int v1 = i;
		int v2 = parent[i];
		if(v2==-1) continue;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(root);

	for(int i=1;i<=n;i++){
		// cout << minimum[i] << " ";
		ans = max(ans, value[i]-minimum[i]);
	}
	// cout <<endl;
	cout << ans<<endl;
	// cout << ansVer.first << " " << ansVer.second <<endl;

	return 0;
}