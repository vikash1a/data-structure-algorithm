# Others

## Class in C++

![image5](./media/image5.png)

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
## C++ & C# DS Comaprison


| C++                                                      | C#                                       | Java                                           |
| :------------------------------------------------------- | :---------------------------------------- | :--------------------------------------------- |
| vector<int>, push_back,size,pop_back                 | List<int> , add,count,list.sort(),      | ArrayList<int> , add, get, set               |
| Linked list- custom, list stl                           | Linkedlist<t>                           | LinkedList, addFirst, addLast                  |
| Strings                                                  | string                                    | string                                         |
| Stacks ,st.push(a),st.pop(),st.top()st.size(),st.empty() | Stack, push(), pop(),peek()               | Stack, push,pop,isEmpty                        |
| Queues,q.push(a),q.front(),q.back(),q.pop(),size,empty   | Queue, enqueue, dequeue, peek             | LinkedList                                     |
| Hashing- unordered_set, unorderer_map                 | Hashset- Add ,remove, dictionoary         | HashSet,add,contains,remove                    |
| Maps- map, set                                          | Sortedset- Add ,remove, sortedDictionary | HashMap<int,int> hm, hm.put(“1”,”2”),get |
| Heap- priority queue                                    | Priority queue- check later              |                                                |
| tree                                                     |                                           |                                                |
| graph                                                    |                                           |                                                |
| cout<<” “<<endl; cin>>endl;                      | Console.writeLine();Console.ReadLine()    | System.out.println();                          |

## C++ data type size


| Data Type              | Size (in bytes) |              Range              |
| ---------------------- | :-------------: | :------------------------------: |
| short int              |        2        |        -32,768 to 32,767        |
| unsigned short int     |        2        |           0 to 65,535           |
| unsigned int           |        4        |        0 to 4,294,967,295        |
| int                    |        4        | -2,147,483,648 to 2,147,483,647 |
| long int               |        4        | -2,147,483,648 to 2,147,483,647 |
| unsigned long int      |        4        |        0 to 4,294,967,295        |
| long long int          |        8        |       -(2^63) to (2^63)-1       |
| unsigned long long int |        8        | 0 to 18,446,744,073,709,551,615 |
| signed char            |        1        |           -128 to 127           |
| unsigned char          |        1        |             0 to 255             |
| float                  |        4        |                                  |
| double                 |        8        |                                  |
| long double            |       12       |                                  |
| wchar_t               |     2 or 4     |         1 wide character         |

## Things to remember

vector<int> v; v.size()-1 will give a large number because v.size() is type of unsigned integer.  
Correction - (int)v.size()-1
