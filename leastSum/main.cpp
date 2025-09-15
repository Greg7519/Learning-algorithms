#include<stdio.h>
#include <bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

vector<int>nums = {5,2,3,5,5};

pair<int,int> minSubArr(vector<int> numArr, int targetSum);
int main(){
    pair<int,int> resPair = minSubArr(nums,10);
    if(resPair.second==0){
        cout<<"Sum not found";
    }
    else{
        cout<<"Length is: "<<resPair.second<< "\n";
        cout<<"Elements are:";
        for(int i=resPair.first; i<resPair.first +resPair.second; i++){
            cout<<nums.at(i)<<" ";
        }
        
    }
   
    
}
pair<int,int> minSubArr(vector<int> numArr, int targetSum){
    int sum=0;
    int start=0;
    int endL=0;
    int arrStart =0;
    int minLength = INT_MAX;
    vector<int> minSumArr;
    pair<int,int> resPair;
    for( endL=0; endL< numArr.size(); endL++){
     
     
        sum+=numArr.at(endL);
        while(sum>targetSum){
            sum= sum - numArr.at(start);
            start++;
            
        }
        if(sum==targetSum && (endL- start + 1<minLength)){
            arrStart = start;
            
            minLength=endL-start+1;
        }
    
       

    }
    if(sum==targetSum){
        minSumArr.insert(minSumArr.begin(), numArr.begin()+arrStart, numArr.begin()+arrStart+minLength);
        resPair = {start,minLength};
        return resPair;
    }

    vector<int> emptyArr = {};
    return resPair = {0,0};
    
    
}