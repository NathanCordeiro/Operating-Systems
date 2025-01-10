//Nathan Cordeiro 22co09
//SJFWA Algorithm
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    int processIds[numProcesses];       // Array to store process numbers
    int burstTimes[numProcesses];       // Array to store burst times
    int completionTimes[numProcesses];  // Array to store completion times
    int waitingTimes[numProcesses];     // Array to store waiting times
    int turnaroundTimes[numProcesses];  // Array to store turnaround times
    int arrivalTimes[numProcesses];     // Array to store arrival times
    int currentTime = 0;                // Current time tracker
    int minBurstIndex;
    float totalWaitingTime = 0, totalTurnaroundTime = 0, averageWaitingTime, averageTurnaroundTime;

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
    for (int i = 0; i < numProcesses; i++) {
        for (int j = i + 1; j < numProcesses; j++) {
            if (arrivalTimes[i] > arrivalTimes[j]) {
                swap(arrivalTimes[i], arrivalTimes[j]);
                swap(burstTimes[i], burstTimes[j]);
                swap(processIds[i], processIds[j]);
            }
        }
    }

    currentTime = arrivalTimes[0];

    for (int i = 0; i < numProcesses; i++) {
        minBurstIndex = -1;
        int minBurstTime = INT_MAX;

        // Find the process with the minimum burst time that has arrived
        for (int j = i; j < numProcesses; j++) {
            if (arrivalTimes[j] <= currentTime && burstTimes[j] < minBurstTime) {
                minBurstTime = burstTimes[j];
                minBurstIndex = j;
            }
        }

        if (minBurstIndex != -1) {
            // Swap the processes to schedule the shortest job next
            swap(arrivalTimes[i], arrivalTimes[minBurstIndex]);
            swap(burstTimes[i], burstTimes[minBurstIndex]);
            swap(processIds[i], processIds[minBurstIndex]);

            currentTime += burstTimes[i];
            completionTimes[i] = currentTime;
            waitingTimes[i] = completionTimes[i] - burstTimes[i] - arrivalTimes[i];
            turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
        } else {
            currentTime = arrivalTimes[i];
            i--;
        }
    }

    for (int i = 0; i < numProcesses; i++) {
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }

    averageWaitingTime = totalWaitingTime / numProcesses;
    averageTurnaroundTime = totalTurnaroundTime / numProcesses;

    // Display the results including averages
    cout << "Process\t\tCT\t\tBT\t\tWT\t\tTT" << endl;
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << processIds[i] << "\t\t" << completionTimes[i] << "\t\t" << burstTimes[i] << "\t\t" << waitingTimes[i] << "\t\t" << turnaroundTimes[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << averageWaitingTime << endl;
    cout << "Average Turnaround Time = " << averageTurnaroundTime << endl;

    // Displaying the Gantt chart
    cout << "\nGantt chart: ";
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << processIds[i] << " ";
    }

    return 0;
}
