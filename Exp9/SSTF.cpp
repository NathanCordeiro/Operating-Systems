// Shortest Seek Time First
// 22co09 Nathan Cordeiro
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

    void
    sstf(std::vector<int> &requests, int start)
{
    int total_seek = 0;
    int current = start;
    std::vector<bool> completed(requests.size(), false);

    std::cout << "Seek Sequence: " << start;

    for (size_t i = 0; i < requests.size(); i++)
    {
        int shortest = -1;
        int min_distance = std::numeric_limits<int>::max();

        for (size_t j = 0; j < requests.size(); j++)
        {
            if (!completed[j])
            {
                int distance = std::abs(current - requests[j]);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    shortest = j;
                }
            }
        }

        if (shortest != -1)
        {
            total_seek += min_distance;
            current = requests[shortest];
            completed[shortest] = true;
            std::cout << " -> " << current;
        }
    }

    std::cout << "\nTotal Seek Time: " << total_seek << std::endl;
}

int main()
{
    int n, start;
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

    sstf(requests, start);

    return 0;
}
