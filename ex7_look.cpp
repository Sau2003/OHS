#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int cal_seek_time(const vector<int>& requests, int head) {
    int total_seek_time = 0;
    int curr_track = head;

    // Sort requests to ensure they are in ascending order
    vector<int> sorted_requests = requests;
    sort(sorted_requests.begin(), sorted_requests.end());

    // Find the index of the current head position
    auto it = lower_bound(sorted_requests.begin(), sorted_requests.end(), head);
    int idx = distance(sorted_requests.begin(), it);

    // Forward scan from head position
    for (int i = idx; i < sorted_requests.size(); ++i) {
        total_seek_time += abs(sorted_requests[i] - curr_track);
        curr_track = sorted_requests[i];
    }

    // Backward scan from head position
    for (int i = idx - 1; i >= 0; --i) {
        total_seek_time += abs(sorted_requests[i] - curr_track);
        curr_track = sorted_requests[i];
    }

    return total_seek_time;
}

int main() {
    // Example requests
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};

    // Initial head position
    int initial_head = 53;

    // Calculate total seek time using LOOK algorithm
    int total_seek_time = cal_seek_time(requests, initial_head);

    // Output total seek time
    cout << "Total Seek Time using LOOK: " << total_seek_time << endl;

    return 0;
}
