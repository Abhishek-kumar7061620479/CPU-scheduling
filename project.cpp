// #include <iostream>
// #include <queue>
// using namespace std;

// struct Process {
//     int id, burstTime, remainingTime, arrivalTime;
// };

// void roundRobin(Process processes[], int n, int quantum) {
//     queue<int> readyQueue;
//     int currentTime = 0;
//     int totalTime = 0;
//     int completed = 0;
//     int waitingTime = 0, turnaroundTime = 0;
    
//     // Add all processes to the ready queue
//     for (int i = 0; i < n; i++) {
//         readyQueue.push(i);
//         totalTime += processes[i].burstTime;
//     }

//     cout << "Round Robin Scheduling (Quantum = " << quantum << "):\n";

//     while (completed < n) {
//         int index = readyQueue.front();
//         readyQueue.pop();
        
//         if (processes[index].remainingTime > 0) {
//             if (processes[index].remainingTime <= quantum) {
//                 currentTime += processes[index].remainingTime;
//                 processes[index].remainingTime = 0;
//                 completed++;
//                 cout << "Process " << processes[index].id << " completed at time " << currentTime << "\n";

//                 waitingTime += currentTime - processes[index].arrivalTime - processes[index].burstTime;
//                 turnaroundTime += currentTime - processes[index].arrivalTime;
//             } else {
//                 currentTime += quantum;
//                 processes[index].remainingTime -= quantum;
//                 readyQueue.push(index);
//             }
//         }
//     }

//     cout << "Average Waiting Time: " << (float)waitingTime / n << endl;
//     cout << "Average Turnaround Time: " << (float)turnaroundTime / n << endl;
// }

// int main() {
//     int n, quantum;
//     cout << "Enter the number of processes: ";
//     cin >> n;
//     Process processes[n];

//     cout << "Enter the time quantum for Round Robin: ";
//     cin >> quantum;

//     for (int i = 0; i < n; i++) {
//         processes[i].id = i + 1;
//         cout << "Enter burst time for process " << i + 1 << ": ";
//         cin >> processes[i].burstTime;
//         processes[i].remainingTime = processes[i].burstTime;
//         processes[i].arrivalTime = 0;  // For simplicity, all processes arrive at time 0
//     }

//     roundRobin(processes, n, quantum);
//     return 0;
// }


// non - premtive

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

