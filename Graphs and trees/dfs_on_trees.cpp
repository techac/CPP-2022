#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

vector<int> graph[N];
int height[N], depth[N];

void dfs(int vertex, int parent=-1){

	for(int child : graph[vertex]){

		if(child==parent) continue;
		depth[child] = 1 + depth[vertex];
		dfs(child, vertex);
		height[vertex] = max(height[vertex], height[child]+1); 

	}

}

int main(int argc, char const *argv[])
{
	int n;
	cin >>n;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin >>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout << depth[i] << " " <<height[i] <<endl;
	}

	
	return 0;
}