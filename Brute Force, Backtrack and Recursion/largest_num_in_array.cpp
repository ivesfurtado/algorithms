#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr {3, 4, 1, 3, 4, 6, 4, 5, 3, 4};
    int num_of_appearances {0}, num {};

    for (size_t i {0}; i < arr.size(); i++) {
        int appearances {0};
        for (size_t j {i}; j < arr.size(); j++) {
            if (arr[j] == arr[i]) {
                appearances++;
            }
        }
        if (appearances > num_of_appearances) {
            num_of_appearances = appearances;
            num = arr[i];
        }
    }

    cout << num << " appeared " << num_of_appearances << " times." << endl;
    return 0;
}