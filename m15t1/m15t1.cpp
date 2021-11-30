#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int i_ind = 0, j_ind = 0;
    int d = 0;
    for (int i = 0; i < a.size(); ++i) {
        int sum = a[i];
        for (int j = i+1; j < a.size(); ++j) {
            sum += a[j];
            if (d < sum) {
                d = sum;
                i_ind = i;
                j_ind = j;
            }
        }
    }

    std::cout << i_ind << " " << j_ind << std::endl;
}