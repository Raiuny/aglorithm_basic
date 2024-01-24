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
g++ -o read read.cpp 
.\read.exe
```
