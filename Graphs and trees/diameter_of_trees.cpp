#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> graph[N];
int depth[N];


void dfs(int vertex, int parent=-1){
	for(int child: graph[vertex]){
		if(parent == child) continue;
		depth[child] = 1 + depth[vertex];
		

		dfs(child,vertex);

	}

}

int main(int argc, char const *argv[])
{
	int n;
	cin >>n;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin >>v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1);
	int maxDepth=-1, maxDepthNode;
	for(int i=1;i<=n;i++){ 
		if(depth[i]>maxDepth){
			maxDepth = depth[i];
			maxDepthNode = i;
		}
	}
	for(int i=0;i<N;i++){
		depth[i]=0;
	}
	dfs(maxDepthNode);
	maxDepth=-1;
	maxDepthNode;
	for(int i=1;i<=n;i++){
		if(depth[i]>maxDepth){
			maxDepth = depth[i];
			maxDepthNode = i;
		}
	}

	cout << maxDepth <<endl;

	
	return 0;
}