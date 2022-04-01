#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/problems/SNSOCIAL
//This code is running on online compiler but not on local compiler
const int N=1e3+5;
const int INF = 1e9+5;
int x[] = {1,0,-1,-1,-1,0,1,1};
int y[] = {-1,-1,-1,0,1,1,1,0};

int main(int argc, char const *argv[])
{
	int t;
	cin >>t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int graph[N][N];
		int level[N][N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				level[i][j]=INF;
			}
		}
		int max_value = INT_MIN;
		queue<pair<int, int>> q;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int temp;
				cin >>temp;
				graph[i][j]=temp;
				max_value = max(max_value, temp);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				// cout <<graph[i][j] << " ";
				if(graph[i][j] == max_value){
					q.push({i,j});
					level[i][j]=0;
				}
			}
			// cout <<endl;
		}
		while(!q.empty()){
			pair<int, int> current = q.front();
			q.pop();
			for(int i=0;i<8;i++){
				int newX = current.first + x[i];
				int newY = current.second + y[i];
				if(newX <0 || newY<0) continue;
				if(newX >=n || newY >=m) continue;
				if(level[current.first][current.second] + 1 < level[newX][newY]){
					level[newX][newY] = level[current.first][current.second] + 1;
					q.push({newX,newY});
				}
			}

		}
		max_value = INT_MIN;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				max_value = max(max_value, level[i][j]);
			}
		}
		cout <<max_value <<endl;



	}

	return 0;
}