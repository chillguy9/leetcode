#include <iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int n;
	cin>>n;
	int  prices[n];
	vector<int> ans;
	stack<int> s;
	for (int i=0;i<n;i++){
    cin>>prices[i];

	while(!s.empty() && prices[s.top()]<=prices[i]){
		s.pop();
	}
	if(s.empty()){
		ans.push_back(i+1);
	}else{
		ans.push_back(i-s.top());
	}
s.push(i);
	}
	
	for(int i : ans){
		cout<<i<<" ";
	}	
	// Writing output to STDOUT
}