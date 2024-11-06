#include <iostream>
using namespace std;
#define MAX 50
int main()
{
    int n;                        // number of referenced strings
    int fs;                       // frame size
    int available, j = 0, pf = 0; // available = 0 means page is to be replaced
    int frame[MAX];               // to store frames
    int page[MAX];                // to store referenced pages
    int lastExtend[MAX];          // to track the last used time for each frame
    cout << "Enter the number of referenced strings: ";
    cin >> n;
    cout << "Enter the referenced pages: ";
    for (int i = 0; i < n; i++)
        cin >> page[i];
    cout << "Enter the frame size: ";
    cin >> fs;
    // Initialize frames and lastExtend
    for (int i = 0; i < fs; i++)
    {
        frame[i] = -1;     // -1 means empty frame
        lastExtend[i] = 0; // Initialize last used times
    }
    cout << "\nPages\t\tFrame\n";
    for (int i = 0; i < n; i++)
    {
        available = 0; // Reset availability for each page reference
        cout << page[i] << "\t\t";
        // Check if page is already in the frame
        for (int k = 0; k < fs; k++)
        {
            if (frame[k] == page[i])
            {
                available = 1;         // Page is found
                lastExtend[k] = i + 1; // Update last used time
                break;
            }
        }
        // If the page is not found in the frame, replace it
        if (available == 0)
        {
            // Find the LRU page to replace
            int min = lastExtend[0];
            int index = 0;
            for (int k = 1; k < fs; k++)
            {
                if (lastExtend[k] < min)
                {
                    min = lastExtend[k];
                    index = k;
                }
            }
            frame[index] = page[i];    // Replace the LRU page
            lastExtend[index] = i + 1; // Update last used time for the new page
            pf++;                      // Increment page fault count
        }
        // Display current state of the frame
        for (int k = 0; k < fs; k++)
        {
            cout << frame[k] << " ";
        }
        cout << endl;
    }
    cout << "\nTotal Page Faults: " << pf << endl;
    return 0;
}
