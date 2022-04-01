#include<bits/stdc++.h>
using namespace std;





int main(int argc, char const *argv[])
{
	int t;
	int x[] = {2,1,-1,-2,-2,-1,1,2};
	int y[] = {-1,-2,-2,-1,1,2,2,1};
	cin >>t;
	while(t--){
		map<pair<int, int>, int> distance; 
		char a,b,c,d;
		int visited[8][8];
		memset(visited, 0, sizeof(visited));
		cin >>a>>b>>c>>d;
		int a1,a2,a3,a4;
		a1 = a-'a';
		a2 = b-'1';
		a3= c-'a';
		a4= d-'1';
		pair<int, int> start = {a1,a2};
		pair<int, int> end = {a3,a4};
		// cout << start.first << " " <<start.second <<endl;
		// cout << end.first << " " <<end.second <<endl;

		queue<pair<int,int>> q;
		q.push(start);
		distance[start] =0;
		visited[start.first][start.second] =1;
		while(!q.empty()){
			pair<int, int> current_pos = q.front();
			q.pop();
			// cout <<current_pos.first << " " <<current_pos.second<<endl;
			if(current_pos.first == end.first && current_pos.second == end.second){
				cout << distance[current_pos] <<endl;
				break;
			}
			int nextX,nextY;
			pair<int,int> nextPos;
			for(int i=0;i<8;i++){
				nextX = current_pos.first + x[i];
				nextY = current_pos.second + y[i];
				if(nextX < 0 || nextY <0) continue;
				if(nextX >=8 || nextY>=8) continue;
				if(visited[nextX][nextY]==1) continue;
				pair<int, int> newPos = {nextX,nextY};
				visited[nextX][nextY] =1;
				q.push(newPos);
				distance[newPos] = distance[current_pos] +1;
			}
		}

	}
	return 0;
}