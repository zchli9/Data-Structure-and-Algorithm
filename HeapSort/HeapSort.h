#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <vector>
#include <algorithm>
using namespace std;
template<typename T>
void heapSort(vector<T>& vec) {
    make_heap(vec.begin(), vec.end()); // 创建一个最大堆
    for (auto it = vec.end() - 1; it != vec.begin() - 1; --it) {
        pop_heap(vec.begin(), it + 1); // 将最大元素放到最后
    }
}


#endif

