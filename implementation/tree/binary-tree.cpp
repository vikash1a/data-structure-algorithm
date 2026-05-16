#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int x){
            val = x;
        }
};
class BinaryTree{
    public:
       
        //test method
        void test(){
            cout<<"\n _ _ _  testing started _ _ _ \n";
            // vector<int> v = {1,2,3,4,5,6,7};
            // Node* root = createBinaryTreeFromArray(v,0);
            // printInorder(root);
            // printPreorder(root);
            // printPostorder(root);

            // createPostFromPreAndIn({1,2,4,5,3,6,7},{4,2,5,1,6,3,7});

            
            cout<<"\n _ _ _  testing ended _ _ _ _ \n";
            return;
        }
        //create binary tree    
        Node* createBinaryTree(){
            Node* node = new Node(1);
            node->left = new Node(2);
            node->right = new Node(3);
            return node;
        }
        //

        //print postorder
        void printPostorder(Node* node){
            cout<<"\n - - - starting preorder trasversal - - - \n";
            printPostorderHelper(node);
            cout<<"\n - - - ending preorder trasversal - - - \n";
        }
        void printPostorderHelper(Node* node){
            if(node== NULL)return;
            printPostorderHelper(node->left);
            printPostorderHelper(node->right);
            cout<<node->val<<" ";
            return;
        }
        //

        //print preorder
        void printPreorder(Node* node){
            cout<<"\n - - - starting preorder trasversal - - - \n";
            printPreorderHelper(node);
            cout<<"\n - - - ending preorder trasversal - - - \n";
        }
        void printPreorderHelper(Node* node){
            if(node== NULL)return;
            cout<<node->val<<" ";
            printPreorderHelper(node->left);
            printPreorderHelper(node->right);
            return;
        }
        //

        //print inorder
        void printInorder(Node* node){
            cout<<"\n - - - starting inorder trasversal - - - \n";
            printInorderHelper(node);
            cout<<"\n - - - ending inorder trasversal - - - \n";
        }
        void printInorderHelper(Node* node){
            if(node== NULL)return;
            printInorderHelper(node->left);
            cout<<node->val<<" ";
            printInorderHelper(node->right);
            return;
        }
        //
        // create binary tree from array
        Node* createBinaryTreeFromArray(vector<int> v, int i){
            int nv = v.size()-1;
            if(nv+1 == 0 || i>nv)return NULL;
            Node* root = new Node(v[i]);
            root->left = createBinaryTreeFromArray(v,2*i+1);
            root->right = createBinaryTreeFromArray(v,2*i+2);
            return root;
        }
        //

        //insert a node at first position available
        // do after trasversal
        void insertNode(Node* root){
            Node* temp = root;
            return;
        }
        void insertNodeHelper(Node* root){
            return;
        }
        //

        //delete a node

        //

        //create postOrder from pre and in order
        vector<int> createPostFromPreAndIn(vector<int> pre, vector<int> in){
            vector<int> post;
            int preIn = 0;
            createPostFromPreAndInHelper(pre,in,0,in.size()-1,preIn,post);
            cout<<"\n starting post \n";
            for(int i=0;i<=post.size()-1;i++){
                cout<<post[i]<<" ";
            }
             cout<<"\n ending post \n";
            return post;

        }
        int createPostFromPreAndInSearch(vector<int> in , int k, int inStart, int inEnd){
            for(int i=inStart;i<=inEnd;i++){
                if(in[i] == k)return i;
            }
            return -1;
        }
        void createPostFromPreAndInHelper(vector<int> pre, vector<int> in, int inStart, int inEnd, int& preIn, vector<int>& post){
            if(inStart > inEnd)return;
            int rootIn = createPostFromPreAndInSearch(in,pre[preIn],inStart,inEnd);
            preIn++;
            createPostFromPreAndInHelper(pre,in,inStart,rootIn-1,preIn,post);
            createPostFromPreAndInHelper(pre,in,rootIn+1,inEnd,preIn,post);
            post.push_back(in[rootIn]);
            return;
        }

        //

};

int main(){
    cout<<"hello world\n";
    BinaryTree binaryTree;
    binaryTree.test();
    return 0;
}