//Nathan Cordeiro 22co09
//Priority WA Algorithm
#include <iostream>
using namespace std;

int main() {
    int numProcesses; // Number of processes
    int currentTime = 0, minPriority, k = 1;
    double totalWaitingTime = 0, totalTurnaroundTime = 0, averageWaitingTime, averageTurnaroundTime;

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    int processIds[numProcesses];  // Array to store process numbers
    int burstTimes[numProcesses];  // Array to store burst times
    int waitingTimes[numProcesses] = {0}; // Array to store waiting times, initialized to 0
    int turnaroundTimes[numProcesses];  // Array to store turnaround times
    int completionTimes[numProcesses];  // Array to store completion times
    int arrivalTimes[numProcesses];  // Array to store arrival times
    int priorities[numProcesses];  // Array to store priorities

    // Input burst times, arrival times, and priorities for each process
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << ":\n";
        cout << "Burst time: ";
        cin >> burstTimes[i];
        cout << "Arrival time: ";
        cin >> arrivalTimes[i];
        cout << "Priority: ";
        cin >> priorities[i];
        processIds[i] = i + 1; // Initialize process numbers
    }

    // Sort processes by arrival time (if equal, by burst time)
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = 0; j < numProcesses - i - 1; j++) {
            if (arrivalTimes[j] > arrivalTimes[j + 1] || (arrivalTimes[j] == arrivalTimes[j + 1] && burstTimes[j] > burstTimes[j + 1])) {
                swap(arrivalTimes[j], arrivalTimes[j + 1]);
                swap(burstTimes[j], burstTimes[j + 1]);
                swap(processIds[j], processIds[j + 1]);
                swap(priorities[j], priorities[j + 1]);
            }
        }
    }

    // Scheduling based on priority
    completionTimes[0] = arrivalTimes[0] + burstTimes[0];
    currentTime = completionTimes[0];

    for (int i = 1; i < numProcesses; i++) {
        minPriority = priorities[i];
        int minIndex = i;

        for (int j = i; j < numProcesses; j++) {
            if (arrivalTimes[j] <= currentTime && priorities[j] < minPriority) {
                minPriority = priorities[j];
                minIndex = j;
            }
        }

        // Swap the selected process to the current position
        swap(arrivalTimes[i], arrivalTimes[minIndex]);
        swap(burstTimes[i], burstTimes[minIndex]);
        swap(processIds[i], processIds[minIndex]);
        swap(priorities[i], priorities[minIndex]);

        // Update the time and calculate the completion time for the selected process
        currentTime += burstTimes[i];
        completionTimes[i] = currentTime;
    }

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < numProcesses; i++) {
        waitingTimes[i] = completionTimes[i] - arrivalTimes[i] - burstTimes[i];
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
    cout << "Process\tCT\tBT\tAT\tPrty\tWT\tTT" << endl;
    for (int i = 0; i < numProcesses; i++) {
        cout << "P" << processIds[i] << "\t" << completionTimes[i] << "\t" << burstTimes[i] << "\t" << arrivalTimes[i] << "\t" << priorities[i] << "\t" << waitingTimes[i] << "\t" << turnaroundTimes[i] << endl;
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
