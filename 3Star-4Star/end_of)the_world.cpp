#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N =1e7+100;
const int num=350;
// 'E' 'O' 'P'
int input[num][num];
char type[num][num];
int consider[num][num];
int visited[num][num];

vector<int> isPrime(N, 1);
vector<int> primePosition(N,-1);
vector<pair<int, int>> movements = {{-1,0},{1,0},{0,-1},{0,1}};

void setPositions(){
	int count=0;
	for(int i=2;i<N;i++){
		if(isPrime[i]){
			primePosition[i]=count;
			count++;
		}
		else{
			primePosition[i]=-1;
		}
	}
}

void sieve(){
	int count=0;
	for(int i=2;i<N;i++){
		if(isPrime[i]){
			primePosition[i]=count;
			count++;
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=0;
			}
		}
	}
}
void bfs(int value, int i, int j, int n){
	
	queue<pair<int, int>> q;
	q.push({i,j});
	visited[i][j]=1;

	while(!q.empty()){
		pair<int, int> current = q.front();
		q.pop();

		for(pair<int, int> child : movements){
			int newX = current.first + child.first;
			int newY = current.second + child.second;
			if(newX<1 || newY<1) continue;
			if(newX >n || newY >n )continue;
			if(!visited[newX][newY] && consider[newX][newY]==value){
				q.push({newX,newY});
				visited[newX][newY]=1;
				consider[newX][newY]=0;
			}
		}
	}


}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >>t;
	sieve();
	// setPositions();
	while(t--){
		int n;
		cin >> n;
		memset(&visited,0,sizeof(visited));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> input[i][j];
				int pass = input[i][j];
				if(pass%2==0){
					if(pass==2){
						type[i][j] = 'P';
						consider[i][j]=3;
					}
					else{
						type[i][j] = 'E';
						consider[i][j]=1;
					}
				}else{
					if(isPrime[pass]){
						type[i][j]='P';
						consider[i][j]=3;
					}else{
						type[i][j]='O';
						consider[i][j]=2;
					}

				}

			}
		}

		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=n;j++){
		// 		if(type[i][j]=='P') ;
		// 		else if(type[i][j]=='E') 
		// 		else 
		// 	}
		// }

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(consider[i][j]!=3 && consider[i][j]>0 && !visited[i][j]){
					bfs(consider[i][j], i, j, n);
				}
			}
		}
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=n;j++){
		// 		cout << consider[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(consider[i][j]>0){
					if(consider[i][j]==3){
						ll toAdd = primePosition[input[i][j]];
						ans+= toAdd;
					}
					else if(consider[i][j]==2){
						//odd number
						ll toAdd= input[i][j];
						toAdd = (toAdd+1)/2 +1;
						ans+= toAdd;

					}else if(consider[i][j] == 1){
						ll toAdd = input[i][j];
						toAdd = toAdd/2;
						ans+= toAdd;
					}
				}
			}
		}
		cout << ans <<'\n';




	}
	return 0;
}