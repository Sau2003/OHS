#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int cal_seek_time(const vector<int>&requests,int head,int upper_limit){
    int total_seek_time=0;
    int curr_track=head;

    vector<int> sorted_requests=requests;
    sort(sorted_requests.begin(),sorted_requests.end());

    // Perform cscan
    int idx=0;
    while (idx<sorted_requests.size() && sorted_requests[idx]<head){
        idx++;
    }

    // scan from head  to upper limit
    for (int i=idx;i<sorted_requests.size();++i){
        total_seek_time+=abs(sorted_requests[i]-curr_track);
        curr_track=sorted_requests[i];
    }

    // for the req above the upper limit 
    total_seek_time+=abs(upper_limit-curr_track);

    // scan from beginning to the head 
    for (int i=0; i<idx;++i){
        total_seek_time+=abs(sorted_requests[i]-curr_track);
        curr_track=sorted_requests[i];
    }
    return total_seek_time;

}


int main() {
    // Example requests
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};

    // Initial head position
    int initial_head = 53;

    // Upper limit of disk
    int upper_limit = 199;

    // Calculate total seek time
    int total_seek_time = cal_seek_time(requests, initial_head, upper_limit);

    // Output total seek time
    cout << "Total Seek Time using C-SCAN: " << total_seek_time << endl;

    return 0;
}

