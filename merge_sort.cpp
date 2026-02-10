#include<iostream>
#include<vector>
using namespace std;

void merge_sort(int i , int j , vector<int>& arr){

     
   if(i>=j) return;
   int mid = i + (j-i)/2;
   merge_sort(i,mid,arr);
   merge_sort(mid+1,j,arr);


   vector<int> temp;

   int st1=i;
   int st2=mid+1;

   while(st1<=mid && st2<=j){
    if(arr[st1]<arr[st2]){
        temp.push_back(arr[st1]);
        st1++;
    }else{
        temp.push_back(arr[st2]);
        st2++;
    }
   }

   while(st1<=mid){
    temp.push_back(arr[st1]);
    st1++;
   }
   while(st2<=j){
    temp.push_back(arr[st2]);
    st2++;
   }

   for(int m=0;m<temp.size();m++){
    arr[i+m]=temp[m];
   }

}


int main(){


 vector<int> arr = {4,2,5,5,1,0,1,6};

 merge_sort(0,7,arr);
 for(int x : arr) cout<<x<<" ";

}