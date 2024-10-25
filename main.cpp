#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int main() {
    string line;
    int numline = 0;


    ifstream fin("codes.txt");
    auto start1 = high_resolution_clock::now();
    vector <string> randomIDs_vector;
    while (getline(fin, line))
        numline++;
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
        randomIDs_set.emplace(line);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<milliseconds>(end3-start3);
    cout << "Reading codes into a list: " << duration3.count() << " milliseconds\n";

    cout << "--------------------- SORTING-------------------------------\n";
    auto start4 = high_resolution_clock::now();
    sort(randomIDs_vector.begin(), randomIDs_vector.end());
    auto end4 = high_resolution_clock::now();
    auto duration4 = duration_cast<milliseconds>(end4-start4);
    cout << "Sort codes in the vector: " << duration4.count() << " milliseconds\n";

    auto start5 = high_resolution_clock::now();
    randomIDs_list.sort();
    auto end5 = high_resolution_clock::now();
    auto duration5 = duration_cast<milliseconds>(end5-start5);
    cout << "Sort codes in the list: " << duration5.count() << " milliseconds\n";

    cout << "Sort codes in the set: " << duration3.count() << " milliseconds\n";

    cout << "--------------------- INSERTING-------------------------------\n";
    
    auto start7 = high_resolution_clock::now();
    randomIDs_vector.insert(randomIDs_vector.begin() + numline/2,0,"TESTCODE");
    auto end7 = high_resolution_clock::now();
    auto duration7 = duration_cast<microseconds>(end7-start7);
    cout << "Insert TESTCODE into the vector: " << fixed << setprecision(3) << duration7.count()/1000.0 << " milliseconds\n";

    auto start8 = high_resolution_clock::now();
    auto it_list = randomIDs_list.begin();
    advance(it_list,numline);
    randomIDs_list.insert(it_list,"TESTCODE");
    auto end8 = high_resolution_clock::now();
    auto duration8 = duration_cast<microseconds>(end8-start8);
    cout << "Insert TESTCODE into the list: " << fixed << setprecision(3) << duration8.count()/1000.0 << " milliseconds\n";

    
    auto start9 = high_resolution_clock::now();
    randomIDs_set.insert("TESTCODE");
    auto end9 = high_resolution_clock::now();
    auto duration9 = duration_cast<microseconds>(end9-start9);
    cout << "Insert TESTCODE into the list: " << fixed << setprecision(3) << duration9.count()/1000.0 << " milliseconds\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/