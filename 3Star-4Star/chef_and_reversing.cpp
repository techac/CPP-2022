#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+5;
vector<int> level(N, INF);
vector<pair<int, int>> graph[N];

int bfs01(int start, int n){
	deque<int> q;
	q.push_back(start);
	level[start]=0;

	while(!q.empty()){
		int current = q.front();
		q.pop_front();
		for(auto child: graph[current]){
			int weight = child.second;
			int childVertex = child.first;
			if(level[childVertex] > level[current] + weight){
				level[childVertex] = level[current] + weight;
				if(weight){
					q.push_back(childVertex);
				}else{
					q.push_front(childVertex);
				}
			}
		}
	}
	return (level[n]==INF? -1 : level[n]);

}
int main(int argc, char const *argv[])
{
	int n,m;
	cin >>n >>m;
	for(int i=0;i<m;i++){
		int v1,v2;
		cin >>v1>>v2;
		if(v1==v2)continue;
		graph[v1].push_back({v2, 0});
		graph[v2].push_back({v1,1});
	}
	cout <<bfs01(1,n)<<endl;
	
	return 0;
}