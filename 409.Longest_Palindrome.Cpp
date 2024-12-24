#include <bits/stdc++.h>
using namespace std;
int longestPadromelin(string s){
    unordered_map<char,int> m;
    for(char c:s) m[c]++;
    int res=0;
    for(auto i:m){
        res+=i.second/2*2;
        if(res%2==0 && i.second%2==1) res++;
    }
    return res;
}