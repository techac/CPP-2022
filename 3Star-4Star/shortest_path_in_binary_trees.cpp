#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> getBinary(ll n){
	vector<int> ans;
	while(n>0){
		ans.push_back(n&1);
		n >>= 1;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(int argc, char const *argv[])
{
	ll t;
	cin >> t;
	while(t--){
		ll v1,v2;
		cin>> v1>>v2;
		ll ans1 = (ll)log2(v1);
		ll ans2 = (ll)log2(v2);
		vector<int> rep1 = getBinary(v1);
		vector<int> rep2 = getBinary(v2);
		int i=0,j=0;
		int count=0;
		while(i<rep1.size() && j<rep2.size()){
			if(rep1[i] == rep2[j]){
				count++;
			}else{
				break;
			}
			i++;
			j++;
		}
		cout << rep1.size()+rep2.size()-2*count <<endl;
		
	}
	return 0;
}