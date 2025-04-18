#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>twosum( vector<int>&arr,int tar){
    unordered_map<int,int>m;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        int first=arr[i];
        int sec=tar-first;
        if(m.find(sec)!=m.end()){
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }
        m[first]=i;
    }
    return ans;

}