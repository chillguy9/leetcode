#include <iostream>
using namespace std;

 bool isprime(int x){
     if(x==1){
         return false;
     }
     for(int i=2 ; i<x ; i++){
         if(x%i==0){
             return false;
         }
     }
     return true;
 }
int main() {

  int t;
  cin>>t;
  while(t--){
      
      
      int n;
      cin>>n;
      int arr[n];
      for(int i=0 ; i<n ; i++){
          cin>>arr[i];
      }
      int ans=0;
      for(int i=0;i<n-1 ; i++){
          for(int j = i+1 ; j<n ; j++){
              if(isprime(arr[i]+arr[j])){
                  ans++;
              }
          }
      }
      cout<<ans<<endl;
  }
}
