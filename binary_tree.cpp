#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;


node(int value){
    data = value;
    left=right=NULL;
}
};

class tree{
    int  idx=-1;


    public:


    node* buildTree(vector<int> &arr){
     idx++;
     if(arr[idx]==-1) return NULL;

     node* root = new node(arr[idx]);

     root->left = buildTree(arr);
     root->right = buildTree(arr);


    return root;

    }

    

    void preOrder(node* root){
    
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    }

    void inOrder(node* root){
    
    if(root==NULL){
        return;
    }
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    }

    void postOrder(node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    }

    void level(node* root){
    
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
    
   

    node* temp= q.front();
     q.pop();
    if(temp==NULL){

    if(q.empty()){
        break;
    }else{
        cout<<endl;
        q.push(NULL);
        continue;
    }


    }

    cout<<temp->data<<" ";
   

    if(temp->left != NULL){
    q.push(temp->left);
    }
    if(temp->right != NULL){
    q.push(temp->right);
    }
  }


    }

    int height(node* root){

    if(root==NULL) return 0;

    int leftht = height(root->left);
    int rightht = height(root->right);

    return max(leftht , rightht) + 1;

   }

   int count(node* root){
   if(root==NULL) return 0;

   int leftcount = count(root->left);
   int rightcount = count(root->right);



   return leftcount + rightcount + 1;

   }

   int sum(node* root){
   if (root==NULL) return 0;

   int leftSum = sum(root->left);
   int rightSum = sum(root->right);


   return leftSum + rightSum + root->data;

}

int maxNode(node* root){

  if(root==NULL) return 0;

  int leftmax = maxNode(root->left);
  int rightmax = maxNode(root->right);


  return max(max(leftmax , rightmax) , root->data);

}

int minNode(node* root){

  if(root==NULL) return INT_MAX;

  int leftmin= minNode(root->left);
  int rightmin = minNode(root->right);


  return min(min(leftmin , rightmin) , root->data);

}


void topviwe(node* root){

    queue<pair<node* , int>> q;
    q.push({root , 0});

    map<int,int> mp;
     
    while(!q.empty()){

    node* curr = q.front().first;
    int idx = q.front().second;

    if(mp.find(idx)==mp.end()){
        mp[idx]=curr->data;
    }

    q.pop();
    

    if(curr->left != nullptr){
        q.push({curr->left , idx -1});
    }
    if(curr->right !=nullptr){
        q.push({curr->right , idx+1});
    }

    }
 
cout<<"top viwe : ";
for(auto it : mp){
    cout<<it.second<<" ";
}

}

void bottom_viwe(node* root){

    queue<pair<node*,int>> q;

    q.push({root,0});

    map<int,int> mp;

    while(!q.empty()){

   node* curr = q.front().first;
   int idx = q.front().second;

   q.pop();

   mp[idx]=curr->data;

   if(curr->left != NULL){
    q.push({curr->left , idx-1});
   }
   if(curr->right != NULL){
    q.push({curr->right , idx+1});
   }


    }


 cout<<"bottom viwe : ";
    for(auto it : mp){

        cout<< it.second<<" ";
    }

}


void kth_level(node* root , int k){

    if(k==1 && root != NULL){
        cout<<root->data<<" ";
        return;
    }
    if(root==NULL) return;
    
    kth_level(root->left , k-1);
    kth_level(root->right , k-1);

}




   
    

};

int main(){

    cout<<"enter array :"<<endl;
    cout<<"enter  -13 to stop \n";

    vector<int> arr;
   int a;
    do{
    cin>>a;
    if(a!=-13){
    arr.push_back(a);
    }
    }while(a!=-13);


    tree t1;

   node* root = t1.buildTree(arr);
   t1.preOrder(root);cout<<endl;
   t1.inOrder(root);cout<<endl;
   t1.postOrder(root);cout<<endl;
   t1.level(root);cout<<endl;
   cout<<"height :"<<t1.height(root)<<endl;
   cout<<"count :"<<t1.count(root)<<endl;
   cout<<"sum :"<<t1.sum(root)<<endl;
   cout<<"max :"<<t1.maxNode(root)<<endl;
   cout<<"min :"<<t1.minNode(root)<<endl;
   t1.topviwe(root);cout<<endl;
   t1.bottom_viwe(root);cout<<endl;
   cout<<"kth level of tree : ";
   t1.kth_level(root , 3);cout<<endl;
}

//123-1-14-1-19-1-1
//12349
//12934

// 1234-1-1-15-1-16-17-1-1
/*16-17
25
3
4 */