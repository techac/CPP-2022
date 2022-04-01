#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &input,int l, int r, int target, bool findStart){
        int ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            cout <<l <<" "<< r <<" " <<mid<<endl;
            if(target==input[mid]){
                ans = mid;
                if(findStart){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            else if(target>input[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        cout << l << " " << r <<endl;
        return ans;
    }
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> input;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		input.push_back(temp);
	}
	int target;
	cin >>target;
	cout << binarySearch(input,0,n-1,target,true)<<endl;
	cout << binarySearch(input,0,n-1,target,false);
	return 0;
}