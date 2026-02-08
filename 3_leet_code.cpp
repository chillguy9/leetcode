//medium of two sorted array 
// binary search in sorted array
#include <iostream>
#include <vector>
using namespace std;

double findMediun(vector<int>& nums1 , vector<int>& nums2){

int n = nums1.size();
int m = nums2.size();

if(n>m) return findMediun(nums2,nums1);

int left = (n + m + 1)/2;
int st=0;
int end=n;
while(st<=end){
  int mid1 = st + (end-st)/2;
  int mid2 = left - mid1;

  int l1 = INT_MIN;
  int l2 = INT_MIN;
  int r1 = INT_MAX;
  int r2 = INT_MAX;

  if(mid1!=n) r1 = nums1[mid1];
  if(mid2!=m) r2 = nums2[mid2];
  if(mid1!=0) l1 = nums1[mid1-1];
  if(mid2!=0) l2 = nums2[mid2-1];

  
if(l1<=r2 && l2<=r1){
    if((n+m)%2==1) return (double)max(l1,l2);
    return ((double)max(l1,l2) + (double)min(r1,r2)) / 2.0;
}
if(l1>r2) end = mid1-1;
else st = mid1+1;

}

return 0;
}