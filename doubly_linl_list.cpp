#include<iostream>
using namespace std;
class node{

public:
int data;
node* next;
node* prv;

node(int x){
    data =x;
    next = nullptr;
    prv = nullptr;
}
};
class dll{
 node* head = nullptr;
 node* tail = nullptr;
 
 public:

  void push_back(int x){
    node* temp = new node(x);

    if(head == nullptr){
   tail = head = temp ;
    }
    else{
    temp->prv = tail;
    tail->next = temp;
    tail = temp;

    }
}
void pop_back(){

    node* temp = tail;
    tail = tail->prv;
    tail->next = nullptr;
    temp->prv = nullptr;
    delete temp;
   
     
}
void insert(int idx , int x){
int i=0;

node* temp = new node(x);
node* me = head;
while(i< idx-1){
    if(me == nullptr){
        cout<<"invalid "<<endl;
        return;
    }
me = me->next;

i++;
}
temp->next=me->next;
temp->prv = me;
me->next = temp;
temp->next->prv = temp;

}

void display(){
    node* temp = head;
    while(temp!=nullptr){
cout<<temp->data<<" ";
temp = temp->next;
    }
}


};
int main(){

dll ll;

ll.push_back(1);
ll.push_back(2);
ll.push_back(3);
ll.push_back(5);
ll.insert(3,4);

//ll.pop_back();
ll.display();

}
