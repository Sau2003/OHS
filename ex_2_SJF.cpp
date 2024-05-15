#include <iostream>
#include <string>
using namespace std;

void sorted_execution(int n, int bt[], string names[]) {
    cout << "\nEnter the execution time of the processes: ";
    for (int i = 0; i < n; i++)
        cin >> bt[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]){
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                string Temp_names = names[i];
                names[i] = names[j];
                names[j] = Temp_names;
            }
        }
    }

    cout << "Execution times after sorting";

    for (int i = 0; i < n; i++)
        cout << bt[i] << " ";
}

void calculateWaitingTime(int n, int bt[], int wt[]) {
    wt[0] = 0; // waiting time for the first process is 0

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

void printResults(int n, int bt[], int wt[], int tat[], string names[]) {
    int avwt = 0, avtat = 0;

    // Print headers
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    // Loop through processes in sorted order and print results
    for (int i = 0; i < n; i++) {
        avwt += wt[i];
        avtat += tat[i];
        //printf("\n%s\t\t%d\t\t%d\t\t%d", names[i].c_str(), bt[i], wt[i], tat[i]);
        cout << "\nP[" << i + 1 << "]\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }

    // Calculate averages
    avwt /= n;
    avtat /= n;

    // Print average waiting time and average turnaround time
    printf("\n\nAverage Waiting Time: %d", avwt);
    printf("\nAverage Turnaround Time: %d\n", avtat);
}


int main() {
    int n, bt[20], wt[20], tat[20];
    string names[20];

    printf("Enter total number of processes (maximum 20):");
    scanf("%d", &n);

    // Input process names
    for (int i = 0; i < n; i++) {
        cout << "Enter name for process " << i + 1 << ": ";
        cin >> names[i];
    }

    sorted_execution(n, bt, names);
    calculateWaitingTime(n, bt, wt);
    calculateTurnaroundTime(n, bt, wt, tat);
    printResults(n, bt, wt, tat, names);

    return 0;
}
