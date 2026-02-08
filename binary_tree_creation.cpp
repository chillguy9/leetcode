#include<iostream>
#include<queue>
using namespace std;

queue<int> num;

class node{

  public:

  int data;
  node* left;
  node* right;

  node(int x){
  data=x;
  left=right=nullptr;
 }
};

class bt{
  

    public:
    
    node* creation(){
    
    
     
    queue<node*> q;

    node* root = new node(num.front());
    num.pop();

    q.push(root);

    while(!num.empty()){

    node* curr = q.front();
    q.pop();
    
    curr->left= new node(num.front());
    num.pop();
    
    if(!num.empty()){
    curr->right = new node(num.front());
    num.pop();
    }
    q.push(curr->left);
    q.push(curr->right);
    }
cout<<"binary tree is created succesfully..\n";
return root;

  }


void pre(node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

void in(node* root){
    if(root==nullptr) return;
    
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}

void post(node* root){
    if(root==nullptr) return;
    
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}

void level_order(node* root){
   

    queue<node*> q;
    
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){

    node* curr=q.front();
    q.pop();
    if(curr==nullptr){
    if(q.empty()){
       cout<<"\n";
        break;
    }else{
        q.push(nullptr);
        cout<<"\n";
        continue;
        }
    }

    cout<<curr->data<<" ";

    if(curr->left!=nullptr){
        q.push(curr->left);
    }
    if(curr->right != nullptr){
        q.push(curr->right);
    }

    }


}



  




};


int main(){

int a;

cout<<"enter count of tree : ";
cin>>a;
int x;
cout<<"enter elements in tree :\n";
for(int i=0 ; i<a ; i++){
    cin>>x;
    num.push(x);
}



bt t1;

node* root = t1.creation();
t1.pre(root);cout<<endl;
t1.in(root);cout<<endl;
t1.post(root);cout<<endl;
t1.level_order(root);cout<<endl;

}