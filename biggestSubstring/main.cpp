#include <iostream>
#include <map>
#include <string>
using namespace std;

string findBiggestSubstring(string myStr);
int main(){
    string myStr;
    cout<< "Enter a string:";
    cin>>myStr;
    string resStr = findBiggestSubstring(myStr);
    cout<<"Biggest substring is "<<resStr<< " with length:"<< resStr.length();
    return 0;
}
string findBiggestSubstring(string myStr){
    int start=0;
    string biggestSubstrNoDup;
    map<char, int> strCharsOccur;
    for(int end =0; end<myStr.length(); end++){
        strCharsOccur[myStr[end]]++;
        while(strCharsOccur[myStr[end]]>1 ){
            strCharsOccur[myStr[start]]--;
            start+=1;
          
        }
      
    
        
        int biggestSubstrNoDupLen = max(myStr.substr(start,end-start+1).length(), biggestSubstrNoDup.length());
        if(biggestSubstrNoDup.length()<myStr.substr(start,end-start+1).length()){
            biggestSubstrNoDup = myStr.substr(start,end-start+1);
        }
       
    }
    return biggestSubstrNoDup;

}