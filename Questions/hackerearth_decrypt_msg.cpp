#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
vector<int> a(N,0);
vector<int> hp(N,0);
vector<int> canRemove(N,0);




vector<int> distictPF(int x){
	vector<int> ans;
	while(x>1){
		int pf = hp[x];
		while(x%pf==0){
			x/=pf;
		}
		ans.push_back(pf);

	}
	return ans;
}

int main(int argc, char const *argv[])
{
	for(int i=2;i<N;i++){
		if(hp[i]==0){
			hp[i]=i;
			for(int j=2*i;j<N;j+=i){
				hp[j]=i;
			}
		}
	}


	int n,q;
	cin >>n >>q;
	for(int i=0;i<n;i++){
		int temp;
		cin >>temp;
		a[temp]=1;
	}
	for(int i=2;i<N;i++){
		if(a[i]==1){
			for(long long int j=i; j<N; j*=i){
					canRemove[j]=1;
			}
		}
	}
	while(q--){
		int x;
		cin>> x;
		vector<int> pf = distictPF(x);
		bool isPossible = false;
		for(int i=0;i<pf.size();i++){
			for(int j=i;j<pf.size();j++){
				int product = pf[i] * pf[j];
				if(i==j && x%product!=0){
						continue;
				}
				int toRemove = x/product;
				if(canRemove[toRemove] || toRemove==1){
						isPossible = true;
						break;
				}

			}
			if(isPossible){
				break;
			}
		}
		cout << (isPossible ? "YES\n" : "NO\n");

	}

	return 0;
}