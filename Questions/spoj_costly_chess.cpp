#include<bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/CCHESS/

const int INF = 1e9+10;

int x[] = {-2,-1,1,2,2,1,-1,-2};
int y[] = {1,2,2,1,-1,-2,-2,-1};

int main(int argc, char const *argv[])
{
	int a,b,c,d;
	while(cin >>a >>b >>c >>d){
		int distance[8][8];
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				distance[i][j]=INF;
			}
		}
		distance[a][b]=0;
		set<pair<int, pair<int, int>>> q;
		q.insert({0,{a,b}});
		while(q.size()>0){
			auto current = *q.begin();
			int vX = current.second.first;
			int vY = current.second.second;
			int vDist = current.first;
			q.erase(q.begin());

			for(int i=0;i<8;i++){
				int newX = vX + x[i];
				int newY = vY + y[i];
				if(newX <0 || newY<0) continue;
				if(newX>=8 || newY>=8) continue;
				if(vDist + vX*newX + vY*newY < distance[newX][newY]){
					distance[newX][newY] = vDist + vX*newX + vY*newY;
					q.insert({distance[newX][newY],{newX,newY}});
				} 
			}
		}
		cout << distance[c][d] <<endl;

	}
	return 0;
}