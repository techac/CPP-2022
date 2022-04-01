#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

vector<int> graph[N];
int substreeSum[N];

void dfs(int vertex, int parent=-1){
	for(int child: graph[vertex]){
		if(parent==child) continue;
		dfs(child, vertex);
		substreeSum[vertex] += substreeSum[child];

	}
	substreeSum[vertex] += vertex;

}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin >>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout << substreeSum[i] <<endl;
	}
	// int q;
	// cin >>q;
	// while(q--){
	// 	int x;
	// 	cin >>x;
	// 	cout << substreeSum[x] <<endl;
	// }
	return 0;
}