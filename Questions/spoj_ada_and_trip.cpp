#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int INF = 1e9+10;

int main(int argc, char const *argv[])
{
	int n,m,q;
	cin >> n >> m>>q;
	vector<pair<int,int>> graph[N];
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >>a>>b>>c;
		if(a==b) continue;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	vector<pair<int, int>> ans(N,-1);
	for(int i=0;i<n;i++){
		int city=i;
		set<pair<int, int>> q;
		vector<int> distance(N, INF);

		distance[city]=0;
		q.insert({0,city});

		while(q.size()>0){
			auto current = *q.begin();
			int v = current.second;
			int v_dist = current.first;
			q.erase(q.begin());
			for(auto child : graph[v]){
				int child_v = child.first;
				int wt = child.second;
				if(v_dist + wt < distance[child_v]){
					distance[child_v] = v_dist + wt;
					q.insert({distance[child_v], child_v});
				}
			}
		}
		int max_value = INT_MIN;
		int count=0;
		for(int i=0;i<n;i++){
			if(distance[i] ==INF) continue;
			max_value = max(max_value, distance[i]);
		}
		for(int i=0;i<n;i++){
			if(max_value == distance[i]){
				count++;
			}
		}
		ans[i] = {max_value,count};
	}
	while(q--){
		int city; 
		cin >> city;
		cout << ans[city].first << " " << ans[city].second<<endl;		


	}
	return 0;
}