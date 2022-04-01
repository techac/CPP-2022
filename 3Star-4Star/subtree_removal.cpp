#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N= 1e5+10;
const ll INF = 1e9+5;

ll sum[N];
ll value[N];
vector<ll> graph[N];
void dfs(ll vertex, ll parent, ll x){
	for(auto child: graph[vertex]){
		if(parent==child) continue;
		dfs(child,vertex,x);
		sum[vertex] += sum[child];

	}
	sum[vertex] = max(-x, sum[vertex]+value[vertex]);
}

int main(int argc, char const *argv[])
{
	ll t;
	cin >>t;
	while(t--){
		ll n,x;
		cin >> n>>x;
		for(ll i=0;i<N;i++){
		    graph[i].clear();
		    sum[i]=0;
		    value[i]=0;
		}
		for(ll i=1;i<=n;i++){
			ll temp;
			cin>> temp;
			value[i]= temp;
		}
		for(ll i=0;i<n-1;i++){
			ll v1,v2;
			cin>> v1 >>v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		dfs(1,-1,x);
		cout << sum[1]<<'\n';

	}
	return 0;
}