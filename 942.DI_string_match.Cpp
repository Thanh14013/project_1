#include <bits/stdc++.h>
using namespace std;
vector<int> diStringMatch(string S) {
    int n=S.size();
    vector<int> res;
    int left=0,right=n;
    for (int i=0;i<n;i++){
        if (S[i]=='I') res.push_back(left++);
        else res.push_back(right--);
    }
    res.push_back(left);
    return res;
}