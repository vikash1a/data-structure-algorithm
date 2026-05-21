# C++ STL Reference

---

## Binary Search Functions

All require a **sorted** range. Return iterators (use `- v.begin()` for index).

| Function | Returns | Condition |
|---|---|---|
| `binary_search(f, l, val)` | `bool` | true if val exists |
| `lower_bound(f, l, val)` | iterator | first element **≥** val |
| `upper_bound(f, l, val)` | iterator | first element **>** val |

```cpp
vector<int> v = {1, 3, 5, 7, 9};

binary_search(v.begin(), v.end(), 5);       // true
lower_bound(v.begin(), v.end(), 5);         // iterator to 5 (index 2)
upper_bound(v.begin(), v.end(), 5);         // iterator to 7 (index 3)

// distance to index:
int idx = lower_bound(v.begin(), v.end(), 5) - v.begin();  // 2
```

---

## Containers Quick Reference

| Container | Ordered | Duplicates | Access | Insert/Delete |
|---|---|---|---|---|
| `vector<T>` | insertion order | yes | O(1) index | O(1) back, O(n) mid |
| `list<T>` | insertion order | yes | O(n) | O(1) anywhere |
| `stack<T>` | LIFO | yes | top only | O(1) |
| `queue<T>` | FIFO | yes | front/back | O(1) |
| `deque<T>` | insertion order | yes | O(1) | O(1) front/back |
| `set<T>` | sorted | no | O(log n) | O(log n) |
| `multiset<T>` | sorted | yes | O(log n) | O(log n) |
| `map<K,V>` | sorted by key | no dup keys | O(log n) | O(log n) |
| `unordered_set<T>` | none | no | O(1) avg | O(1) avg |
| `unordered_map<K,V>` | none | no dup keys | O(1) avg | O(1) avg |
| `priority_queue<T>` | heap | yes | O(1) top | O(log n) |

---

## Common Operations

```cpp
// Vector
vector<int> v(10, 0);
v.push_back(x);  v.pop_back();  v[i];  v.size();
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>());  // descending

// Stack
stack<int> st;
st.push(x);  st.pop();  st.top();  st.empty();

// Queue
queue<int> q;
q.push(x);  q.pop();  q.front();  q.back();  q.empty();

// Deque
deque<int> dq;
dq.push_back(x);  dq.push_front(x);
dq.pop_back();    dq.pop_front();

// Set / Map
set<int> s;
s.insert(x);  s.erase(x);  s.find(x);  s.count(x);

map<int,int> m;
m[key] = val;  m.find(key);  m.count(key);  m.erase(key);

// Priority Queue
priority_queue<int> maxH;                               // max-heap
priority_queue<int, vector<int>, greater<int>> minH;    // min-heap
maxH.push(x);  maxH.pop();  maxH.top();
```

---

## Useful Algorithms

```cpp
// Min / Max
*min_element(v.begin(), v.end());
*max_element(v.begin(), v.end());

// Reverse
reverse(v.begin(), v.end());

// Accumulate (sum)
accumulate(v.begin(), v.end(), 0);

// Count occurrences
count(v.begin(), v.end(), val);

// Next permutation
next_permutation(v.begin(), v.end());

// Unique (remove consecutive duplicates — sort first)
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```
