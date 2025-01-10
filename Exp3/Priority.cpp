//Nathan Cordeiro 22co09
//PRIORITY Algorithm
#include <iostream>
using namespace std;

int main() {
    int numProcesses; // Number of processes
    double totalWaitingTime = 0, totalTurnaroundTime = 0, averageWaitingTime, averageTurnaroundTime;

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    int processIds[numProcesses];  // Array to store process numbers
    int burstTimes[numProcesses];  // Array to store burst times
    int waitingTimes[numProcesses];  // Array to store waiting times
    int turnaroundTimes[numProcesses];  // Array to store turnaround times
    int completionTimes[numProcesses];  // Array to store completion times
    int priorities[numProcesses];  // Array to store priorities

    // Input burst times and priorities for each process
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << ":\n";
        cout << "Burst time: ";
        cin >> burstTimes[i];
        cout << "Priority: ";
        cin >> priorities[i];
        processIds[i] = i + 1; // Initialize process numbers
    }

    // Sort processes by priority (higher priority comes first)
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = i + 1; j < numProcesses; j++) {
            if (priorities[i] > priorities[j]) {
                swap(burstTimes[i], burstTimes[j]);
                swap(processIds[i], processIds[j]);
                swap(priorities[i], priorities[j]);
            }
        }
    }

    // Calculate completion time for each process
    completionTimes[0] = burstTimes[0];
    for (int i = 1; i < numProcesses; i++) {
        completionTimes[i] = completionTimes[i - 1] + burstTimes[i];
    }

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < numProcesses; i++) {
        waitingTimes[i] = completionTimes[i] - burstTimes[i];
        turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
    }

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < numProcesses; i++) {
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }

    // Calculate average waiting time and average turnaround time
    averageWaitingTime = totalWaitingTime / numProcesses;
    averageTurnaroundTime = totalTurnaroundTime / numProcesses;

    // Display the results
    cout << "\nProcess\t\tBT\t\tCT\t\tWT\t\tTT\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << processIds[i] << "\t\t" << burstTimes[i] << "\t\t" << completionTimes[i] << "\t\t" << waitingTimes[i] << "\t\t" << turnaroundTimes[i] << "\n";
    }

    cout << "\nAverage Waiting Time = " << averageWaitingTime << endl;
    cout << "Average Turnaround Time = " << averageTurnaroundTime << endl;

    // Displaying the Gantt chart
    cout << "\n\nGantt chart:";
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << processIds[i] << " ";
    }

    return 0;
}
