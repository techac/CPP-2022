#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int parent[N];
int length[N];

void make(int v){
    parent[v]=v;
    length[v]=1;
}
int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b){
    a= find(a);
    b= find(b);
    


    if(a!=b){
        if(length[a] < length[b]) swap(a,b);
        parent[b]=a;
        length[a]+=length[b];
    }
}

int main(){
    int n;
    cin >>n;
    for(int i=1;i<=n;i++){
        make(i);
    }
    int k; 
    cin >>k;
    for(int i=0;i<k;i++){
        int v1,v2;
        cin >>v1 >>v2;
        Union(v1,v2);
    }
    int connected_ct=0;
    for(int i=1;i<=n;i++){
        if(i==parent[i]) connected_ct++;
    }
    cout << connected_ct <<endl;


}