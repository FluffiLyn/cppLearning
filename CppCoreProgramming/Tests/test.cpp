#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class RandomGenerator {
public:
    int randInt(int i, int j) {
        return i + rand() % (j - i + 1);
    }
};

double generatePermutation3(int* a, RandomGenerator& r, int N) {
    auto start = high_resolution_clock::now();
    
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1;
    }
    
    for (int i = 1; i < N; ++i) {
        swap(a[i], a[r.randInt(0, i)]);
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

int main() {
    int N_values[] = {100000, 200000, 400000, 800000, 1600000, 3200000, 6400000};
    int num_trials = 10;
    
    for (auto N : N_values) {
        int* a = new int[N];
        RandomGenerator r;
        
        double total_time = 0;
        for (int trial = 0; trial < num_trials; ++trial) {
            total_time += generatePermutation3(a, r, N);
        }
        
        cout << "Algorithm 3, N = " << N << ", Average Time: " << total_time / num_trials << " microseconds" << endl;
        delete[] a;
    }
    
    return 0;
}