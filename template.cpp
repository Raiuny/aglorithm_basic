#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char **argv)
{
int arr[8] = {2,2,1,1,-1,-1,5,9};
int newlen;
newlen = unique(arr,arr+8) - arr;

for(int i=0; i < newlen; i++)
cout << arr[i] << ' ';
system("pause");
return 0;
}