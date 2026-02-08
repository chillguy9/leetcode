#include<iostream>
#include<vector>
#include<map>
using namespace std;        
class Solution {
public:
    bool isAnagram(string s, string t) {
         sort(s.begin() , s.end());
         sort(t.begin() , t.end());
        if(s==t){
            return true;
        }
        return false;
    }
};


int main (){
    // string s, t;
    // cout << "Enter first string: ";
    // cin >> s;
    // cout << "Enter second string: ";
    // cin >> t;

    // Solution sol;
    // if (sol.isAnagram(s, t)) {
    //     cout << "The strings are anagrams." << endl;
    // } else {
    //     cout << "The strings are not anagrams." << endl;
    // }
    // cout<<'b'-'a'<<endl;
    
    // int arr[1]={0};
    // arr[0]++;
    // cout<<arr[0]<<endl;
    // string a="anagram";
    // for(auto i : a){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<int> freq(26, 0);
    map<vector<int>, vector<int>> mp;
    int idx = 0;
    for(auto i : strs){
         for( char j : i){
          freq[j-'a']++;

         }
         mp[freq].push_back(idx);
         freq.clear();
         idx++;
         }


    return 0;
}