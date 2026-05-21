# Other Notes

## C++ Class

```cpp
#include <bits/stdc++.h>
using namespace std;

class Geeks {
public:
    int id;

    // Default constructor
    Geeks() : id(-1) {}

    // Parameterised constructor
    Geeks(int x) : id(x) {}
};

int main() {
    Geeks obj1;       // default constructor — id = -1
    Geeks obj2(21);   // parameterised constructor — id = 21
}
```

---

## C++ Data Types

| Type | Size | Range |
|---|---|---|
| `int` | 4 bytes | −2,147,483,648 to 2,147,483,647 |
| `long long int` | 8 bytes | −(2^63) to (2^63)−1 |
| `unsigned int` | 4 bytes | 0 to 4,294,967,295 |
| `unsigned long long` | 8 bytes | 0 to 18,446,744,073,709,551,615 |
| `short int` | 2 bytes | −32,768 to 32,767 |
| `char` / `signed char` | 1 byte | −128 to 127 |
| `unsigned char` | 1 byte | 0 to 255 |
| `float` | 4 bytes | ~7 decimal digits |
| `double` | 8 bytes | ~15 decimal digits |
| `long double` | 12 bytes | ~18 decimal digits |
| `wchar_t` | 2 or 4 bytes | wide character |

---

## Gotchas

**`vector::size()` returns unsigned — subtraction can overflow:**

```cpp
vector<int> v;
v.size() - 1;        // BUG: underflows to a huge number if v is empty
(int)v.size() - 1;   // CORRECT: cast first
```

---

## DS Syntax Comparison — C++ / Java / Kotlin

| Structure | C++ | Java | Kotlin |
|---|---|---|---|
| Dynamic array | `vector<int>` | `ArrayList<Integer>` | `MutableList<Int>` |
| Linked list | `list<T>` (STL) | `LinkedList` | use Java |
| Stack | `stack<T>` | `Stack` | use Java |
| Queue | `queue<T>` | `LinkedList` as queue | use Java |
| Hash set | `unordered_set<T>` | `HashSet` | `HashSet` |
| Hash map | `unordered_map<K,V>` | `HashMap<K,V>` | `HashMap<K,V>` |
| Sorted map | `map<K,V>` | `TreeMap<K,V>` | use Java |
| Heap | `priority_queue<T>` | `PriorityQueue<Int>` | use Java |
| Print | `cout << x << endl` | `System.out.println(x)` | `println(x)` |
| Input | `cin >> x` | `Scanner(System.in)` | `readLine()` |
