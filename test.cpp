#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    enum class apple{A,B,C};
    vector<int> hi[2][3][4];
    vector<int> hehe(3,0);
    hi[apple::A][2][2] = hehe;
        

    return 0;
}