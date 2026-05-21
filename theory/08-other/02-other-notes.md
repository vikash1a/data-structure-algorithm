# Others

## Class in C++

![image5](../media/image5.png)

```C++

    #include <bits/stdc++.h>
    using namespace std;
    class Geeks
    {
        public:
        int id;
      
        //Default Constructor
        Geeks()
        {
            cout << "Default Constructor called" << endl;
            id=-1;
        }
      
        //Parameterized Constructor
        Geeks(int x)
        {
            cout << "Parameterized Constructor called" << endl;
            id=x;
        }
    };
    int main() {
      
        // obj1 will call Default Constructor
        Geeks obj1;
        cout << "Geek id is: " <<obj1.id << endl;
      
        // obj1 will call Parameterized Constructor
        Geeks obj2(21);
        cout << "Geek id is: " <<obj2.id << endl;
        return 0;
    }
```
## DS Comparison


| C++                                                      | Java                                          | Kotlin                                   |
| :------------------------------------------------------- | :-------------------------------------------- | ---------------------------------------- |
| vector<int>, push_back,size,pop_back                     | ArrayList<int> , add, get, set                | List<int>, MutableList<int>,add, remove, |
| Linked list- custom, list stl                            | LinkedList, addFirst, addLast                 | use java                                 |
| Strings                                                  | string                                        | string                                   |
| Stacks ,st.push(a),st.pop(),st.top()st.size(),st.empty() | Stack, push,pop,isEmpty                       | use java                                 |
| Queues,q.push(a),q.front(),q.back(),q.pop(),size,empty   | LinkedList                                    | use java                                 |
| Hashing- unordered_set, unorderer_map                    | HashSet,add,contains,remove                   | HashSet,add,contains,remove              |
| Maps- map, set                                           | HashMap<int,int> hm, hm.put(“1”,”2”),get      | HashMap<int,int> hm, hm.put(“1”,”2”),get |
| Heap- priority queue                                     | PriorityQueue<Int>()   , add , poll, peek     | use java                                 |
| tree                                                     |                                               |
| graph                                                    |                                               |
| cout<<” “<<endl; cin>>endl;                              | System.out.println(); new Scanner(System.in); | println() readLine()                     |

## C++ data type size


| Data Type              | Size (in bytes) |              Range              |
| ---------------------- | :-------------: | :-----------------------------: |
| short int              |        2        |        -32,768 to 32,767        |
| unsigned short int     |        2        |           0 to 65,535           |
| unsigned int           |        4        |       0 to 4,294,967,295        |
| int                    |        4        | -2,147,483,648 to 2,147,483,647 |
| long int               |        4        | -2,147,483,648 to 2,147,483,647 |
| unsigned long int      |        4        |       0 to 4,294,967,295        |
| long long int          |        8        |       -(2^63) to (2^63)-1       |
| unsigned long long int |        8        | 0 to 18,446,744,073,709,551,615 |
| signed char            |        1        |           -128 to 127           |
| unsigned char          |        1        |            0 to 255             |
| float                  |        4        |                                 |
| double                 |        8        |                                 |
| long double            |       12        |                                 |
| wchar_t                |     2 or 4      |        1 wide character         |

## Things to remember

vector<int> v; v.size()-1 will give a large number because v.size() is type of unsigned integer.  
Correction - (int)v.size()-1
