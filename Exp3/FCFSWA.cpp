//Nathan Cordeiro 22co09
//FCFSWA Algorithm
#include <iostream>
using namespace std;

int main() {
    int numProcesses; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    int processIds[numProcesses]; // Array to store process numbers
    int burstTimes[numProcesses]; // Array to store burst times
    int arrivalTimes[numProcesses]; // Array to store arrival times
    int waitingTimes[numProcesses]; // Array to store waiting times
    int turnaroundTimes[numProcesses]; // Array to store turnaround times
    int completionTimes[numProcesses]; // Array to store completion times

    // Input burst times and arrival times for each process
    cout << "Enter burst times and arrival times for each process:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << ":\n";
        cout << "Burst Time: ";
        cin >> burstTimes[i];
        cout << "Arrival Time: ";
        cin >> arrivalTimes[i];
        processIds[i] = i + 1; // Initialize process numbers
    }

    // Sort processes based on arrival times
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = 0; j < numProcesses - i - 1; j++) {
            if (arrivalTimes[j] > arrivalTimes[j + 1]) {
                swap(arrivalTimes[j], arrivalTimes[j + 1]);
                swap(burstTimes[j], burstTimes[j + 1]);
                swap(processIds[j], processIds[j + 1]);
            }
        }
    }

    // Perform FCFS scheduling
    int currentTime = 0; // Initialize the current time
    for (int i = 0; i < numProcesses; i++) {
        if (arrivalTimes[i] > currentTime) {
            currentTime = arrivalTimes[i];
        }
        waitingTimes[i] = currentTime - arrivalTimes[i];
        turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
        currentTime += burstTimes[i];

        // Calculate completion time for each process
        completionTimes[0] = burstTimes[0]; // The first process's completion time is its burst time
        for (int i = 1; i < numProcesses; i++) {
            completionTimes[i] = completionTimes[i - 1] + burstTimes[i];
        }
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

    cout << "\nAverage Waiting Time: " << averageWaitingTime << "\n";
    cout << "Average Turnaround Time: " << averageTurnaroundTime << "\n";

    // Displaying the Gantt chart
    cout << "\n\nGantt chart:";
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << processIds[i] << " ";
    }

    return 0;
}
