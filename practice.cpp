#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>mergesortedarray(vector<int>&arr1,vector<int>&arr2){
    int n=arr1.size(),m=arr2.size();
    vector<int>merged;
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j])
        merged.push_back(arr1[i++]);
        else
        merged.push_back(arr2[j++]);
    }
    while(i<n)
    merged.push_back(arr1[i++]);
    merged.push_back(arr2[j++]);
    return merged;
}