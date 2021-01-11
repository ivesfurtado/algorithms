#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr {4, 2, 7, 6, 3, 8, 1};
    int sum {0}, num {};
    int full_arr_size = arr.size() + 1;
    int total_sum = (full_arr_size * (full_arr_size + 1) + 1) / 2;
    cout << total_sum << endl;

    for (size_t i {0}; i < arr.size(); i++) {
        sum += arr[i];
    }

    num = total_sum - sum;
    cout << "The num is: " << num << endl;
}