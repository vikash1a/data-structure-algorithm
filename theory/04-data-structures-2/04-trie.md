This data structure is used for optimised search and insertion.

### Node Structure

- Node -> It represents a single character and contians all the children nodes
- Children -> Each node has multiple children node representing one of possible characters that comes after. 
- isEndofWrod -> Represents if node is a end of word. 
- SC - O(ALPHABET_SIZE * m * n)
  - m -> total no of word
  - n -> avg length of word

![](./media/trie-ds.png)

```c++
class Node{
    int countEndWith = 0;
    int countPrefix = 0;
    vector<Node*> nodeV;
};
```

### Insertion
TC - O(world length)
![](./media/trie-insertion.png)

### Search 
TC - O(world length)
![](./media/trie-search.png)

### Source
[Striver Trie Playlist](https://www.youtube.com/watch?v=RV0QeTyHZxo&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=4)