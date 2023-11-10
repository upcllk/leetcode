#include <bits/stdc++.h>

using namespace std;

struct treeNode{
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int x): val(x), left(NULL), right(NULL){}
};

treeNode* buildTree(){
    int num;
    cin >> num;

    if(!num){return nullptr;}

    treeNode *root=new treeNode(num);

    root->left=buildTree();
    root->right=buildTree();

    return root;
}

treeNode* findVal(treeNode *root,treeNode *target){
    if(root==nullptr || target == nullptr || &root == &target){return nullptr;}

    if(root->left==target||root->right==target){return root;}

    treeNode *left_res=findVal(root->left,target);
    if(left_res!=nullptr){return left_res;}
    
    return findVal(root->right,target);
}

void getPreOrder(treeNode* root) {
    if(root == nullptr) {
        cout << 0 << " ";
        return;
    }
    cout << root->val << " ";
    getPreOrder(root->left);
    getPreOrder(root->right);
}

int main(){
    treeNode *root=buildTree();
    
    int num,target;
    cin>>num;

    while(num){
        cin>>target;
        
        treeNode *Tar=new treeNode(target);
        treeNode *res=findVal(root,Tar);

        if(res==nullptr){cout<<"0"<<endl;}
        else{cout<<res->val<<endl;}

        num--;
    }

    return 0;

}