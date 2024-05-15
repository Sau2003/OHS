#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Structure to represent a file
struct File {
    string name;
    int size;
};

// Function to allocate files using index file allocation
void indexFileAllocation(const vector<File>& files, int diskSize) {
    unordered_map<string, int> indexTable; // Index table to store file locations

    int currentBlock = 0; // Initialize current block to 0

    // Allocate files using index file allocation
    for (const File& file : files) {
        if (currentBlock + file.size <= diskSize) {
            // Allocate file and update index table
            indexTable[file.name] = currentBlock;
            cout << "Allocating " << file.name << " at block " << currentBlock << endl;
            
            // Move to the next block
            currentBlock += file.size;
        } else {
            cout << "Disk full! Cannot allocate " << file.name << endl;
        }
    }
}

int main() {
    // Example files with their sizes
    vector<File> files = {
        {"File1", 200},
        {"File2", 300},
        {"File3", 400},
        {"File4", 100},
        {"File5", 150}
    };

    // Disk size
    int diskSize = 1000; // Assuming disk size is 1000 units

    // Allocate files using index file allocation
    indexFileAllocation(files, diskSize);

    return 0;
}
