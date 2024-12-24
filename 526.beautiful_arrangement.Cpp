#include <bits/stdc++.h>
using namespace std;
int countArrangement(int n){
    vector<int> visited(n+1,0);
    int count=0;
    function<void(int)> backtrack=[&](int index){
        if(index>n){
            count++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==0 && (i%index==0 || index%i==0)){
                visited[i]=1;
                backtrack(index+1);
                visited[i]=0;
            }
        }
    };
    backtrack(1);
    return count;
}