#include<iostream>
using namespace std;
void mearge(int arr[] , int st , int mid , int end){
    int i=st;
    int j=mid+1;
    int k=0;
    int b[end-st+1];
    while(i<=mid && j<=end){

        if(arr[i]>=arr[j]){
        b[k]=arr[j];
        k++;
        j++;
        }else{
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=arr[i];
        k++;i++;
    }
    while(j<=end){
        b[k]=arr[j];
        j++;k++;
    }
    k=0;
    for (int m=st; m<=end ; m++){
        arr[m]=b[k];
        k++;
    }


}

void mearge_sort(int arr[],int st, int end){
if(st>=end){
    return;
}
    int mid=(st+end)/2;

    mearge_sort(arr , st , mid);//left half
    mearge_sort(arr , mid+1 , end);//right half
    mearge(arr , st , mid , end);



}
int main(){


int arr[10] = {4,4,3,21,-1,34,-1,78,0,-1};

mearge_sort(arr,0,9);

for(int i=0 ; i<10 ; i++){
    cout<<arr[i]<<" ";
}

}