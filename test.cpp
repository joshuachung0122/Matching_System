#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ifstream ifs("tutor_info.txt");
    char line[1024];
    int i=0;
    for(;!ifs.eof();++i)
        ifs.getline(line,1024);
    cout<<i;
    ifs.close();
    return 0;
}