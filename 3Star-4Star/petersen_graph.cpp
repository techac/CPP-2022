#include<bits/stdc++.h>
using namespace std;

vector<int> innerGraph[10];
vector<int> outerGraph[10];
int selectValue(char c, int outer){
	int value = (int)(c - 'A');
	if(outer){
		return value;
	}else{
		return value+5;
	}
}
bool Reach(int start, int end, int outer){
	int isOuter = outer;
	if(isOuter){
		for(auto child : outerGraph[start]){
			if(child==end){
				return true;
			}
		}
	}else{
		for(auto child : innerGraph[start]){
			if(child ==end){
				return true;
			}
		}
	}
	return false;
}

bool answer(int outer, string s){
		bool ans= true;
		vector<int> output;
		int current = selectValue(s[0],outer);
		int prev=-1;
// 		cout << prev << " " << current << endl;
		output.push_back(current);
		for(int i=1;i<s.length();i++){
			prev = current;
			current = selectValue(s[i], outer);

			if(prev == current){
				if(current<5){
					current = current+5;
					output.push_back(current);
				}else{
					current = current-5;
					output.push_back(current);
				}
				outer = outer^1;


			}else{
				bool canReach = Reach(prev, current, outer);
				if(canReach){
					output.push_back(current);
				}
				else{
					ans= false;
					break;
				}
			}
// 			cout << prev <<" " << current <<endl;

			
		}
		if(ans){
			for(auto child: output){
				cout << child;
			}
			cout <<endl;
		}
		return ans;
}


int main(int argc, char const *argv[])
{
	int t;
	cin>> t;
	innerGraph[5] = {7,8};
	innerGraph[6] = {8,9};
	innerGraph[7] = {5,9};
	innerGraph[8] = {5,6};
	innerGraph[9] = {6,7};
	outerGraph[0] = {1,4};
	outerGraph[1] = {0,2};
	outerGraph[2] = {1,3};
	outerGraph[3] = {2,4};
	outerGraph[4] = {0,3};
	while(t--){
		string s;
		cin >>s;
		

		bool ans1 = answer(1,s);
		if(!ans1){
			bool ans2 = answer(0,s);
			if(!ans2){
				cout << "-1" <<endl;
			}
		}



		

		
	}
	return 0;
}