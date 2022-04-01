#include<bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/HS08PAUL/
const int N  = 1e7+5;
const int sizeX = 1e4+5;
const int sizeY = 1e2+5;

bool a[N];
long long int xSquare[sizeX];
long long int ySquare[sizeY];
long long int sum[sizeX][sizeY];
long long int ans[N];
map<int, int> isOfForm;

int main(int argc, char const *argv[])
{
	int t;
	cin >>t;
	memset(a, true, sizeof(a));
	a[1]=false;
	a[0] = false;
	long long int i;
	long long int j;
	for(i=2;i<N;i++){
		if(a[i]){
			for(j=2*i;j<N;j+=i){
				a[j]=false;
			}
		}
	}
	for(i=0;i<sizeX;i++){
		xSquare[i] = i*i;
	}
	for(j=0;j<sizeY;j++){
		ySquare[j] = j*j*j*j;
	}
	for(int i=0;i<sizeX;i++){
		for(int j=0;j<sizeY;j++){
			long long int sum = xSquare[i] + ySquare[j];
			isOfForm[sum]= 1;

		}
	}

	for(int i=2;i<N;i++){
		ans[i] =ans[i-1];
		if(a[i]){
			if(isOfForm.find(i) != isOfForm.end()){
				ans[i]++;
			}
		}
	}

	while(t--){
		long long int n;
		cin >> n;
		cout <<ans[n] <<endl;



	}
	return 0;
}