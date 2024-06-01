#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
}

int main() {
    for (int n : {50, 500, 1000}) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 1000;

        auto start = chrono::high_resolution_clock::now();
        selectionSort(arr, n);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "Для " << n << " элементов время сортировки: " << duration << " мс" << endl;
    }

    return 0;
}