// LOOK
// 22co09 Nathan Cordeiro
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void look(std::vector<int> &requests, int start, int prev)
{
    int total_seek = 0;
    int current = start;
    int direction = (prev < start) ? 1 : -1; // Determine direction based on previous head position

    std::cout << "Seek Sequence: " << start;

    // Sort the requests array
    std::sort(requests.begin(), requests.end());

    // Find the position of the first request greater than or equal to the start
    auto pos = std::lower_bound(requests.begin(), requests.end(), start);

    if (direction == 1)
    {
        // Moving towards the end of the disk
        for (auto it = pos; it != requests.end(); ++it)
        {
            total_seek += std::abs(current - *it);
            current = *it;
            std::cout << " -> " << current;
        }
        for (auto it = pos - 1; it >= requests.begin(); --it)
        {
            total_seek += std::abs(current - *it);
            current = *it;
            std::cout << " -> " << current;
        }
    }
    else
    {
        // Moving towards the beginning of the disk
        for (auto it = pos - 1; it >= requests.begin(); --it)
        {
            total_seek += std::abs(current - *it);
            current = *it;
            std::cout << " -> " << current;
        }
        for (auto it = pos; it != requests.end(); ++it)
        {
            total_seek += std::abs(current - *it);
            current = *it;
            std::cout << " -> " << current;
        }
    }

    std::cout << "\nTotal Seek Time: " << total_seek << std::endl;
}

int main()
{
    int n, start, prev;
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
    std::cout << "Enter previous request position: ";
    std::cin >> prev;

    look(requests, start, prev);

    return 0;
}
