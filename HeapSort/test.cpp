#include <iostream>
#include <chrono>
#include <random>
#include "HeapSort.h"
using namespace std;

template<typename T>
bool check(const vector<T>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            // cout << "Sorting failed at index " << i << ": " << vec[i] << " < " << vec[i - 1] << endl;
            return false; 
        }
    }
    return true;
}

int main() {
    const int N = 1000000;
    // 产生随机序列
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);

    vector<int> randomSeq(N), sortedSeq(N), reverseSeq(N), duplicateSeq(N);
    
    // 随机序列
    for (int i = 0; i < N; ++i) {
        randomSeq[i] = dist(gen);
    }

    // 有序序列
    sortedSeq = randomSeq;
    sort(sortedSeq.begin(), sortedSeq.end());

    // 逆序序列
    reverseSeq = sortedSeq;
    reverse(reverseSeq.begin(), reverseSeq.end());

    // 部分元素重复序列
    for (int i = 0; i < N; ++i) {
        duplicateSeq[i] = dist(gen);
    }
    for (int i = 0; i < N / 10; ++i) {
        duplicateSeq[i] = duplicateSeq[i * 10];
    }
    // 测试我的堆排序
    auto testHeapSort = [](vector<int>& seq, const string& name) {
        auto start = chrono::high_resolution_clock::now();
        heapSort(seq);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if(check(seq)){
            cout << "MyHeapsort(" << name << ") - Time: " << duration.count() << " seconds." << endl;
        }
        else{
            cout << "MyHeapsort(" << name << ") - Failed sorting check!" << endl;
        }
        
    };

    // 测试std::sort_heap
    auto testStdSortHeap = [](vector<int>& seq, const string& name) {
        auto start = chrono::high_resolution_clock::now();
        make_heap(seq.begin(), seq.end());
        sort_heap(seq.begin(), seq.end());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if(check(seq)){
            cout << "std::sort_heap (" << name << ") - Time: " << duration.count() << " seconds." << endl;
        }
        else{
            cout << "std::sort_heap (" << name << ") - Failed sorting check!" << endl;
        }
    };

    // Perform tests
    testHeapSort(randomSeq, "Random Sequence");
    testStdSortHeap(randomSeq, "Random Sequence");

    testHeapSort(sortedSeq, "Sorted Sequence");
    testStdSortHeap(sortedSeq, "Sorted Sequence");

    testHeapSort(reverseSeq, "Reverse Sequence");
    testStdSortHeap(reverseSeq, "Reverse Sequence");

    testHeapSort(duplicateSeq, "Duplicate Sequence");
    testStdSortHeap(duplicateSeq, "Duplicate Sequence");

    return 0;
}
