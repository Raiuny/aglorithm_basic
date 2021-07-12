#include<iostream>
using namespace std;
int main(int argc, char **argv)
{
/* 输入一个整数，判断是否为水仙花数 */
int n, temp, i, sum;
int a[11];
while(1){
    cin >> n;
    temp = n;
    for (i = 0; i < 10 ; i++)
    {
        a[i] = temp%10;
        temp = temp/10;
        if(!temp) break;
    }
    sum = 0;
    for(; i >= 0 ; i--)
    {
        sum += a[i]*a[i]*a[i];
    }    
    if(sum == n) cout << n <<" :是水仙花数" << endl;
    else cout << n << " :不是水仙花数" << endl;
}
return 0;
}