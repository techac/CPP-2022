#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;
vector<pair<int,int>> graph[N];

const int N = 1e5+10;
   const int INF = 1e9+10;
    
    
void dijkstra(int src, vector<pair<int,int>> graph[], int n){
    vector<int> dist(N, INF);
    vector<int> vis(N, 0);

    set<pair<int,int>> st;
    st.insert({0,src});
    dist[src]=0;

    while(st.size()>0){
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        for(auto child: graph[v]){
            int child_v = child.first;
            int wt = child.second;
            if(v_dist + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}
int main(int argc, char const *argv[])
{
	
	return 0;
}