#include <bits/stdc++.h>
using namespace std;
int topK(vector<int> v,int k){
    unordered_map<int, int> set;
    int max=0;
    for(auto i:v){
        set[i]++;
    }
    priority_queue<int,vector<int>,greater<int>> pri;
    for (const auto &i: set){
        pri.push(i.second);
        if (pri.size()>k) pri.pop();
    }
    int x= pri.top();
    for (const auto &i: set){
        if (i.second==x) return i.first;
    }
    return -1;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<topK(v,k);
    return 0;
}