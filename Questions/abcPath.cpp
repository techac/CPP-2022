#include<bits/stdc++.h>
using namespace std;
// https://www.spoj.com/submit/ABCPATH/

char g[100][100];
int graph[100][100];

int dfs(int i, int j, int lastValue, int row, int col, int dp[][100]){
	if(i<0 || j<0) return 0;
	if(i>=row || j>=col) return 0;
	if(graph[i][j] - lastValue!=1 && lastValue!=-100){
		return 0;
	}
	if(dp[i][j]!=-1) return dp[i][j];

	int a = dfs(i-1 , j-1 , graph[i][j], row, col, dp);
	int b = dfs(i-1 , j   , graph[i][j], row, col, dp);
	int c = dfs(i-1 , j+1 , graph[i][j], row, col, dp);
	int d = dfs(i   , j-1 , graph[i][j], row, col, dp);
	int e = dfs(i   , j+1 , graph[i][j], row, col, dp);
	int f = dfs(i+1 , j-1 , graph[i][j], row, col, dp);
	int g = dfs(i+1 , j   , graph[i][j], row, col, dp);
	int h = dfs(i+1 , j+1 , graph[i][j], row, col, dp);

	int maxValue;
	maxValue = 1 + max(a,max(b,max(c,max(d,max(e,max(f,max(g,h)))))));
	dp[i][j]=maxValue;
	return maxValue;
}

int main(int argc, char const *argv[])
{
	int count=0;
	while(true){
		count++;
		int n,m;
		int dp[100][100];
		memset(dp,-1,sizeof(dp));
		cin >> n >>m;
		if(n==0 && m==0){
			break;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> g[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				graph[i][j] = g[i][j]-'A';
				// cout << graph[i][j] << " ";
			}
			// cout <<endl;
		}
		int maxValue = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(graph[i][j]==0)
					maxValue = max(maxValue, dfs(i,j,-100,n,m,dp));
			}
		}
		cout << "Case " << count << ": " <<maxValue <<endl;



	}
	
	return 0;
}