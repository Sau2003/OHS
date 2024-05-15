#include <iostream>

using namespace std;

void inputBurstTime(int n, int bt[]) {
    cout << "Enter Burst Time for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
    }
}

void calculateWaitingTime(int n, const int bt[], int wt[], int quantum_time) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0;

    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false;

                if (rem_bt[i] > quantum_time) {
                    t += quantum_time;
                    rem_bt[i] -= quantum_time;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done)
            break;
    }
}

void calculateTurnaroundTime(int n, const int bt[], const int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void printResults(int n, const int bt[], const int wt[], const int tat[]) {
    int avwt = 0, avtat = 0;

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time" << endl;

    for (int i = 0; i < n; i++) {
        avwt += wt[i];
        avtat += tat[i];
        cout << "P[" << i + 1 << "]\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    avwt /= n;
    avtat /= n;

    cout << "\nAverage Waiting Time: " << avwt << endl;
    cout << "Average Turnaround Time: " << avtat << endl;
}

int main() {
    int n, quantum_time;

    cout << "Enter total number of processes (maximum 20): ";
    cin >> n;

    cout << "Enter time quantum: ";
    cin >> quantum_time;

    int bt[20], wt[20], tat[20];

    inputBurstTime(n, bt);

    calculateWaitingTime(n, bt, wt, quantum_time);
    calculateTurnaroundTime(n, bt, wt, tat);
    printResults(n, bt, wt, tat);

    return 0;
}
