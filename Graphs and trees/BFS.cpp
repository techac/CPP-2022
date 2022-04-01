#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool vis[N];
int level[N];
int parent[N];

void bfs(int source){
	queue<int> q;
	q.push(source);
	vis[source] =true;
	while(!q.empty()){
		int curr_v = q.front();
		q.pop();
		cout << curr_v << " ";
		for(int child : g[curr_v]){
			if(!vis[child]){
				q.push(child);
				vis[child]=1;
				level[child] = level[curr_v]+1;
				parent[child] =curr_v;
			}
		}

	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n ;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin >>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	bfs(1);
	
	return 0;
}