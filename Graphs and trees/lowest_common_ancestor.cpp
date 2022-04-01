#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> graph[N];

int par[N];

void dfs(int vertex, int parent){
	par[vertex] = parent;
	for(int child:graph[vertex]){
		if(child==parent) continue;
		dfs(child, vertex);
		
	}
}

vector<int> findPath(int vertex){
	int curr_vertex=vertex;
	vector<int> result;
	result.push_back(curr_vertex);
	while(par[curr_vertex]!=-1){
		result.push_back(par[curr_vertex]);
		// cout << par[curr_vertex] << " ";
		curr_vertex = par[curr_vertex];
	}
	reverse(result.begin(), result.end());
	return result;
}
int main(int argc, char const *argv[])
{	
	int n;
	cin >> n ;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin >> v1 >>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1,-1);
	// for(int i=1;i<=n;i++){
	// 	cout << i << " " <<par[i] <<endl;
	// }
	int x,y;
	cin>>x>>y;
	vector<int> pathX = findPath(x);
	vector<int> pathY = findPath(y);

	int loopLength = min(pathX.size(), pathY.size());
	int commonNode;
	for(int i=0;i<loopLength;i++){
		if(pathX[i] ==pathY[i]){
			commonNode=pathX[i];
		}else break;
	}
	cout << commonNode <<endl;


	
	return 0;
}