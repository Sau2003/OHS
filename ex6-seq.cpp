#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a file
struct File {
    string name;
    int size;
};

// Function to allocate files sequentially on disk
void sequencedFileAllocation(const vector<File>& files, int diskSize) {
    int currentPosition = 0;

    // Allocate files sequentially
    for (const File& file : files) {
        if (currentPosition + file.size <= diskSize) {
            cout << "Allocating " << file.name << " at position " << currentPosition << endl;
            currentPosition += file.size;
        } else {
            cout << "Disk full! Cannot allocate " << file.name << endl;
            break;
        }
    }

    // Check for fragmentation
    if (currentPosition < diskSize) {
        cout << "Fragmentation present. Unused space: " << diskSize - currentPosition << " units" << endl;
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

    // Allocate files using sequenced file allocation
    sequencedFileAllocation(files, diskSize);

    return 0;
}
