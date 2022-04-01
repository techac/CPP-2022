#include<bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/EAGLE1/

#define ll long long int
const ll N = 1e5+5;
vector<pair<ll,ll>> graph[N];
bool visited[N];

ll dfs(ll vertex){
	visited[vertex] = true;
	ll maxValue = 0;
	for(pair<ll,ll> child: graph[vertex]){
		if(!visited[child.first]){
			ll temp = child.second + dfs(child.first);
			if(temp>maxValue){
				maxValue=temp;
			}
		}
	}
	return maxValue;
}

int main(int argc, char const *argv[])
{
	ll t;
	cin >>t;
	while(t--){
		ll n;
		cin >> n;
		for(ll i=0;i<N;i++){
			graph[i].clear();
		}
		for(ll i=0;i<n-1;i++){
			ll v1,v2,d;
			cin >>v1 >>v2 >>d;
			graph[v1].push_back({v2,d});
			graph[v2].push_back({v1,d});
		}
		for(ll i=1;i<=n;i++){
			for(int i=0;i<N;i++){
				visited[i]=false;
			}
			cout << dfs(i) << " ";
		}
		cout <<endl;

	}
	return 0;
}