[TOC]
# C++ STL

## 数据类型
- int
- char
- bool
- char* 
- string 包含在string库里`#include <string>`

## 常用的函数
- getline(cin, string line);
  读取一行
- cin.getline(char* str, _num);
- cin判断EOF
  ```c++
  while(cin>>a){
      // 当文件读取完文件，到达文件末尾后会返回0
  }
  ```
 ### 输入输出流函数细节
- cin的速度比scanf慢很多，1e5以上的数据用cin读入可能会TLE，此时建议用scanf
- 输出小数用printf更方便一点，c++格式输出要用到`<iomanip>`头文件，用cout.setprecistion(int digit);来设置精度
- 输出小数用printf，其余用cout.

## C++语法特性
### C++ 动态开辟内存
```c++
int* number = new int;
int* arr = new int[100];
char* carr = (char*)malloc(100 * sizeof(char);//C的动态开辟内存
```

### 引用 &t
```c++
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
```

### 函数重载
- 相同名字的函数如果参数列表不同，则两个函数不同
- 默认参数 func(int a, int b = 0) //如果没有b参数则默认设为0

### struct
```c++
struct node
{
    int number;
    node *next;
    node(int _number = 0, node *_next = null){
        number = _number;
        next = _next;
    } //构造函数，有指针的对象，要自己写析构函数，不然容易产生内存溢出
};
// node* head; //前面不需要加struct
int main(int argc, char **argv){
    node a = node(0);
    node *b = new node(1, &a);
}
```

## C++ STL标准库
- < vector>
- < string>
- < algorithm>
  
< string> 和 < cstring>库完全不同
- memset()需要包含< cstring>库：
```
memset(str,0,sizeof(str));
memset(str,-1,sizeof(str));
memset(arr,0x3f3f3f3f,sizeof(arr));
```
< cstring>中还有其它实用的函数：
例如：
- strlen()
- strcmp() 字符串比较
- strcpy() 字符串拷贝
- memcpy() 暴力拷贝

< cmath>:
- 三角函数
- 指数函数
- 浮点取整函数
  
< cstdlib>:
- qsort() C语言快排
- rand() 随机数
- malloc() free() C语言动态分配内存
- srand(time(0)) 初始化随机种子

< ctime>:
- time(0) 从1970年到现在的秒数(配合随机数)
- clock() 程序启动到目前位置的毫秒数ms
```c++
//计时
int a = clock();
//程序在此
int consumeTime = clock() - a;
```
< cctype>:
- isdigit() 判断是否为数字
- isalpha() 判断是否为大小写字母

### < vector>
- vector 可以看成给一个变长数组，既可以用下标访问，也可以像链表一样动态改变长度
  
```c++
vector<int> arr(100);
vector<int> list;
for(int i = 0; i < 100; i++) {
    scanf("%d",&arr[i]);
    cout << arr[i] << endl;
}

for(int i = 0; i < 100; i++) {
    int a;
    cin >> a;
    list.push_back(a);
    printf("%d\n",list[i]);
}
```
#### vector的遍历
```c++
for(int i= 0; i < arr.size(); i++) {
    printf("%d\n",arr[i]);
}

vector<int>::iterator p1;
for(p1 = arr.begin(); p1 != arr.end(); p1++) {
    cout << *p1 << endl;
}
```

#### vector的crub操作 增删改查
- list.size(); //返回元素个数 O(1)
- list.clear(); //一键清空数组 O(n)
- list.empty(); //判断数组是否为空 O(1)
- list.begin(); // 返回首元素迭代器 O(1)
- list.end(); //返回尾元素迭代器，（最后一个元素的下一个元素）实际不存在
- list.erase(p1); //删除数组某个迭代器所在位置的元素 O(n)
- list.push_back(item1); //往数组后面添加元素 O(1)
- list.pop_back(); //删除数组最后一个元素 O(1)
```c++
vector<int>::iterator i = find( v1.begin(), v1.end(), 3);

if( i != v1.end()) {
    v1.insert(i, 6);  
}
```
### < string> 字符串
```c++
string str1 = "hello ";
string str2 = "world"; 
str2.push_back("!");
cout << str2 + str3 << endl;
```

#### string 的crub操作
```c++
- str.length(); str.size();  //O(n)
- str.insert(str.begin(),"aaa"); // 在迭代器处 str.begin()插入字符串 O(n)
- str.insert(1, "aaa") // 在下标为1处插入字符串 O(n)
- str.c_str(); 返回C语言字符串，用于printf() O(n)
- str.append(str2); // 将str2拼接到str后面 O(n)
- str.compare(str2); // strcmp(str,str2); 比较第一个不同的字符的ASCII码的大小，如果大，返回值1，
// 如果小 则返回-1；如果相等，返回0
- str == str2; // strcmp(str,str2) == 0;
- str += str2; // str.append(str, str2);
- str += 'a'; // str.push_back('a');
```

### < algorithm>
纯算法，不是类函数
#### sort()

复杂度： O(nlogn)
```c++
// 对数组
int arr[]={2,3,1,5,0,8};
int n = 6;
sort(arr,arr+n);
for(int i = 0; i < 6; i++) {
    cout << arr[i] << ' ';
}
// 对vector
vector<int> list(arr, arr+n);//利用数组进行初始化
sort(list.begin(),list.end());
```
sort函数中还有第三个参数，为一个函数参量，比较函数
- 方法1：自定义cmp函数
```java
sort(iterator begin, iterator end, function cmp);
int cmp(int a, int b) {
    return b < a; // b < a 时候返回true,不执行swap操作，否则执行swap操作
    // 因此最终会降序排列
}
sort(list.begin(), list.end(), cmp);
```
- 方法2：重载<
```c++
struct Point {
 int x, y;
};
const bool operator <(const Point &a, const Point &b){
      return a.x > b.x;
} 
sort(list.begin(), list.end()); //按照x降序排列，默认是升序排列的
// 重载小于号，只能作用于自定义结构体或者类，不能作用于固有的变量类型，会引起冲突
```
#### min(item1, item2), max()
#### min_element(iterator begin, iterator end) O(n)
#### max_element(iterator begin, iterator end) O(n)
#### nth_element(iterator begin, (iterator begin) + n, iterator end)   // O(n)

- 如果只想要排序后的第n位的元素则使用nth_element(), 其index = n ,所以是第n+1小的元素。
- 左边全部都是比它小的元素，右边全部都是比它大的元素
- 该函数无返回值，只是进行相关排序操作。
- 如果想得到第n+1大的元素，可以重载运算符<

```c++
int arr[8] = {2,3,4,0,-1,10,5,9};
int n;
cin >> n;
nth_element(arr, arr+n-1, arr+8);
printf("{%d: %d}",n,arr[n-1]);
sort(arr,arr+8);
for(int i=0; i < 8; i++)
cout << arr[i] << ' ';
```
#### swap(item1,item2) // 交换两个同类型变量
#### reverse(iterator begin, iterator end) //反转数组

#### unique(iterator begin, iterator end) //返回新数组尾部指针
```c++
int newlength = unique(arr,arr+n)-arr;
int newlength = unique(v.begin(),v.end()) - v.begin();
```
#### 二分查找
##### bool isExist = binary_search(iterator begin, iterator end, find_val, function cmp);

所谓“已排好序”，并不是要求 [first, last) 区域内的数据严格按照某个排序规则进行升序或降序排序，只要满足“所有令 element< val（或者 comp(val, element）成立的元素都位于不成立元素的前面（其中 element 为指定范围内的元素）”即可。
##### lower_bound(iterator begin, iterator end, item_val) //先排序，查找不小于 val 的元素
```C++ 
sort(arr,arr+n);
int firstloc = lower_bound(arr,arr+n, _val) - arr; //_val应该插入在firstloc处
int lastloc = upper_bound(arr,arr+n,_val) - arr; // _val应该插在lastloc处，二分查找的思想前提是数组已经排好顺序，查找不大于val的元素位置
// 如果是结构元素，需要重载小于号
```
### < stack>
- stack< int> s;
- s.push(item); // 入栈
- int topElement = s.top();
- s.pop(); //出栈
- s.empty(); //判断栈是否为空
- s.size(); // 返回栈的大小
### < queue>
- queue< int> que;
- que.push(item); //入队列
- int frontElem = que.front();
- que.pop(); //出队列
- que.empty(); //判断队列是否为空
- que.size(); //返回队列的大小
  
优先队列：加入删除一个元素为O(logn)
- priority_queue< int> que2;
- que2.push(item);
- int minElem = que2.top();
- que2.pop();
- que2.empty();
- que.size();  

### < set>
< set> 包含set, multiset
1. set 不允许元素重复，能够在O(logn)的时间内查找、删除、添加某个元素，将结构元素放入里面，需要重载小于号< 
    迭代器的++和--可以找到第一个比它大(小)的元素
- set< int> st;
- st.insert(item);
- st.find(item);
- st.erase(item);
  
2. set自带去重，multiset允许元素重复，通过count可以获得某个元素的数量
- multiset< int> mst;
- mst.insert(item);
- mst.find(item);
- mst.erase(item);
- mst.count(item);

### < map>
- pair< int, int> origin;
- origin = make_pair(0, 0);
- origin.first == origin.second;
- origin.swap;

pair自己有自己的比较函数，先比较第一个元素，然后再比较第二个元素。

```c++
pair< string, int> id;
id = make_pair("Tom", 18);
```

map<string, int> person; //哈希表
可以把第一个元素当做下标，也可以把第二个元素当做下标；
例如：
```cpp
#include <map>
pair<string int> id;
id = make_pair("Tom", 19);
map<string, int> students = {
    {"xx",12},
    {"yy",13} //初始化方式
}
students["小明"] = 20;
students["小红"] = 20;
students.insert(id);
students.erase("小明");
```

### < bitset> 位集合
```cpp
bitset<1000> bst; //新建一个包含1000位的集合bst
bst[0] = 1; bst.set(0); //置1操作
bst[0] = 0; bst.reset(0); //清零操作
bst << 1; bst >> 1; //移位操作
bst ^= 1; //异或操作，将第0位取反
bst &= 1; //与操作，取第0位
bst.count(); //1的个数，汉明码距
bst.to_string(); //返回字符串
bst.to_ullong(); //
// 状态压缩动态规划会用到位集合<bitset>
```
### PS:
- < functional> 在ACM中只是配合prio_queue一起使用
- < complex> C++中的复数类
- < unordered_set>: 不保证排好序，但是插入访问均为O(1);
- < unordered_map>: 不保证排好序，但是插入访问均为O(1); map插入的其实是字典， 只能对标准对象(int... ,pair<>)
- #include <bits/stdc++.h> // 将所有c++的标准库包含