// First Come First Serve
// 22co09 Nathan Cordeiro
#include <iostream>
using namespace std;

int main()
{
    int currentPos, diskMovement=0, n, i;
    cout << "Enter the number of requests: ";
    cin >> n;
    int diskQueue[n];
    cout << "Enter the requests in the disk queue: ";
    for (i=0;i<n;i++)
        cin >> diskQueue[i];
    cout << "Enter the current position: ";
    cin >> currentPos;

    for (i=0;i<n;i++)
    {
        if (diskQueue[i]<currentPos)
        {
            diskMovement+=(currentPos-diskQueue[i]);
            currentPos=diskQueue[i];
        }
        else
        {
            diskMovement+=(diskQueue[i]-currentPos);
            currentPos=diskQueue[i];
        }

    }
    cout << "Total head movement in FCFS: " << diskMovement << endl;
    return 0;
}
