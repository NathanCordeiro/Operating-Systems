#include <iostream>
using namespace std;
#define MAX 50
int main()
{
    int n;                 // number of referenced strings
    int fs;                // frame size
    int available, pf = 0; // available = 0 means page is to be replaced
    int frame[MAX];        // to store frames
    int page[MAX];         // to store referenced pages
    cout << "Enter the number of referenced strings: ";
    cin >> n;
    cout << "Enter the referenced pages: ";
    for (int i = 0; i < n; i++)
        cin >> page[i];
    cout << "Enter the frame size: ";
    cin >> fs;
    // Initialize frames
    for (int i = 0; i < fs; i++)
    {
        frame[i] = -1; // -1 means empty frame
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
                available = 1; // Page is found
                break;
            }
        }
        // If the page is not found in the frame, replace it
        if (available == 0)
        {
            // Find the Optimal page to replace
            int index = -1;
            int farthest = i; // Initialize to current index
            for (int k = 0; k < fs; k++)
            {
                // Find the next occurrence of frame[k]
                int j;
                for (j = i + 1; j < n; j++)
                {
                    if (frame[k] == page[j])
                    {
                        break;
                    }
                }
                // If not found, replace this page
                if (j == n)
                {
                    index = k; // Found a frame that is not needed anymore
                    break;
                }
                // Check if this frame is used farthest in the future
                if (j > farthest)
                {
                    farthest = j;
                    index = k;
                }
            }
            frame[index] = page[i]; // Replace the page

            pf++; // Increment page fault count
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
