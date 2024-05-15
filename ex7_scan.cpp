#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int cal_seek_time(const vector<int> &request, int head){
    int total_seek_time=0;
    int curr_track=head;

    vector<int>sorted_requests=request;
    sorted_requests.push_back(head);
    sort(sorted_requests.begin(),sorted_requests.end());

    auto it= find(sorted_requests.begin(),sorted_requests.end(),head);
    int index=distance(sorted_requests.begin(),it);

    // Moving right 
    for (int i=index;i<sorted_requests.size();++i){
        total_seek_time+=abs(sorted_requests[i]-curr_track);
        curr_track=sorted_requests[i];
    }

    // Moving left
    for(int i=index-1;i>=0;--i){
        total_seek_time+=abs(sorted_requests[i]-curr_track);
        curr_track=sorted_requests[i];
    }
    return total_seek_time;
}

int main(){
    vector<int> request={98, 183, 37, 122, 14, 124, 65, 67};
    int initial_head=53;
    int total_seek_time=cal_seek_time(request,initial_head);
    cout<<"Total seek time is "<<total_seek_time;
}