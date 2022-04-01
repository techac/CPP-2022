#include<bits/stdc++.h>
using namespace std;
const int N=12;
const int INF = 1e9+10;

vector<pair<int, int>> graph[N];
vector<int> visited(N,0);
vector<int> output;

void countPaths2(int vertex, int n, vector<int> &dist){
	if(vertex==n){
		output.push_back(dist[vertex]);
	}
	for(auto child : graph[vertex]){
		int child_v = child.first;
		if(dist[child_v]==-1){
			dist[child_v] = child.second + dist[vertex];
			countPaths2(child_v, n, dist);
			dist[child_v]=-1;
		}

	}
}



int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >>n >> m;
		for(int i=0;i<N;i++){
			graph[i].clear();
			visited[i]=0;
		}
		output.clear();
		for(int i=0;i<m;i++){
			int v1,v2,v3;
			cin >> v1 >> v2 >>v3;
			graph[v1].push_back({v2,v3});
			graph[v2].push_back({v1,v3});
		}
		vector<int> dist(n+5,-1);
		vector<int> level(n+5,0);

		dist[1]=0;

		countPaths2(1,n,dist);
		int minElement = INT_MAX;
		for(auto child: output){
			minElement = min(minElement, child);
		}
		int count=0;
		for(auto child : output){
			if(child == minElement){
				count++;
			}
		}
		cout <<count << endl;
		// cout << level[n]<<endl;
	}
	return 0;
}