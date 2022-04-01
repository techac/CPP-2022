#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	map<string, int> occ;
	for(int i=0;i<n;i++){
		string s;
		cin >>s;
		sort(s.begin(),s.end());
		occ[s]++;
	}
	int ans = INT_MIN;
	for(auto member: occ){
		ans = max(ans, member.second);
	}
	cout <<ans <<endl;
	return 0;
}