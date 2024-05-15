#include <iostream>
#include <list> // Include the list header for using std::list
#include <vector>

using namespace std;

// Structure to represent a file
struct File {
    string name;
    int size;
};

// Function to allocate files using linked list allocation
void linkedListFileAllocation(const vector<File>& files, int diskSize) {
    list<pair<int, int>> diskSpace; // Linked list to represent disk space

    // Initialize the disk space with a single block representing the entire disk
    diskSpace.push_back(make_pair(0, diskSize - 1));

    // Allocate files using linked list allocation
    for (const File& file : files) {
        bool allocated = false;

        // Iterate through the blocks of disk space
        for (auto it = diskSpace.begin(); it != diskSpace.end(); ++it) {
            // If block is large enough for file allocation
            if (it->second - it->first + 1 >= file.size) {
                // Allocate file in this block
                cout << "Allocating " << file.name << " from block " << it->first << " to " << it->first + file.size - 1 << endl;

                // Update the current block's start position
                it->first += file.size;

                allocated = true;
                break;
            }
        }

        // If file couldn't be allocated, print error message
        if (!allocated) {
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

    // Allocate files using linked list file allocation
    linkedListFileAllocation(files, diskSize);

    return 0;
}
