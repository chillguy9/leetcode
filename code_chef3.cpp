#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int count =0;
	    for(int i=0 ; i<s.size() ; i++){
            cout<<s[i]<<endl;
	        if(s[i]==1){
	            count++;
                cout<<"count="<<count<<endl;
	        }
            
            else{
	            if(count==2 && count==1){
	                cout<<"No"<<endl;
	                count = -1;
	                break;
	                
	            }
	            count=0;
	        }
	        
	        
	        
	    }
	   if(count!=-1){
	       cout<<"Yes"<<endl;
	   }
	    
	}

}
