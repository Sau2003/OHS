#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class OptimalPageReplacement {
private:
    int frame_count;
    vector<int> frames;
    unordered_map<int, vector<int>> page_table;

public:
    OptimalPageReplacement(int count) : frame_count(count) {}

    bool page_fault_occurred(int page) {
        if (find(frames.begin(), frames.end(), page) == frames.end()) {
            if (frames.size() < frame_count) {
                frames.push_back(page);
            } else {
                int farthest_index = -1;
                int page_to_replace = -1;

                for (int i = 0; i < frames.size(); ++i) {
                    if (page_table[frames[i]].empty()) {
                        page_to_replace = frames[i];
                        break;
                    } else {
                        auto it = find(page_table[frames[i]].begin(), page_table[frames[i]].end(), page);
                        if (it == page_table[frames[i]].end()) {
                            page_to_replace = frames[i];
                            break;
                        } else {
                            int distance = std::distance(page_table[frames[i]].begin(), it);
                            if (distance > farthest_index) {
                                farthest_index = distance;
                                page_to_replace = frames[i];
                            }
                        }
                    }
                }

                replace_page(page, page_to_replace); 
            }

            page_table[page].push_back(frames.size() - 1);
            return true; // Page fault occurred
        }
        return false; // No page fault occurred
    }

    void replace_page(int new_page, int old_page) {
        auto it = find(frames.begin(), frames.end(), old_page);
        *it = new_page;
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
    OptimalPageReplacement optimal(3);
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4};
    int page_faults = 0;

    for (int page : pages) {
        if (optimal.page_fault_occurred(page)) {
            page_faults++;
        }
        optimal.print_frames();
    }

    cout << "Total number of page faults: " << page_faults << endl;

    return 0;
}
