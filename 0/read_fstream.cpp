#include<fstream>
using namespace std;
int main()
{
    int a, b;
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");
    while (inFile >> a >> b)
    {
        outFile << a + b << endl;
    }
  inFile.close();
  outFile.close(); 
  return 0;
}