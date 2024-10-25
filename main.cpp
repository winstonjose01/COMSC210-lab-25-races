#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

int main() {
    string line;


    ifstream fin("codes.txt");

    auto start1 = high_resolution_clock::now();
    vector <string> randomIDs_vector;
    while (getline(fin, line))
        randomIDs_vector.push_back(line);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1-start1);
    cout << "Reading codes into a vector: " << duration1.count() << " milliseconds\n";
    

    auto start2 = high_resolution_clock::now();
    list<string> randomIDs_list;
    while (getline(fin, line))
        randomIDs_list.push_back(line);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2-start2);
    cout << "Reading codes into a list: " << duration2.count() << " milliseconds\n";

    
    auto start3 = high_resolution_clock::now();
    set<string> randomIDs_set;
    while (getline(fin, line))
        randomIDs_list.push_back(line);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<milliseconds>(end3-start3);
    cout << "Reading codes into a list: " << duration3.count() << " milliseconds\n";


    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/