#include <bits/stdc++.h>
using namespace std;
bool validPalindrome(string s){
    int i=0,j=s.size()-1;
    function<bool(string,int,int)> isPalindrome=[&](string s,int i,int j){
        while(i<j) if(s[i++]!=s[j--]) return false;
        return true;
    };
    while(i<j){
        if(s[i]!=s[j]) return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
        i++,j--;
    }
    return true;
}
int main(){
    cout<<validPalindrome("abccda")<<endl;
    cout<<validPalindrome("abca")<<endl;
    return 0;
}