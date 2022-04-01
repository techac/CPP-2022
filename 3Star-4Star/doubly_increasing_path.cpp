#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N = 1e5+5;

ll value[N];
vector<ll> graph[N];
ll visited[N];

ll dfs(ll vertex, ll currentDiff){
	// visited[vertex] = 1;
	ll ans=0;
	// cout <<"Current Vertex: " << vertex << " current diff: " << currentDiff << endl;
	for(auto child: graph[vertex]){
		// if(visited[child]) continue;
		
		if(value[child]- value[vertex] > currentDiff){
			// cout <<"Going to: " << child <<" from: "<< vertex << " current Diff: " << currentDiff << " " ;
			ans = max(ans, dfs(child, value[child] - value[vertex]));
		}

	}
	// cout <<endl;
	return ans+1;
}

int main(int argc, char const *argv[])
{
	ll t;
	cin >> t;
	while(t--){
		 ll n,m;
		 cin >>n >>m;
		 for(ll i=0;i<N;i++){
		 	value[i]=0;
		 	visited[i]=0;
		 	graph[i].clear();
		 }
		 for(ll i=1;i<=n;i++){
		 	cin >> value[i];
		 }
		 for(ll i=0;i<m;i++){
		 	ll v1,v2;
		 	cin >>v1 >>v2;
		 	graph[v1].push_back(v2);
		 	graph[v2].push_back(v1);
		 }
		 ll ans=INT_MIN;
		 ll ansVertex;
		 // dfs(1,0);
		 for(ll i=1;i<=n;i++){
		 	// memset(&visited,0,sizeof(visited));
		 	ll temp =  dfs(i,0);
		 	if(temp> ans){
		 		ans=temp;
		 		ansVertex = i;
		 	}
		 }
		 cout <<ans <<endl;



	}
	return 0;
}