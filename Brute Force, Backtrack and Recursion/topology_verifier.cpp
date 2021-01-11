#include <iostream>
#include <vector>

using namespace std;

bool is_ring_topology(vector<vector<int>> topology);
bool is_star_topology(vector<vector<int>> topology);
bool is_fully_connected_topology(vector<vector<int>> topology);



int main() {
    vector<vector<int>> ring {
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0}
    };
    vector<vector<int>> star {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };
    vector<vector<int>> fully {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };

    cout << "Is it a ring topology? " << ((is_ring_topology(ring)) ? "True":"False") << "!" << endl;
    cout << "Is it a star topology? " << ((is_star_topology(star)) ? "True":"False") << "!" << endl;
    cout << "Is it a fully connected topology? " << ((is_fully_connected_topology(fully)) ? "True":"False") << "!" << endl;
    
    return 0;
}

bool is_ring_topology(vector<vector<int>> topology) {
    vector<int> ring {};
    for (size_t i {0}; i < topology.size(); i++) {
        ring.push_back(0);
    }

    for (size_t i {0}; i < topology.size(); i++) {
        for (size_t j {0}; j < topology[i].size(); j++) {
            if (topology[i][j] == 1) {
                ring[j] += 1;
            }
        }
    }

   for (size_t i {0}; i < ring.size(); i++) {
       if (ring[i] != 2) {
           return false;
       }
   }

   return true;
}

bool is_star_topology(vector<vector<int>> topology) {
    vector<int> star {};
    for (size_t i {0}; i < topology.size(); i++) {
        star.push_back(0);
    }

    for (size_t i {0}; i < topology.size(); i++) {
        for (size_t j {0}; j < topology[i].size(); j++) {
            if (topology[i][j] == 1) {
                star[i] += 1;
            }
        }
    }

    int sum {0};
    for (size_t i {0}; i < star.size(); i++) {
       if (star[i] != 1 && star[i] != (topology.size() - 1)) {
           return false;
       } else if (star[i] == topology.size()) {
           sum++;
           if (sum != 1) {
               return false;
           }
       }
    }

    return true;
}
bool is_fully_connected_topology(vector<vector<int>> topology) {
    for (size_t i {0}; i < topology.size(); i++) {
        int sum {0};
        for (size_t j {0}; j < topology[i].size(); j++) {
            if (topology[i][j] == 1) {
                sum++;
            }
        }
        if (sum != (topology.size() - 1) && sum != 0) {
            return false;
        }
    }

    return true;
}