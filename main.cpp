#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

int main() {

    auto start = high_resolution_clock::now();
    string line;
    vector 

    ifstream fin("codes.txt");
    while (getline(fin, line))
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/