#include<iostream>
using namespace std;



vector<int> prev_smaller_element(vector<int>& nums){


  vector<int> ans;
  stack<int> st;

  for(int i=0;i<nums.size();i++){
   
    while(!st.empty() && st.top()>=nums[i]){
   st.pop();
    }

    if(st.empty()) ans.push_back(-1);
    else ans.push_back(st.top());

    st.push(nums[i]);

  }

return ans;


}





int main(){

vector<int> temp={1,2,0,-1,5,6,1};
//-1,1,-1,-1,-1,5,-1
vector<int> ans = prev_smaller_element(temp);

for(int x : ans) cout<<x<<" ";



}