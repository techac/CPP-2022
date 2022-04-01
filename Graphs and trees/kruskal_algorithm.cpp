#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int parent[N],length[N];


void make(int v){
	parent[v]=v;
}
int find(int v){
	if(v==parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void Union(int a,int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		if(length[a] <length[b]) swap(a,b);
		parent[b]=a;
		length[a]+=length[b];

	}

}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n>>m;
	vector<pair<int, pair<int, int>>> edges;
	for(int i=1;i<=n;i++){
		make(i);
	}
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin >>u >>v >>wt;
		edges.push_back({wt,{u,v}});
	}
	sort(edges.begin(), edges.end());
	int totalCost=0;
	for(auto &edge:edges){
		int wt = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if(find(u) == find(v)) continue;
		else{
			Union(u,v);
			totalCost+= wt;
			cout << u << " "<<v <<endl;
		}

	}
	cout <<totalCost <<endl;
	
	return 0;
}