#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <typename T>
int binary_search(T* arr, int size, T target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

void process_test_case(char data_type, int n, int q, string* data, string* queries) {
    if (data_type == 'i') {
        int* int_data = new int[n];
        int* int_queries = new int[q];
        for (int i = 0; i < n; ++i) {
            int_data[i] = stoi(data[i]);
        }
        for (int i = 0; i < q; ++i) {
            int_queries[i] = stoi(queries[i]);
        }
        for (int i = 0; i < q; ++i) {
            cout << binary_search(int_data, n, int_queries[i]) << endl;
        }
        delete[] int_data;
        delete[] int_queries;
    }
    else if (data_type == 's') {
        for (int i = 0; i < q; ++i) {
            cout << binary_search(data, n, queries[i]) << endl;
        }
    }
}

int main() {
    char data_type;
    int n, q;
    while (cin >> data_type >> n >> q) {
        string* data = new string[n];
        string* queries = new string[q];
        for (int i = 0; i < n; ++i) {
            cin >> data[i];
        }
        for (int i = 0; i < q; ++i) {
            cin >> queries[i];
        }
        process_test_case(data_type, n, q, data, queries);
        delete[] data;
        delete[] queries;
    }
    return 0;
}