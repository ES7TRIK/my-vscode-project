#include <iostream>
#include <vector>
using namespace std;
bool isPossible(vector<int>&arr,int m,int c,int minallowed){

    int cows = 1; 
    int lastStallPos = arr[0]; 
for (int i = 1; i < n; i++) {
if(arr[i]-laststallPos<=minAllowed){
    cows++;
    laststallPos=arr[i];
}if(cows==C)
    return false;
}
int getDistance(vector<int>&arr,int m,int c){
    sort(arr.begin(),arr.end());
    int st=1;int end=arr[N-1]-arr[0],ans=-1;
    while(st<end){
        int mid=st+(end-st)/2;
}
if(isPossible(arr,N,C,mid)){
ans=mid;
st=mid+1;
}else{
    end=mid-1;
}
}
return ans;
}