#include<bits/stdc++.h>
using namespace std;

struct tree{
    int val;
    tree* left;
    tree* right;
    tree* parent;
    bool red;
    tree(int data){
        val =data;
        left= NULL;
        right= NULL;
        parent=NULL;
        red=1;
    }
};

bool check(tree* root){
    return root->red;
}

void rleft(tree *&root) {
        tree *right = root->right;
        root->right = right->left;

        if(root->right != NULL){
            root->right->parent = root;
        }

        right->parent=root->parent;

        if(root->parent==NULL){
            root = right;}
        else if(root == root->parent->left){
            root->parent->left = right;
        }
        else{
            root->parent->right = right;
        }

    right->left = root;
    root->parent = right;
}

void rright(tree *&root) {
        tree *left = root->left;
        root->left = left->right;

        if(root->left != NULL){
            root->left->parent = root;
        }

        left->parent = root->parent;

        if(root->parent == NULL){
            root = left;
        }
        else if(root == root->parent->left){
            root->parent->left = left;}
        else{
            root->parent->right = left;
        }

        left->right = root;
        root->parent = left;
    }
void func(tree *&root) {
        tree *parent = NULL;
        tree *gp = NULL;

        while((root != root)) {
                if(!root->red) break;
                if(root->parent->red) break;
            parent=root->parent;
            gp=parent->parent;

            if(parent==gp->left) {
            tree *unc=gp->right;
                if(unc&&unc->red==1) {
                    gp->red=1;
                    parent->red=0;
                    unc->red=0;
                    root=gp;
                } else{
                    if(root==parent->right) {
                        rleft(parent);
                        root=parent;
                        parent=root->parent;
                    }
                    rright(gp);
                swap(parent->red,gp->red);
                    root=parent;
                }
            } else {
                tree *unc=gp->left;

                if(unc->red){
                    gp->red=1;
                    parent->red = 0;
                    unc->red = 0;
                    root = gp;
                } else{
                    if (root==parent->left) {
                    rright(parent);
                        root=parent;
                        parent=root->parent;
                }
                    rleft(gp);
                    swap(parent->red, gp->red);
                    root = parent;
                }
            }
        }
        root->red = 0;
    }
void insert(tree *&root, int x){
        if(root==NULL){
            root=new tree(x);
            return;
        }

    if(x<root->val){
    insert(root->left, x);
    }
    else if(x>root->val){
        insert(root->right, x);
        }

    func(root);
}

void print(tree *root) {
        if (root == NULL) return;

        print(root->right);
        cout << endl;
        if(root->red==1){
            cout<<root->val<<"R"<<endl;
        }else{
            cout<<root->val<<"B"<<endl;
        }
        print(root->left);
    }

int main(){
    tree* rb;
    int arr[20];
    int n;
    cout<<"enter size of array to input";
    cin>>n;
    int i;
    cout<<"enter values"<<endl;
    for(i=0;i<n;i++){
            cout<<"value for "<<i;
            cin>>arr[i];
    }
    for(i=0;i<n;i++){
        insert(rb,arr[i]);
    }
    print(rb);
}
