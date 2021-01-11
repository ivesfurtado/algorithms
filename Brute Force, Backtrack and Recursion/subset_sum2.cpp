#include <iostream>
#include <vector>

using namespace std;

vector<int> BubbleSort(vector<int> set);
vector<int> SubSetSum (vector<int> set, vector<int> x, int i, int T, int parcial_sum, int subset_sum);

int main() {
    vector<int> set {1, 6, 7, 8, 4};
    vector<int> x{};

    int subset_sum {0};
    int full_sum {0};

    for (size_t i {0}; i < set.size(); i++) {
        full_sum += set[i];
        x.push_back(0);
    }
    if (full_sum % 2 != 0) {
        cout << "No subset." << endl;
        return 0;
    }
    subset_sum = full_sum / 2;
    
    set = BubbleSort(set);

    SubSetSum(set, x, 0, full_sum, 0, subset_sum);

    return 0;
}

vector<int> BubbleSort(vector<int> set) {
    for (size_t i {0}; i < set.size(); i++) {
        for (size_t j {i}; j < set.size(); j++) {
            if (set[j] < set[i]) {
                int tmp = set[j];
                set[j] = set[i];
                set[i] = tmp;
            }
        }
    }
    return set;
}

vector<int> SubSetSum (vector<int> set, vector<int> x, int i, int T, int parcial_sum, int subset_sum) {
    x[i] = 1;
    cout << set[i] << " ";
    
    if (parcial_sum + set[i] == subset_sum) {
        cout << "porraaaaaaaaaaa";
        for (size_t i {0}; i < set.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    } else {
        if ((parcial_sum + set[i] + set[i + 1]) <= subset_sum) {
            cout << "aaaaaaaaaaaaa " << endl;
            SubSetSum(set, x, i + 1, T - set[i], parcial_sum + set[i], subset_sum);
        }
    }
    if (((parcial_sum + T - set[i]) >= subset_sum) && ((T + set[i + 1]) <= subset_sum)) {
        x[i] = 0;
        cout << "bbbbbbbbbbbbbb " << endl;
        SubSetSum(set, x, i + 1, T - set[i], parcial_sum, subset_sum);
    }
}