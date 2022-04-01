5
3 6 2 4 5
5
1 2
2 4
3 5
1 5
4 4
const int N = 1e5+10;

vector<int> a(N);
vector<int> BIT(N);

void update(int i, int x, int n){
	for(;i<=n;i+=(i&(-i))){
		BIT[i] = __gcd(BIT[i], x);
	}
}

int gcdQuery(int l, int r){
	int i;
	i=r;
	int ans1=0,ans2=0;
	for(;i>0;i-=(i&(-i))){
		ans1 = __gcd(ans1,BIT[i]);
	}
	return ans1;
	// i=r;
	// for(;i>0;i-=(i&(-i))){
	// 	ans
	// }
}



int main(int argc, char const *argv[])
{
	int n;
	cin >> n ;
	for(int i=0;i<n;i++){
		int temp;
		cin >>temp;
		a[i]=temp;
		update(i+1, temp,n);
	}

	int q;
	cin >>q;
	while(q--){
		int l ,r;
		cin >> l >> r;
		cout <<gcdQuery(l,r)<<endl; 

	}

	return 0;
}