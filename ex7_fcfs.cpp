#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int cal_seek_time(const vector<int>&request,int head){
    int total_seek_time=0;
    int curr_track=head;

    for(int track: request){
        total_seek_time+=abs(track-curr_track);
        curr_track=track;
    }
    return total_seek_time;

}

int main(){
    vector<int> request={98, 183, 37, 122, 14, 124, 65, 67};
    int initial_head=53;
    int total_seek_time=cal_seek_time(request,initial_head);
    cout<<"Total seek time is"<<total_seek_time;
    return 0;
}