#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int INF = 1e9+10;

int main(int argc, char const *argv[])
{
	// ios_base::sync_with_stdio(false);
 //    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
    	vector<pair<int, int>> graph[N];
    	int n,m;
    	cin >> n>>m;
    	for(int i=0;i<m;i++){
    		int a,b,c;
    		cin >>a>>b>>c;
    		graph[a].push_back({b,c});
    	}
    	int start,end;
    	cin >>start>>end;
    	set<pair<int, int>> q;
    	vector<int> distance(N,INF);
    	distance[start]=0;
    	q.insert({0,start});
    	while(q.size()>0){
    		auto current = *q.begin();
    		int v = current.second;
    		int v_dist = current.first;
    		q.erase(q.begin());
    		for(auto child : graph[v]){
    			if(v_dist + child.second < distance[child.first]){
    				distance[child.first] = v_dist + child.second;
    				q.insert({distance[child.first], child.first});
    			}
    		}
    	}

    }
	return 0;
}