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
Treenode* CBT(vector<int> preorder,vector<int> inorder){
    if (inorder.size()==0) return NULL;
    int s= preorder.size();
    int d=0;
    Treenode* root=new Treenode(preorder[0]);
    for (int i=0;i<s;i++){
        if (preorder[0]==inorder[i]) d=i;
    }
    vector<int> inoleft,preoleft,inoright,preoright;
    for (int i=0;i<d;i++){
        inoleft.push_back(inorder[i]);
        preoleft.push_back(preorder[i+1]);
    }
    for (int i=d+1;i<s;i++){
        inoright.push_back(inorder[i]);
        preoright.push_back(preorder[i]);
    }
    root->left=CBT(preoleft,inoleft);
    root->right= CBT(preoright, inoright);
    return root;
}
