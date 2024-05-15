#include <iostream>
#include <algorithm> // For find
#include <vector>
#include <cmath>
#include <limits> // For numeric_limits

using namespace std;

int calculateTotalSeekTime(const vector<int>& requests, int head) {
    int total_seek_time = 0;
    int current_track = head;

    vector<int> remaining_requests = requests;

    while (!remaining_requests.empty()) {
        int closest_request = -1;
        int min_distance = numeric_limits<int>::max();

        for (int track : remaining_requests) {
            int distance = abs(track - current_track);
            if (distance < min_distance) {
                min_distance = distance;
                closest_request = track;
            }
        }

        total_seek_time += min_distance;
        current_track = closest_request;

        auto it = find(remaining_requests.begin(), remaining_requests.end(), closest_request);
        if (it != remaining_requests.end()) {
            remaining_requests.erase(it);
        }
    }

    return total_seek_time;
}

int main() {
    // Example requests
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};

    // Initial head position
    int initial_head = 53;

    // Calculate total seek time
    int total_seek_time = calculateTotalSeekTime(requests, initial_head);

    // Output total seek time
    cout << "Total Seek Time using SSTF: " << total_seek_time << endl;

    return 0;
}
