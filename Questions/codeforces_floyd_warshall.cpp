#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/295/B
const int N = 505;
const int INF=  1e9+10;

int dist[N][N];
int graph[N][N];

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> graph[i][j];
			dist[i][j] = graph[i][j];
		}
	}
	vector<int> removedVertex;
	vector<long long> ans;
	for(int i=0;i<n;i++){
		int temp;
		cin >>temp;
		removedVertex.push_back(temp);
	}
	reverse(removedVertex.begin(), removedVertex.end());


	for(int k=0;k<removedVertex.size();k++){
		int iv= removedVertex[k];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][iv] !=INF && dist[iv][j]!=INF){
					dist[i][j] = min(dist[i][j], dist[i][iv] + dist[iv][j]);
				}
			}
		}
		long long int sum=0;
		for(int i=0;i<=k;i++){
			for(int j=0;j<=k;j++){
				sum+= dist[removedVertex[i]][removedVertex[j]];
			}
		}
		ans.push_back(sum);
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<n;i++){
		cout <<ans[i] <<endl;
	}


	return 0;
}