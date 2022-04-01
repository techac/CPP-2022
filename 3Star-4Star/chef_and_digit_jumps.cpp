#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF=1e9+10;

vector<int> graph[N];
vector<int> level(N,INF);
vector<int> visited(N, 0);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin>> s;
	int n= s.length();
	for(int i=0;i<s.length();i++){
		char c = s[i];
		// cin >> c;
		int temp = c - '0';
		// cout << temp << " ";
		graph[temp].push_back(i+1); 
	}
	// cout << endl;
	queue<int> q;
	q.push(1);
	level[1]=0;
	visited[1]=1;

	while(!q.empty()){
		int current = q.front();
		// cout << current << " " ;
		q.pop();

		int next;
		next = current+1;
		if(next>=1 && next<=n){
			if(level[next] > level[current]+1){
				q.push(next);
				visited[next]=1;
				level[next] = level[current]+1;
			}

		}
		next = current-1;
		if(next>=1 && next<=n){
			if(level[next] > level[current]+1){
				q.push(next);
				visited[next]=1;
				level[next] = level[current]+1;
			}
		}
		int value = s[current-1] - (int)'0';
		for(auto child : graph[value]){
			if(level[child] > level[current]+1){
				level[child] = level[current]+1;
				visited[child]=1;
				q.push(child);
			}
		}
		graph[value].clear(); //** once we traverse a value array, it cannot be gone through again
		// was getting TLE without this statement

	}
	cout << level[n] <<'\n';

	return 0;
}