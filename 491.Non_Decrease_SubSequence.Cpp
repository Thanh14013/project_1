#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    function<void(int)> dfs=[&](int start){
        if (path.size()>1) res.push_back(path);       
        for (int i=start;i<nums.size();i++){
            if ((!path.empty() && nums[i]<path.back())) continue;
           
            path.push_back(nums[i]);
            dfs(i+1);
            path.pop_back();
        }
    };
    return res;
}
int main(){
    vector<int> nums={4,6,7,7};
    vector<vector<int>> res=findSubsequences(nums);
    for (auto x:res){
        for (auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}