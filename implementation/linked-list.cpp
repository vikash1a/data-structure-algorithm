#include <bits/stdc++.h>
using namespace std;

class DoubleNode{
    public:
        int val;
        DoubleNode* next;
        DoubleNode* prev;
        DoubleNode(int x){
            val = x;
        }
        DoubleNode* addStart(DoubleNode* node, int x){
            DoubleNode* newNode = new DoubleNode(x);
            newNode->next = node;
            node->prev = newNode;
            return newNode;
        }
        DoubleNode* addEnd(DoubleNode* node, int x){
            DoubleNode* newNode = new DoubleNode(x);
            DoubleNode* ans = node;
            while(node->next!=NULL){
                node = node->next;
            }
            node->next = newNode;
            newNode->prev = node;
            return ans;
        }
        void print(DoubleNode* node){
            while(node!=NULL){
                cout<<node->val<<" ";
                node=node->next;
            }
            cout<<endl;
            return;
        }
};

class Node
{
    public:
        int val;
        Node* next;
        Node(int x){
            val = x;
            next = NULL;
        }
};
void addNode(Node* node,Node* nodeToBeAdded){
    node->next = nodeToBeAdded;
    return;
}
void addNode(Node* node,int nodeToBeAdded){
    node->next = new Node(nodeToBeAdded);
    return;
}
void deleteNode(Node* node, Node* nodeTobeDeleted){
    while(node!=NULL){
        if(node->next == nodeTobeDeleted){
            node->next = node->next->next;
            return;
        }
        node = node->next;
    }
    return;
}
void print(Node* node){
    while(node!=NULL){
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<endl;
    return;
}


int main()
{
    cout<<"Hello World\n";

    // Node* node = new Node(0);
    // addNode(node,new Node(1));
    // addNode(node->next,2);
    // print(node);
    // deleteNode(node,node->next);
    // print(node);

    DoubleNode* doubleNode = new DoubleNode(1);
    doubleNode = doubleNode->addStart(doubleNode,0);
    doubleNode =doubleNode->addEnd(doubleNode,2);
    doubleNode =doubleNode->addStart(doubleNode,-1);
    doubleNode =doubleNode->addEnd(doubleNode,3);
    doubleNode->print(doubleNode);

    return 0;
}