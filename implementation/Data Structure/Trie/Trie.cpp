#include<bits/stdc++.h>
using namespace std;

class Node{
    private:
        int countEndWith = 0;
        int countPrefix = 0;
        vector<Node*> nodeV;
       
    public:
        Node(){
            nodeV = vector<Node*>(26,NULL);
        }
        bool containsKey(char c){
            return nodeV[c-'a']!=NULL;
        }
        void put(Node* node,char c){
            nodeV[c-'a']=node;
            return;
        }
        Node* get(char c){
            return nodeV[c-'a'];
        }
        void incrementCountEnWith(){
            countEndWith+=1;
        }
        void decrementCountEnWith(){
            countEndWith-=1;
        }
        int getCountEndWith(){
            return countEndWith;
        }
        int getCountPrefix(){
            return countPrefix;
        }
        void incrementCountPrefix(){
            countPrefix+=1;
        }
        void decrementCountPrefix(){
            countPrefix-=1;
        }

};

class Trie{
    private:
        Node* root;
       
    public:
        Trie(){
            root = new Node();
        }
        void insertWord(string word){
            Node* node = root;
            for(char c : word){
                if(!node->containsKey(c)){
                    node->put(new Node(),c);
                }   
                node = node->get(c);
                node->incrementCountPrefix();
                
            }
            node->incrementCountEnWith();
        }
        int countSearchWord(string word){
            Node* node = root;
            for(char c : word){
                if(node->containsKey(c)){
                    node = node->get(c);
                }   
                else return 0;
            }
            return node->getCountEndWith();
        }
        int countStartsWithWord(string word){
            Node* node = root;
            for(char c : word){
                if(node->containsKey(c)){
                    node = node->get(c);
                }   
                else return 0;
            }
            return node->getCountPrefix();
        }
        void eraseWord(string word){
            Node* node = root;
            for(char c : word){
                if(node->containsKey(c)){
                    node = node->get(c);
                    node->decrementCountPrefix();
                }   
                else return;
            }
            node->decrementCountEnWith();
            return;
        }

};

int main(){
    // cout<<"hello world\n";
    Trie* trie = new Trie();
    trie->insertWord("bus");
    trie->insertWord("buses");
    trie->insertWord("truck");
    cout<<trie->countSearchWord("bu")<<endl;
    cout<<trie->countSearchWord("bus")<<endl;
    trie->eraseWord("buses");
    cout<<trie->countSearchWord("buses")<<endl;
    cout<<trie->countStartsWithWord("bu")<<endl;
    cout<<trie->countSearchWord("truck")<<endl;
    return 0;
}