#include <iostream>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        //string a= "";
        //string b = "";
       // string ans = "";
       int ans=0;
       //int eual = -1;
        for (int i=0 ; i<s.size()-1 ; i++){
         //a=a+s[i];
        // b=s[s.size()-1-i]+b;
        //  cout<<"a="<<a<<endl;
        //  cout<<"b="<<b<<endl;
         if(s.substr(ans,i+1)==s.substr(s.size()-1-i ,i+1 )){
            ans=i+1;
            
         }


        }
       if (ans == 0 && s[0]!=s[s.size()-1]){
        return "";
       }
        return s.substr(0,ans);
       
    }
};
int main() {
    Solution s;
   string str="level";
    
    cout << "Longest Prefix-Suffix: " << s.longestPrefix(str) << endl;
    return 0;
}