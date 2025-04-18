#include <iostream>
#include <vector>
using namespace std;
int maxprofit (vector<int>& arr){
    int maxprofit=0,bestbuy=prices[0];
    for(int i=0;i<n;i++){
        if(prices[i]<bestbuy){
            maxprofit=max(maxprofit,prices[i]-bestbuy);
        }else{
  bestbuy=prices[i];
}
        }
        return maxprofit;
    }
    int  main(){
        int n;
        cout<<"Enter the length of the stock prices";
        cin>>n;
        vector<int>prices(n)
        cout"Enter the stock prices"<<endl;
        for(int i=0i<n;i++){
            cin>>prices[i];
        }
    }
