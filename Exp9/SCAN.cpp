// SCAN
// 22co09 Nathan Cordeiro
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void scan(std::vector<int> &requests, int start, int end, int prev)
{
    int total_seek = 0;
    int current = start;
    int direction = (prev < start) ? 1 : -1; // Determine direction based on previous head position
    std::cout << "Seek Sequence: " << start;

    // Sort the requests array
    std::sort(requests.begin(), requests.end());

    int pos = 0;
    while (pos < requests.size() && requests[pos] < start)
        pos++;

    if (direction == 1)
    {
        // Moving right
        for (int i = pos; i < requests.size(); i++)
        {
            total_seek += std::abs(current - requests[i]);
            current = requests[i];
            std::cout << " -> " << current;
        }
        total_seek += std::abs(current - end);
        current = end;
        std::cout << " -> " << current;
        for (int i = pos - 1; i >= 0; i--)
        {
            total_seek += std::abs(current - requests[i]);
            current = requests[i];
            std::cout << " -> " << current;
        }
    }
    else
    {
        // Moving left
        for (int i = pos - 1; i >= 0; i--)
        {
            total_seek += std::abs(current - requests[i]);
            current = requests[i];
            std::cout << " -> " << current;
        }
        total_seek += std::abs(current - 0);
        current = 0;
        std::cout << " -> " << current;
        for (int i = pos; i < requests.size(); i++)
        {
            total_seek += std::abs(current - requests[i]);
            current = requests[i];
            std::cout << " -> " << current;
        }
    }
    std::cout << "\nTotal Seek Time: " << total_seek << std::endl;
}

int main()
{
    int n, start, end, prev;
    std::cout << "Enter number of requests: ";
    std::cin >> n;

    std::vector<int> requests(n);
    std::cout << "Enter request sequence: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> requests[i];
    }

    std::cout << "Enter initial head position: ";
    std::cin >> start;
    std::cout << "Enter end of disk range: ";
    std::cin >> end;
    std::cout << "Enter previous request position: ";
    std::cin >> prev;

    scan(requests, start, end, prev);

    return 0;
}
