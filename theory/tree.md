## Binary Tree

Minimum possible height - log(n+1)  

### Trasversal  

#### DFS 
In,pre,post  
Tc - O(N), AS - O(h)  

#### BFS / Level order  
TC- O(N), sc - o(n)  

#### Morris inorder  
O(n) sc- O(1)  
![image4](./media/image4.png)
 
### Properties  
- Maximum number of nodes at level l is 2l;  
- Maximum no of nodes in binary tree of height h is 2h -1  
- Minimum height of binary tree with n node is log2(n+1)  
- Binary tree with l leaves has at least log2(l)+1 level  
- In Binary tree where every node has 0 or 2 children, the number of leaf nodes is always one more than nodes with two children  
- No of edge = no of node -1, root has no edge 

### Type  
- Full binary tree - either 0 or 2 children  
- Complete binary tree - all levels completely filled except last level  
- Perfect binary tree - A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same leve  
- Balanced binary tree - if height = log(n)  
- Degenerate or (pathological tree) - tree where very internal node has one child  

- Enumeration of tree   
    Nth catalan number - T(n)=sum_{i=0}^{n-1}T(i)T(n-i-1)  for  ngeq 1;                               
    Unlabeled tree - T(n) = (2n)! / (n+1)!n!  
    Labeled tree - T(n) = (2n)! / (n+1)!  
- Insert node  
    Bfs until we find node with either left or right child empty  
    Insert new node there  
- Delete node  
- BFS vs DFS  
Time complexity  - O(n) n = no. of node  
Space complexity  
    Dfs- o(height)  
    BFS - o (weight)  
 - Binary tree, array implementation  
 - AVL with duplicate keys - check later  
 - 
### Traversals  
- Inorder without recursion , using stack 
- Inorder without recursion and stack , morris traversal
- Create postorder from in and pre 
- Create post order from preorder 
 - Find all possible binary tree with given inorder traversal 
