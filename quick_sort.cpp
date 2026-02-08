#include<iostream>
using namespace std;

int partetion(int arr[] , int st , int end){
    int pivot = arr[end];
    int index=st-1;
    int j=st;
    while(j<=end){
    if(arr[j]<=pivot){

        index++;
        swap(arr[index] , arr[j]);
    }
j++;

    }
     index++;
        swap(arr[index] , arr[end]);

return index;

}