#include<bits/stdc++.h>
using namespace std;
const int N =1e2+10;

int parent[N];
int len[N];


int findParent(int v){
	if(v==parent[v]) return v;
	return parent[v] = findParent(parent[v]);
}

void Union(int a, int b){
	a= findParent(a);
	b = findParent(b);

	if(len[a] <len[b]) swap(a,b); 

	if(a!=b){
		parent[b] = a;
		len[a]+=len[b];
	}

}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >>t;
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i=0;i<N;i++){
			parent[i]=i;
			len[i]=1;
		}
		for(int i=0;i<m;i++){
			int v1,v2;
			cin>> v1>>v2;
			Union(v1,v2);
		}
		int q;
		cin >> q;
		while(q--){
			int v1,v2;
			cin >> v1>>v2;
			if(findParent(v1)==findParent(v2)){
				cout <<"YO" <<'\n';
			}
			else{
				cout << "NO"<<'\n';
			}
		}


	}
	return 0;
}