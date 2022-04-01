#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int INF = 1e9+5;
vector<int> graph[N];

int depth[N];
int visited[N];

void dfs(int vertex, int parent=-1){
	for(int child : graph[vertex]){
		if(parent==child) continue;
		depth[child] = depth[vertex] +1;
		dfs(child,vertex);
 	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >> n;
		for(int i=0;i<N;i++){
			graph[i].clear();
		}
		for(int i=0;i<n-1;i++){
			int u,v;
			cin >> u >>v;
			graph[u].push_back(v);
			graph[v].push_back(u);	
		}
		memset(&visited,0,sizeof(visited));
		memset(&depth,-1,sizeof(depth));
		//find max depth vertex from 1;
		depth[1]=0;
		dfs(1);
		// for(int i=1;i<=n;i++){
		// 	cout << depth[i] << " ";
		// }
		// cout <<endl;
		int selected;
		int maxDepth=INT_MIN;
		for(int i=1;i<=n;i++){
			if(depth[i]>maxDepth){
				maxDepth=depth[i];
				selected=i;
			}
		}
		// cout << selected <<endl;
		memset(&visited,0,sizeof(visited));
		memset(&depth,-1,sizeof(depth));
		depth[selected]=0;
		dfs(selected);
		int diameter=INT_MIN;
		for(int i=1;i<=n;i++){
			diameter = max(diameter, depth[i]);
		}
		cout <<diameter <<endl;

	}

	return 0;
}