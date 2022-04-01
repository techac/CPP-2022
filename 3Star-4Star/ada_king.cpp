#include<bits/stdc++.h>
using namespace std;

int x[] = {-1,1,-1,0,1,-1,0,1};
int y[] = {0,0,1,1,1,-1,-1,-1};
int input[8][8][8];

int dfs(int i,int j, int n, int m, int k){
	if(k<0) return 0;
	if(i<0 || j<0) return 0;
	if(i>=n || j >=m) return 0;
	if(input[i][j][k]!=0) return 0;
	int ans=1;
	// cout << "Current location: "<<endl;
	// cout << i << " " <<j <<endl;
	// cout <<"possible moves: "<<endl;
	for(int move=0;move<8;move++){
		int newX = i + x[move];
		int newY = j + y[move];
		// cout <<newX << " " << newY <<endl;

		ans += dfs(newX,newY,n,m,k-1);
	}
	input[i][j][k]=ans;
	return ans;

}
int main(int argc, char const *argv[])
{
	int t;
	cin >>t;
	while(t--){
		int r,c,k;
		cin >>r >>c >>k;
		memset(&input,0,sizeof(input));
		cout << dfs(r-1,c-1,8,8,k)<<endl;

	}
	return 0;
}