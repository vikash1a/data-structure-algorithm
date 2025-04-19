#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int x){
            val = x;
        }
        void printInOrder(Node* node){
            if(node==NULL)return;
            printInOrder(node->left);
            cout<<node->val<<" ";
            printInOrder(node->right);
            return;
        }
        Node* search(Node* node , int k){
            if(node == NULL || node->val == k)return node;
            if(node-> val < k){
                return search(node->right, k);
            }
            return search(node->left, k);
        }
        void insert(Node* node, int k){
            if(node==NULL)return;
            if(node->left == NULL && node->right == NULL){
                if(k<node->val){
                    node->left = new Node(k);
                    return;
                }
                else{
                    node->right = new Node(k);
                    return;
                }
            }
            else{
                if(k<node->val){
                    insert(node->left,k);
                }
                else insert(node->right,k);
            }
            return;
        }
        //delete node
        Node* deleteNode(Node* node, int k){
            if(node==NULL)return NULL;
            if(node->val < k){
                node->right = deleteNode(node->right,k);
            }
            else if(node->val > k){
                node->left = deleteNode(node->left,k);
            }
            else{
                if(node->left == NULL && node->right == NULL)return NULL;
                else if(node->left == NULL){
                    Node* temp = node->right;
                    free(node);
                    return temp;
                }
                else if(node->right == NULL){
                    Node* temp = node->left;
                    free(node);
                    return temp;
                }
                else{
                    Node* temp = searchInOrderFirst(node);
                    node->val = temp->val;
                    node->right = deleteNode(node->right,temp->val);
                }
            }
            return node;
        }
        Node* searchInOrderFirst(Node* node){
            if(node->left==NULL)return node;
            return searchInOrderFirst(node->left);
        }
        //
        //construct tree from pre order trasversal
        Node* constructTree(Node* node, vector<int> preOrder){
            int np = preOrder.size()-1;
            Node* root = new Node(preOrder[0]);
            stack<Node*> st;
            st.push(root);
            for(int i = 1; i<=np; i++){
                Node* temp = NULL;
                while(!st.empty() && preOrder[i] > st.top()->val){
                    temp = st.top();
                    st.pop();
                }
                if(temp == NULL){
                    st.top()->left = new Node(preOrder[i]);
                    st.push(st.top()->left );
                }
                else{
                    temp->right = new Node(preOrder[i]);
                    st.push(temp->right);
                }
            }
            return root;
        }
        void preOrder(Node* node,vector<int>& ans){
            if(node == NULL)return ;
            ans.push_back(node->val);
            preOrder(node->left,ans);
            preOrder(node->right,ans);
            return;
        }
        //
        //binary tree to binary search tree
        void inOrder(Node* node, vector<int>& inOrderV){
            if(node == NULL)return;
            inOrder(node->left,inOrderV);
            inOrderV.push_back(node->val);
            inOrder(node->right,inOrderV);
            return;
        }
        Node* convertBtToBst(Node* node){
            vector<int> inOrderV;
            inOrder(node,inOrderV);
            sort(inOrderV.begin(), inOrderV.end());
            int k =0;
            populate(node,inOrderV,k);
            return node;
        }
        void populate(Node* node, vector<int> inOrderV, int& k){
            if(node==NULL)return;
            populate(node->left,inOrderV,k);
            node->val = inOrderV[k++];
            populate(node->right,inOrderV,k);
            return;
        }
        //
};

//sorted linked list to bst
namespace linkedListToBst
{
    class LinkedNode{
        public:
            int val;
            LinkedNode* next;
            LinkedNode(int x){
                val = x;
            }
    };
    
    int countSize(LinkedNode* linkedNode){
        int count =0;
        while(linkedNode!=NULL){
            count++;linkedNode = linkedNode->next;
        }
        return count;
    }
    Node* helper( LinkedNode** linkedNode, int n){
        if(n<=0)return NULL;
        Node* left = helper(linkedNode,n/2);
        Node* root = new Node((*linkedNode)->val);
        root->left = left;
        (*linkedNode) = (*linkedNode)->next;
        Node* right = helper(linkedNode,n-n/2-1);
        root->right = right;
        return root;
    }
    Node* convertLinkedListToBst(LinkedNode* linkedNode){
        int n = countSize(linkedNode);
        Node* root = helper(&linkedNode,n);        
        return root;
    }
    void test(){
        LinkedNode* linkedNode = new LinkedNode(1);
        LinkedNode* temp = linkedNode ;
        temp->next = new LinkedNode(2);temp = temp->next;
        temp->next = new LinkedNode(3);temp = temp->next;
        temp->next = new LinkedNode(4);temp = temp->next;
        temp->next = new LinkedNode(5);temp = temp->next;
        temp->next = new LinkedNode(6);temp = temp->next;

        Node* root = convertLinkedListToBst(linkedNode);
        root->printInOrder(root);
    }
}

int main()
{
    cout<<"Hello World from Main\n";

    // Node* node = new Node(10);
    // node->left  = new Node(8);
    // node->right  = new Node(15);
    // node->printInOrder(node);
    // Node* searched = node->search(node,15);
    // cout<<"searched->val "<<searched->val<<endl;

    // node->insert(node,2);
    // node->insert(node,20);
    // node->insert(node,50);
    // node->insert(node,12);
    // node->insert(node,32);
    // node->printInOrder(node);cout<<"\n";

    // node->deleteNode(node,20);
    // node->printInOrder(node);cout<<"\n";

    // vector<int> preOrder;
    // node->preOrder(node,preOrder);
    // Node* constructedNdoe = node->constructTree(node,preOrder);
    // node->printInOrder(constructedNdoe);cout<<"\n";

    // Node* bt = new Node(10);
    // bt->left = new Node(30);
    // bt->right = new Node(15);
    // bt->left->left = new Node(20);
    // bt->right->right = new Node(5);

    // Node* bst = node->convertBtToBst(bt);
    // node->printInOrder(bt);cout<<"\n";
    // node->printInOrder(bst);cout<<"\n";

    linkedListToBst::test();
    return 0;
}