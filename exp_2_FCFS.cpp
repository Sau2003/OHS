#include <iostream>

using namespace std;

void inputBurstTime(int n, int bt[]) {
    cout << "Enter Process Burst Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
    }
}

void calculateWaitingTime(int n, int bt[], int wt[]) {
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
            wt[i] += bt[j];
    }
}

void calculateTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void printResults(int n, int bt[], int wt[], int tat[]) {
    int avwt = 0, avtat = 0;

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time" << endl;

    for (int i = 0; i < n; i++) {
        avwt += wt[i];
        avtat += tat[i];
        cout << "\nP[" << i + 1 << "]\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }

    avwt /= n;
    avtat /= n;

    cout << "\n\nAverage Waiting Time: " << avwt;
    cout << "\nAverage Turnaround Time: " << avtat << endl;
}

int main() {
    int n, bt[20], wt[20], tat[20];

    cout << "Enter total number of processes (maximum 20): ";
    cin >> n;

    inputBurstTime(n, bt);
    calculateWaitingTime(n, bt, wt);
    calculateTurnaroundTime(n, bt, wt, tat);
    printResults(n, bt, wt, tat);

    return 0;
}
