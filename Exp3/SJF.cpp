//Nathan Cordeiro 22co09
//SJF Algorithm
#include <iostream>
using namespace std;

int main() {
    int numProcesses; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    int processIds[numProcesses]; // Array to store process numbers
    int burstTimes[numProcesses]; // Array to store burst times
    int waitingTimes[numProcesses]; // Array to store waiting times
    int turnaroundTimes[numProcesses]; // Array to store turnaround times
    int completionTimes[numProcesses]; // Array to store completion times

    cout << "\nEnter burst times for each process:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> burstTimes[i];
        processIds[i] = i + 1; // Initialize process numbers
    }

    // Sort processes based on burst times (SJF - Shortest Job First)
    for (int i = 0; i < numProcesses; i++) {
        for (int j = i + 1; j < numProcesses; j++) {
            if (burstTimes[i] > burstTimes[j]) {
                swap(burstTimes[i], burstTimes[j]);
                swap(processIds[i], processIds[j]);
            }
        }
    }

    // Calculate completion time for each process
    completionTimes[0] = burstTimes[0]; // The first process's completion time is its burst time
    for (int i = 1; i < numProcesses; i++) {
        completionTimes[i] = completionTimes[i - 1] + burstTimes[i];
    }

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < numProcesses; i++) {
        waitingTimes[i] = completionTimes[i] - burstTimes[i];
        turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
    }

    // Calculate average waiting time and average turnaround time
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;
    for (int i = 0; i < numProcesses; i++) {
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }
    double averageWaitingTime = totalWaitingTime / numProcesses;
    double averageTurnaroundTime = totalTurnaroundTime / numProcesses;

    // Display the results including averages
    cout << "\nProcess\t\tBT\t\tCT\t\tWT\t\tTT\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << processIds[i] << "\t\t" << burstTimes[i] << "\t\t" << completionTimes[i] << "\t\t" << waitingTimes[i] << "\t\t" << turnaroundTimes[i] << "\n";
    }

    cout << "\nThe average waiting time: " << averageWaitingTime << "\n";
    cout << "The average turnaround time: " << averageTurnaroundTime << "\n";

    // Displaying the Gantt chart
    cout << "\n\nGantt chart:";
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << processIds[i] << " ";
    }

    return 0;
}
