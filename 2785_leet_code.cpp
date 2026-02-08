#include<iostream>
using namespace std;

    string sortVowels(string s) {
        vector<char> a(s.length() , '0');
        vector<char> yes;
         for(int i=0 ; i<s.size() ; i++){
           if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){

            yes.push_back(s[i]);
           }
           else{
            a[i] = s[i];
           }
           } 
           sort(yes.begin() , yes.end());
           int j=0;
           for( int i=0 ; i<s.size() ; i++){
            if(a[i]=='0'){
                a[i]=yes[j];
                j++;
            }
           }
           string ans="";
           for(char i : a){
            ans=ans+i;
           }
           return ans ; 
    }
int main(){
    cout<<sortVowels("");
}