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
template <typename Container>
void sorting (Container &);
template<typename Container>
void inserting (Container &, int);
template<typename Container>
void deleting (Container &, int);
double elapsed(time_point<high_resolution_clock>, time_point<high_resolution_clock>);

int main() {
    string line;
    int numline = 0;
    ifstream fin("codes.txt");
    if (!fin.is_open()){                                // Check if the file opened successfully
        cout << "Error opening file. Aborting!";            
        return(1);    
    }
    else {
        while (getline(fin, line)){                     // Loop to read the number of lines in the file
            numline++;
            }
    }
    fin.clear();                                        // Clear any errors from the filestream 
    fin.seekg(0);                                       // Reset the file pointer to the start of the file

    // ------------------------ READING -------------------------------
    // Vector
    auto start1 = high_resolution_clock::now();         // Start timing for vector reading
    vector <string> random_vector;                      // Create vector to store lines from the file
    reading(fin, random_vector);                        // Call reading() template function
    auto end1 = high_resolution_clock::now();           // End timing for vector reading
    auto duration1 = elapsed(start1, end1);             // Calculate the duration in milliseconds

    // List
    auto start2 = high_resolution_clock::now();         // Start timing for list reading
    list<string> random_list;                           // Create list to store lines from the file
    reading(fin, random_list);                          // Call reading() template function
    auto end2 = high_resolution_clock::now();           // End timing for list reading
    auto duration2 = elapsed(start2, end2);             // Calculate the duration in milliseconds

    // Set
    auto start3 = high_resolution_clock::now();         // Start timing for set reading 
    set<string> random_set;                             // Create set to store lines from the file   
    reading(fin,random_set);                            // Call reading() template function
    auto end3 = high_resolution_clock::now();           // End timing for set reading
    auto duration3 = elapsed(start3, end3);             // Calculate the duration in milliseconds

    // ------------------------ SORTING -------------------------------
    // Vector   
    auto start4 = high_resolution_clock::now();         // Start timing for vector sorting
    sorting (random_vector);                            // Call sorting() template function
    auto end4 = high_resolution_clock::now();           // End timing for vector sorting
    auto duration4 = elapsed(start4, end4);

    // List
    auto start5 = high_resolution_clock::now();         // Start timing for list sorting
    sorting (random_list);                              // Call sorting() template function
    auto end5 = high_resolution_clock::now();           // End timing for list sorting
    auto duration5 = elapsed(start5, end5);             // Calculate the duration in milliseconds
    
    // Set - Sorting set automatically happens when the elements are read into the set.

    // ------------------------ INSERTING -------------------------------
    
    auto start7 = high_resolution_clock::now();         // Start timing for vector insertion
    inserting(random_vector,numline);                   // Call inserting() template function
    auto end7 = high_resolution_clock::now();           // End timing for vector insertion
    auto duration7 = elapsed(start7, end7);             // Calculate the duration in milliseconds

    auto start8 = high_resolution_clock::now();         // Start timing for list insertion
    inserting(random_list, numline);                    // Call inserting() template function
    auto end8 = high_resolution_clock::now();           // End timing for list insertion
    auto duration8 =  elapsed(start8, end8);             // Calculate the duration in milliseconds

    
    auto start9 = high_resolution_clock::now();         // Start timing for set insertion
    inserting(random_set, numline);                     // Call inserting() template function
    auto end9 = high_resolution_clock::now();           // End timing for set insertion
    auto duration9 = elapsed(start9, end9);             // Calculate the duration in milliseconds

    // ------------------------ DELETING -------------------------------

    auto start10 = high_resolution_clock::now();        // Start timing for vector deletion
    deleting(random_vector,numline);                    // Call deleting() template function
    auto end10 = high_resolution_clock::now();          // End timing for vector deletion
    auto duration10 = elapsed(start10, end10);          // Calculate the duration in milliseconds

    auto start11 = high_resolution_clock::now();        // Start timing for list deletion       
    deleting(random_list, numline);                     // Call deleting() template function
    auto end11 = high_resolution_clock::now();          // End timing for list deletion
    auto duration11 = elapsed(start11, end11);          // Calculate the duration in milliseconds

    auto start12 = high_resolution_clock::now();        // Start timing for set deletion    
    deleting(random_set,numline);                       // Call deleting() template function
    auto end12 = high_resolution_clock::now();          // End timing for set deletion
    auto duration12 = elapsed(start12 ,end12);          // Calculate the duration in milliseconds

    // Output the timing on the table
    cout << fixed << setprecision(3);
    cout << setw(12) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << setw(12) <<  right << "Reading" << setw(10) << right << duration1 << setw(10) << right << duration2 << setw(10) << right << duration3 << endl;
    cout << setw(12) <<  right << "Sorting" << setw(10) << right << duration4 << setw(10) << right << duration5 << setw(10) << right << duration3 << endl;
    cout << setw(12) <<  right << "Inserting" << setw(10) << right << duration7 << setw(10) << right << duration8 << setw(10) << right << duration9 << endl;
    cout << setw(12) <<  right << "Deleting" << setw(10) << right << duration10 << setw(10) << right << duration11 << setw(10) << right << duration12 << endl;

    return 0;
}

// A template function that reads from a file and stores elements into a container
// arguments: A filestream and a template type variable
// returns: No returns
template <typename Container>
void reading (ifstream &f, Container &coll){
    string line;
    f.clear();                          // Clear any error flags in the filestream
    f.seekg(0);                         // Set the pointer back to the beginning of the file

    while (getline(f,line)){
        // If container is either a vector or a list
        if constexpr (is_same_v<Container, vector<string>> ||  is_same_v <Container, list<string>>){    
            coll.push_back(line);       // Store the elements
        }
        else if constexpr (is_same_v <Container,set<string>>){
            coll.emplace(line);         // Store the elements
        }
    }
}

// A template function that does sorting on the elements of the container
// arguments:  A template variable that is a Container type
// returns: No returns
template <typename Container>
void sorting (Container &coll){
    if constexpr(is_same_v<Container,vector<string>>){      // If container is a vector
        sort(coll.begin(),coll.end());              // Sort the vector
    } 
    else if constexpr(is_same_v<Container,list<string>>){   // If container is a list
        coll.sort();                                // Sort the list
    }
}

// A template function that inserts a new element in the middle the container
// arguments: A template variable that is a Container type
// returns: No returns
template <typename Container>
void deleting (Container &coll, int x){
    if constexpr(is_same_v<Container,vector<string>>){  // If container is vector
        coll.erase(coll.begin() + x/2);             // Delete element at index middle of the vector
    }    
    else if constexpr(is_same_v<Container,list<string>>){   //If container is a list
        auto it_list = coll.begin();               // Create iterator and position at the beginning of the list
        advance(it_list,x/2);                      // Advance iterator to the middle of the list
        coll.erase(it_list);                       // Delete element at middle of the list
    }
    else if constexpr(is_same_v<Container, set<string>>){   // If container is a set
        auto it_set = coll.begin();                // Create iterator and initialize at the beginning of the set
        advance(it_set,x/2);                       // Advance iterator to middle of the set
        coll.erase(it_set);                        // Delete element at middle of the set
    }
}
    
// A template function that deletes an element from the middle container
// arguments: A template variable that is a Container type and an int (the number of lines in the file)
// returns: No returns
template <typename Container>
void inserting (Container &coll, int x){
    if constexpr(is_same_v<Container,vector<string>>){    // If container is a vector
        coll.insert(coll.begin() + x/2,"TESTCODE");       // Insert the new element
    }    
    else if constexpr(is_same_v<Container,list<string>>){ // If container is a list
        auto it_list = coll.begin();                // Create iterator and position at the beginning of the list
        advance(it_list,x/2);                       // Advance iterator to the middle of the list
        coll.insert(it_list,"TESTCODE");            // Insert the new element
    }
    else if constexpr(is_same_v<Container, set<string>>){ // If container is a set
        coll.insert("TESTCODE");                    // Insert the new element
    }
}

// A function that calculates and returns the elapsed time
// arguments: 2 timepoint variables (the start and stop time)
// returns: Returns a double, the value of elapsed time.
double elapsed(time_point<high_resolution_clock> start, time_point<high_resolution_clock> stop){
    return(duration_cast<microseconds>(stop-start).count()/1000.0);
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/