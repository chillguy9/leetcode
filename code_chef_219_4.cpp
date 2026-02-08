#include <iostream>
using namespace std;

int main() {
	// your code goes here
    int t;
    cout<<"enter :";
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        if(n<=2) cout<<-1<<endl;
        
        else{
        
            int k=n-3;
            
            for(int i=0 ; i<n; i++){
                for(int j=0 ; j<n ; j++){
                    if(j==n-1 ){
                     if(k==0)  cout<<1<<" ";
                     else cout<<0<<" ";   
                    
                    }
                    else if(i==0) cout<<1<<" ";
                    else if(j==n-2) cout<<1<<" ";
                    else cout<<0<<" ";
                    
                }
                if(k>0)k--;
                cout<<endl;
            }
            
         
         
         
            
        
        }
        
    }
}
