#include<iostream>

using namespace std;
class expresion{

    public:
    int pri(char a){
    
     if(a=='^'){
        return 4;
    }else if(a=='*' || a=='/'){
        return 3;
    }else if (a=='+' || a=='-') {
        return 2;
    }else{
        return 1;
    }
   


    }


    string infix_to_postfix(string str){
    
    vector<char> st;
    string ans="";

    for(int i=0 ; i<str.size() ; i++){
     if(str[i]==')'){
    while(st[st.size()-1]!='('){
    
ans=ans+st[st.size()-1];
st.pop_back();

    }
    st.pop_back();
     }else if(str[i]==']'){


    while(st[st.size()-1]!='['){
    
ans=ans+st[st.size()-1];
st.pop_back();
    }
    st.pop_back();

     }else if(str[i]>='a' && str[i]<='z'){
       ans=ans+str[i];
     }else{
        if(str[i]=='(' || str[i]=='['){
            st.push_back(str[i]);
        }else{
     while(!st.empty() && (pri(st[st.size()-1])>=pri(str[i]))){
     ans=ans+st[st.size()-1];
     st.pop_back();
     }
     st.push_back(str[i]);
   
 }
}
  
 }
 while(!st.empty()){
    ans=ans+st[st.size()-1];
    st.pop_back();
 }


return ans;
    }


void evaluation(){
cout<<"enter expresion :";
string expresion;
cin>>expresion;
int num1,num2;
expresion = infix_to_postfix(expresion);
cout<<"post_fix expresion :"<<expresion;
  int a;
  cout<<endl;
  cout<<"enter number of oprend :";
  cin>>a;
  float arr[a];
  
  vector<float> st;
  for(int i=0 ; i<a ; i++){
cout<<"enter value of ["<<char('a'+i)<<"] :";
cin>>arr[i];
}


for(int i=0 ; i<expresion.size() ; i++){
if(expresion[i]<'a' || expresion[i]>'z'){
 num1=st[st.size()-1];st.pop_back();
 num2=st[st.size()-1];st.pop_back();

    switch (expresion[i])
    {
    case '+': st.push_back(num1+num2);break;
    case '-': st.push_back(num2-num1);break;
    case '*': st.push_back(num2*num1);break;
    case '/': st.push_back(num2/num1);break;
    case '^': st.push_back(pow(num2,num1));break;
        
    }
}else{
  st.push_back(arr[expresion[i]-'a']);

}





}



cout<<"evaluation of expresion is :"<<st[0];

    }



};
int main(){

 expresion obj;
obj.evaluation();




}