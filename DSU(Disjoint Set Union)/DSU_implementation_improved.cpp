#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int parent[N];
int size[N];

void make(int v){
	parent[v]=v;
	size[v]=1;
}

int find(int v){
	if(v==parent[v]) return v;
	//path compression
	return parent[v] = find(parent[v]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(size[a] < size[b]) swap(a,b);

	if(a!=b){
		parent[b]=a;
		size[a] +=size[b];
	}


}

int main(int argc, char const *argv[])
{
	
	return 0;
}