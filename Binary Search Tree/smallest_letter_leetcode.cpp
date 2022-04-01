#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<char> &input, int l, int r, char target){
	while(l<=r){
		int mid = l + (r-l)/2;
		if(input[mid] <= target){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return l;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >>n;
	vector<char> input;
	for(int i=0;i<n;i++){
		char temp;
		cin>> temp;
		input.push_back(temp);
	}
	char target;
	cin >>target;
	cout << binarySearch(input,0,n-1,target)<< endl;

	return 0;
}