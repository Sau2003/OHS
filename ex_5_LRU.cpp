#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class lru_page_replacement {
private:
    int frame_count;
    vector<int> frames;
    unordered_map<int, int> page_indices; // To keep track of the most recent usage index of pages

public:
    lru_page_replacement(int count) : frame_count(count) {}

    bool page_fault_occurred(int page, int current_index) {
        auto it = find(frames.begin(), frames.end(), page);
        if (it == frames.end()) { // Page fault occurred
            if (frames.size() < frame_count) {
                frames.push_back(page);
            } else {
                // Find the least recently used page
                int lru_page = frames[0];
                for (int frame : frames) {
                    if (page_indices[frame] < page_indices[lru_page]) {
                        lru_page = frame;
                    }
                }
                // Replace the least recently used page
                auto lru_it = find(frames.begin(), frames.end(), lru_page);
                *lru_it = page;
            }
            page_indices[page] = current_index;
            return true;
        } else { // No page fault occurred
            page_indices[page] = current_index; // Update the usage index
            return false;
        }
    }

    void print_frames() {
        cout << "Current frames: ";
        for (int frame : frames) {
            cout << frame << " ";
        }
        cout << endl;
    }
};

int main() {
    lru_page_replacement lru(3);
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4};
    int page_faults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        if (lru.page_fault_occurred(pages[i], i)) {
            page_faults++;
        }
        lru.print_frames();
    }

    cout << "Total number of page faults: " << page_faults << endl;

    return 0;
}
