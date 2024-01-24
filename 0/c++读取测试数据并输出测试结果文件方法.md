### C++读取测试数据文件并输出测试结果文件方法

#### C语言实现
```
#include <cstdio>
int main()
{
    int a, b;
    freopen("in.txt", "r", stdin);   //输入重定向，输入数据将从in.txt文件中读取
    freopen("out.txt", "w", stdout); //输出重定向，输出数据将保存在out.txt文件中
    while (scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d ",a*b);
    }
    fclose(stdin);  //关闭文件
    fclose(stdout); //关闭文件
    return 0;
}
```
```shell
gcc -o read read_freopen.c 
.\read.exe
comp out.txt out_std.txt
```
在cmd中使用fc或comp命令可以看最后的文件和标准答案文件内容是否相同。
#### 直接重定向
```cpp
#include <cstdio>
int main()
{
    int a, b;
    while (scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d ",a*b);
    }
    return 0;
}
```
```
gcc -o read read.c
.\read.exe < in.txt > out.txt
```
使用type或者more来查看输出txt文件的内容，使用comp和fc来比较与标准答案之间的差别
