#include<bits/stdc++.h>
using namespace std;
const int N = 13;
// * = treasure
// . = path
// # = blocked
int dist[N][N];
int visited[N][N];
char input[N][N];
vector<pair<int, int>> output;

vector<pair<int, int>> positions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isValid(int i, int j, int n){
	if(i<0 || j <0 ) return false;
	if(i>=n || j>=n) return false;
	return true;

}

void dfs(int totalValue, int n, int i, int j, int moves){
	// cout << i << " " << j << " " << totalValue << " " << moves<<endl;
	if(i==n-1 && j==n-1){
		output.push_back({dist[i][j], totalValue});
	}

	for(auto child : positions){
		int new_x = i + child.first;
		int new_y = j + child.second;
		if(isValid(new_x, new_y, n) && dist[new_x][new_y]==-1){
			if(input[new_x][new_y]=='#') continue;
			dist[new_x][new_y] = dist[i][j] +1;
			visited[new_x][new_y]++;
			if(input[new_x][new_y]=='*'){
				input[new_x][new_y]='.';
				dfs(totalValue-1,n,new_x, new_y, moves+1);
				input[new_x][new_y]='*';
			}else{
				dfs(totalValue, n, new_x, new_y, moves+1);
			}
			dist[new_x][new_y]=-1;
			// visited[new_x][new_y]--;
		}
	}



}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		output.clear();
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				dist[i][j]=-1;
				visited[i][j]=0;
			}
		}
		int count=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				char temp ;
				cin >> temp;
				if(temp=='*'){
					count+=1;
				}

				input[i][j]=temp;
			}
		}
		dist[0][0]=0;
		visited[0][0]=1;
		dfs(count, n ,0,0,0);
		for(auto child: output){
			if(child.second==0)
			cout << child.first << " ";
		}
		cout << endl;
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		char temp ;
		// 		 cout << input[i][j] << " ";
		// 	}
		// 	cout <<endl;
		// }
	}
	return 0;
}