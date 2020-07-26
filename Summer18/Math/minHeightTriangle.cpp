#include <iostream>

using namespace std;

int lowestTriangle(int base, int area){
    return (2*area+base-1)/base;
}


int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}