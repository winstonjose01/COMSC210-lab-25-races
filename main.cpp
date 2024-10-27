// COMSC210 | Lab 25| Winston Jose
// IDE UsedL Visual Studio Code
// Github link: https://github.com/winstonjose01/COMSC210-lab-25-races 

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

template <typename Container>
void reading (ifstream &, Container &);

int main() {
    string line;
    int numline = 0;
    ifstream fin("codes.txt");
    if (!fin.is_open()){                                // Check if the file opened successfully
        cout << "Error opening file. Aborting!";            
        return(1);    
    }

    // ------------------------ READING -------------------------------
    // Vector
    auto start1 = high_resolution_clock::now();         // Start timing for vector reading
    vector <string> randomIDs_vector;                   // Create vector to store lines from the file
    reading(fin, randomIDs_vector);
    // while (getline(fin, line)){                         // Read lines until EOF
    //     numline++;
    //     randomIDs_vector.push_back(line);               // Add line to the vector
    // }
    //fin.clear();                                        // Clear the filestream
    auto end1 = high_resolution_clock::now();           // End timing for vector reading
    auto duration1 = duration_cast<microseconds>(end1-start1).count()/1000.0; // Calculate the duration in milliseconds
    // List
    auto start2 = high_resolution_clock::now();         // Start timing for list reading
    list<string> randomIDs_list;                        // Create list to store lines from the file
    while (getline(fin, line)){                         // Read lines until EOF
        randomIDs_list.push_back(line);                 // Add line to the list
    }
    fin.clear();                                        // Clear the filstream
    auto end2 = high_resolution_clock::now();           // End timing for list reading
    auto duration2 = duration_cast<microseconds>(end2-start2).count()/1000.0; // Calculate the duration in milliseconds
    // Set
    auto start3 = high_resolution_clock::now();         // Start timing for set reading 
    set<string> randomIDs_set;                          // Create set to store lines from the file   
    while (getline(fin, line)){                         // Read lines until EOF
        randomIDs_set.emplace(line);                    // Add line to the set
    }
    fin.clear();                                        // Clear the filestream
    auto end3 = high_resolution_clock::now();           // End timing for set reading
    auto duration3 = duration_cast<microseconds>(end3-start3).count()/1000.0; // Calculate the duration in milliseconds

    // ------------------------ SORTING -------------------------------
    // Vector   
    auto start4 = high_resolution_clock::now();         // Start timing for vector sorting
    sort(randomIDs_vector.begin(), randomIDs_vector.end()); // Sort the vector
    auto end4 = high_resolution_clock::now();               // End timing for vector sorting
    auto duration4 = duration_cast<microseconds>(end4-start4).count()/1000.0; // Calculate the duration in milliseconds
    // List
    auto start5 = high_resolution_clock::now();         // Start timing for list sorting
    randomIDs_list.sort();                              // Sort the list
    auto end5 = high_resolution_clock::now();           // End timing for list sorting
    auto duration5 = duration_cast<microseconds>(end5-start5).count()/1000.0; // Calculate the duration in milliseconds
    
    // Set - Sorting set automatically happens when the elements are read into the set.

    // ------------------------ INSERTING -------------------------------
    
    auto start7 = high_resolution_clock::now();         // Start timing for vector insertion
    randomIDs_vector.insert(randomIDs_vector.begin() + numline/2,"TESTCODE"); // Insert "TESTCODE" in the middle of the vector
    auto end7 = high_resolution_clock::now();           // End timing for vector insertion
    auto duration7 = duration_cast<microseconds>(end7-start7).count()/1000.0; // Calculate the duration in milliseconds

    auto start8 = high_resolution_clock::now();         // Start timing for list insertion
    auto it_list = randomIDs_list.begin();              // Create iterator and position at the beginning of the list
    advance(it_list,numline/2);                         // Advance iterator to the middle of the list
    randomIDs_list.insert(it_list,"TESTCODE");          // Insert string "TESTCODE"
    auto end8 = high_resolution_clock::now();           // End timing for list insertion
    auto duration8 = duration_cast<microseconds>(end8-start8).count()/1000.0; // Calculate the duration in milliseconds

    
    auto start9 = high_resolution_clock::now();         // Start timing for set insertion
    randomIDs_set.insert("TESTCODE");                   // Insert "TESTCODE" 
    auto end9 = high_resolution_clock::now();           // End timing for set insertion
    auto duration9 = duration_cast<microseconds>(end9-start9).count()/1000.0; // Calculate the duration in milliseconds

    // ------------------------ DELETING -------------------------------

    auto start10 = high_resolution_clock::now();        // Start timing for vector deletion
    randomIDs_vector.erase(randomIDs_vector.begin() + numline /2); // Delete element at index numline/2
    auto end10 = high_resolution_clock::now();          // End timing for vector deletion
    auto duration10 = duration_cast<microseconds>(end10-start10).count()/1000.0; // Calculate the duration in milliseconds

    auto start11 = high_resolution_clock::now();        // Start timing for list deletion       
    it_list = randomIDs_list.begin();                   // Reset list iterator to the beginning of the list 
    advance(it_list,numline/2);                         // Advance iterator to middle of the list
    randomIDs_list.erase(it_list);                      // Delete element at indext numline/2
    auto end11 = high_resolution_clock::now();          // End timing for list deletion
    auto duration11 = duration_cast<microseconds>(end11-start11).count()/1000.0; // Calculate the duration in milliseconds

    auto start12 = high_resolution_clock::now();        // Start timing for set deletion    
    auto it_set = randomIDs_set.begin();                // Create iterator and initialize at the beginning of the set
    advance(it_set,numline/2);                          // Advance iterator to middle of the list
    randomIDs_set.erase(it_set);                        // Delete element at indext numline/2
    auto end12 = high_resolution_clock::now();          // End timing for set deletion
    auto duration12 = duration_cast<microseconds>(end12-start12).count()/1000.0; // Calculate the duration in milliseconds

    // Output the timing on the table
    cout << fixed << setprecision(3);
    cout << setw(12) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << setw(12) <<  right << "Reading" << setw(10) << right << duration1 << setw(10) << right << duration2 << setw(10) << right << duration3 << endl;
    cout << setw(12) <<  right << "Sorting" << setw(10) << right << duration4 << setw(10) << right << duration5 << setw(10) << right << duration3 << endl;
    cout << setw(12) <<  right << "Inserting" << setw(10) << right << duration7 << setw(10) << right << duration8 << setw(10) << right << duration9 << endl;
    cout << setw(12) <<  right << "Deleting" << setw(10) << right << duration10 << setw(10) << right << duration11 << setw(10) << right << duration12 << endl;

    return 0;
}

template <typename Container>
void reading (ifstream &f, Container &coll){
    string line;
    f.clear();
    f.seekg(0);

    while (getline(f,line)){
        if constexpr (is_same_v<Container, vector<string>> ||  is_same_v <Container, list<string>>){
            coll.push_back(line);
        }
        else if constexpr (is_same_v <Container,set<string>>){
            coll.emplace(line);
        }
    }

}
    



/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/