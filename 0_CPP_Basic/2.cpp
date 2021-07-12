#include <iostream>
using namespace std;
int main(int argc, char **args)
{
    /* 输入年份 判断是否是闰年 */
    int n;
    while(1){
        cin >> n;
        cout << n << " :";
    if(n%4==0){
        if(n%100) {
           cout << "是闰年" << endl;
        }
        else if(n%400) {
            cout << "不是闰年" << endl;
        }
        else {
            cout << "是闰年" << endl;
        }
    }
    else cout << "不是闰年" << endl;
    }
    return 0;
}