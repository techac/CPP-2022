#include<bits/stdc++.h>
using namespace std;

const int N = 500;
const int INF = 1e9+10;

int dist[N][N];
vector<pair<int, int>> graph[N];

int main(int argc, char const *argv[])
{
	int n,m;
	cin >>n >> m;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j) dist[i][j]=0;
			else dist[i][j]=INF;
		}
	}
	for(int i=0;i<m;i++){
		int v1,v2,v3;
		cin >>v1 >> v2 >>v3 ;
		graph[v1].push_back({v2,v3});
		dist[v1][v2] =v3;
		// dist[v2][v1] = v3;
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k] !=INF && dist[k][j]!=INF){
					dist[i][j] = min(dist[i][j] , dist[i][k]+dist[k][j]);
				}
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dist[i][j]==INF)cout << "I ";

			else cout << dist[i][j] << " ";
		}
		cout <<endl;
	}
	
	return 0;
}