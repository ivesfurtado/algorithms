#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> disk {1, 0, 1, 0, 1, 0, 1, 0};
    // 0 = white and 1 = black.

    for (size_t i {0}; i < disk.size(); i++) {
        for (size_t j {i}; j < disk.size(); j++) {
            if (disk[j] < disk[i]) {
                int tmp = disk[j];
                disk[j] = disk[i];
                disk[i] = tmp;
            }
        }
    }

    for (size_t i {0}; i < disk.size(); i++) {
        cout << disk[i] << " ";
    }

    return 0;
}