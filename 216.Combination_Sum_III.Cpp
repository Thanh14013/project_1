#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> combinationSum3(int k,int n){
    vector<vector<int>> res;
    vector<int> path;
    function<void(int,int)> dfs=[&](int k,int n){
        if (k==0){
            if (n==0){
                res.push_back(path);
            }
            return;
        }
        for (int i=path.empty()?1:path.back()+1;i<=9;i++){
            if (i>n) break;
            path.push_back(i);
            dfs(k-1,n-i);
            path.pop_back();
        }
    };
}