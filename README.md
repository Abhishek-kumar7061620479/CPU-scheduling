// Non - premetive scheduling


#include <iostream>
using namespace std;

struct Process {
    int id, burstTime, arrivalTime, completionTime, waitingTime, turnaroundTime;
};

void fcfsScheduling(Process processes[], int n) {
    int currentTime = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    cout << "First-Come-First-Serve Scheduling:\n";

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        processes[i].completionTime = currentTime + processes[i].burstTime;
        currentTime = processes[i].completionTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;

        cout << "Process " << processes[i].id << " completed at time " << processes[i].completionTime << "\n";
    }

    cout << "Average Waiting Time: " << totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaroundTime / n << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].arrivalTime = 0;  // For simplicity, all processes arrive at time 0
    }

    fcfsScheduling(processes, n);
    return 0;
}
