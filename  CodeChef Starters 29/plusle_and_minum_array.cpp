#include<bits/stdc++.h>
using namespace std;
//solved
// https://www.codechef.com/problems/PMA
#define ll long long int

int main(int argc, char const *argv[])
{
	ll t;
	cin >>t;
	while(t--){
		ll n;
		cin >>n;
		vector<ll> input(n);
		ll sum=0;
		for(ll i=0;i<n;i++){
			ll temp;
			cin >>temp;
			if(temp<0){
				temp=-temp;
			}
			if(i%2==0) sum+=temp;
			else sum-=temp;
			input[i]=temp;
		}
		ll min_element = input[0];
		ll max_element = input[1];
		for(ll i=0;i<n;i+=2){
			if(input[i]<min_element){
				min_element= input[i];
			}
		}
		for(ll i=1;i<n;i+=2){
			if(input[i]>max_element){
				max_element=input[i];
			}
		}
		ll result = sum + 2 * max_element - 2*min_element;

		cout << ((result>sum)? result : sum) <<endl;
	}
	return 0;
}