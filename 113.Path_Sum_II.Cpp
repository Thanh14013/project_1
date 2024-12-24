#include <bits/stdc++.h>
using namespace std;
struct Treenode{
    int val;
    Treenode* left;
    Treenode* right;
    Treenode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
vector<vector<int>> pathSum(Treenode* root, int sum){
    vector<vector<int>> res;
    vector<int> path;
    function<void(Treenode*,int)> dfs=[&](Treenode* node,int sum){
        if (!node) return;
        path.push_back(node->val);
        sum-=node->val;
        if (!node->left&&!node->right&&sum==0){
            res.push_back(path);
        }
        dfs(node->left,sum);
        dfs(node->right,sum);
        path.pop_back();
    };
    dfs(root,sum);
    return res;
}
int main(){
    Treenode* root=new Treenode(5);
    root->left=new Treenode(4);
    root->right=new Treenode(8);
    root->left->left=new Treenode(11);
    root->left->left->left=new Treenode(7);
    root->left->left->right=new Treenode(2);
    root->right->left=new Treenode(13);
    root->right->right=new Treenode(4);
    root->right->right->left=new Treenode(5);
    root->right->right->right=new Treenode(1);
    vector<vector<int>> res=pathSum(root,22);
    for (auto x:res){
        for (auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}