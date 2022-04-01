#include<bits/stdc++.h>

using namespace std;
// https://www.youtube.com/watch?v=4tYoVx0QoN0&ab_channel=Cl%C3%A9mentMihailescu
const int N =1e3+5;
int matrix[N][N];
int visited[N][N];
int canBeRemoved[N][N];

int optionsX[] = {0,1,0,-1};
int optionsY[] = {-1,0,1,0};

void dfs(int i, int j, int row, int column){
	if(i<0 || j<0 ) return;
	if(i>=row || j>=column) return;
	if(visited[i][j]==0 && matrix[i][j]==1){
		visited[i][j]=1;
		canBeRemoved[i][j]=0;
		for(int directions=0;directions<4;directions++){
			int newX = i+optionsX[directions];
			int newY = j+optionsY[directions];
			if(matrix[newX][newY]==1){
				dfs(newX, newY, row, column);
			}
		}

	}
	if(visited[i][j]==0 && matrix[i][j]==0){
		canBeRemoved[i][j]=1;
	}
}

int main(int argc, char const *argv[])
{	
	int n,m;
	cin >> n >> m ;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=0;
			if((i==0 || i==n-1) && (j==0 ||j==m-1)) canBeRemoved[i][j]=0;
			canBeRemoved[i][j]=1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >>matrix[i][j];
		}
	}
	int x[] = {0,n-1};
	int y[] = {0,m-1};

	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			int row= i;
			int column = y[j];
			if(matrix[row][column]==1){
				dfs(row, column,n,m);
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(canBeRemoved[i][j]==0){
				cout << matrix[i][j] << " ";
			}else{
				cout <<"0 ";
			}
			// cout << canBeRemoved[i][j] << " ";
		}
		cout <<endl;
	}


	return 0;
}