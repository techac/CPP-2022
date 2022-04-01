#include<bits/stdc++.h>
using namespace std;
const int N= 5;
vector<pair<int,int>> graph[N];
const int start = 0;
const int last = 4;
int visited[N];

bool dfs(int length, int *input, int vertex){
	if(vertex==last && length==0) return true;
	int value = input[0];
	bool returnValue = false;
	for(auto child: graph[vertex]){
		if(child.second==value){
			returnValue |= dfs(length-1,input+1, child.first);
		}else continue;
	}
	return returnValue;
}
int main(int argc, char const *argv[])
{
	int t ;
	cin >>t;
	graph[0] ={{0,0},{1,1}};
	graph[1] = {{1,1},{2,0}};
	graph[2] = {{1,1},{3,0}};
	graph[3] = {{1,1},{4,0}};
	graph[4] = {{0,0},{1,1}};

	while(t--){
		string s;
		cin >>s; 
		memset(&visited,0,sizeof(visited));
		int* input = new int[s.length()];
		for(int i=0;i<s.length();i++){
			input[i] = (int)(s[i]-'0');
		}
		// for(int i=0;i<s.length();i++){
		// 	cout << input[i] <<" ";
		// }
		// cout <<endl;
		// for(int i=0;i<5;i++){
		// 	for(auto child: graph[i]){
		// 		cout << child.first << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << (dfs(s.length(), input, 0)? "YES" : "NO") <<endl;
	}
	return 0;
}