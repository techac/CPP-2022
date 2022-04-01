#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/problems/REVERSE

const int N = 1e5+10;
const int INF = 1e9+10;
vector<pair<int, int>> graph[N];
vector<int> level(N, INF);

int bfsZeroOne(int start, int n)
{
	deque<int> q;
	q.push_back(start);
	level[1]=0;
	while(!q.empty()){
		int curr_v  = q.front();
		q.pop_front();
		for(auto child : graph[curr_v]){
			int child_v = child.first;
			int weight = child.second;
			if(level[curr_v] + weight < level[child_v] ){
				level[child_v] = level[curr_v]+weight; 
				if(weight==1){
					q.push_back(child_v);
				}
				else{
					q.push_front(child_v);
				}
			}
		}

	}
	return level[n] ==INF ? -1 : level[n];

}
int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >>m;
	for(int i=0;i<m;i++){
		int v1,v2;
		cin >>v1 >>v2;
		if(v1==v2) continue;
		graph[v1].push_back({v2,0});
		graph[v2].push_back({v1,1});
	}
	cout << bfsZeroOne(1,n);
	return 0;
}