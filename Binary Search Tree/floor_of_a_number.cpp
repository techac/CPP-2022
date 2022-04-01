#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> &input, int l, int r, int target){
	while(l<=r){
		int mid = l + (r-l)/2;
		if(target==input[mid]){

			return mid;
			// if u want to find the number just less tah target uncomment this.
			// r=mid-1;
		}
		else if(target>input[mid]){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return r;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n ;
	vector<int> input;
	for(int i=0;i<n;i++){
		int temp;
		cin >>temp;
		input.push_back(temp);
	}
	int target;
	cin >>target;
	cout << binarySearch(input, 0,n-1,target);
	return 0;
}