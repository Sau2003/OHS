#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class fifo_page_replacement{
    private:
    int frame_count;
    vector<int> frames;

    public:
    fifo_page_replacement(int count): frame_count(count){}

    bool page_fault_occurred(int page){
        if (find(frames.begin(),frames.end(),page)==frames.end()){
            if (frames.size() < frame_count){
                frames.push_back(page);
                return true;  // Page fault occurred
            }
            else{
                frames.erase(frames.begin());
                frames.push_back(page);
                return true;  // Page fault occurred
            }
        }
        return false;  // No page fault occurred
    }

    void print_frames(){
        cout<<"Current frames ";
        for (int frame: frames){
            cout<<frame<<" ";
        }
        cout<<endl;
    }
};

int main(){
    fifo_page_replacement fifo(3);
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4};
    int page_faults = 0;

    for (int page: pages){
        if (fifo.page_fault_occurred(page)) {
            page_faults++;
        }
        fifo.print_frames();
    }

    cout << "Total number of page faults: " << page_faults << endl;

    return 0;
}
