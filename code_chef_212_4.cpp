#include <iostream>
using namespace std;

int main(){
	// your code goes here
int t;
cin>>t;
while(t--){
    int n ;
    cin>>n;
    string str;
    cin>>str;

int ones=0;
int zeros=0;
int ans=0;
for(int i=1 ; i<n ; i++){
    if(str[i]=='1' && str[i-1]=='1') ones++;
    else if(str[i]=='0' && str[i-1]=='0') zeros++;
    }
    cout<<zeros<<" "<<ones<<endl;
    
    if(ones<zeros) {
      for(int i=1 ; i<n-1 ; i++){
    if(str[i]=='0' && str[i-1]=='0' && str[i-1]=='0') {
        str[i]='1';
        zeros-=2;
        ans++;
         cout<< i<<" "<<zeros<<" "<<ones<<endl;
         }
        if(ones>=zeros)  break;
    }
  }
  if(ones<zeros){
      for(int i=1 ; i<n ; i++){
          if(str[i]=='0' && str[i-1]=='0'){
              str[i]='1';
              ans++;
              zeros--;
              cout<<zeros<<" "<<ones<<endl;
          }
          if(ones>=zeros) break;
      } 
  }
  cout<<ans<<endl;
    }
}