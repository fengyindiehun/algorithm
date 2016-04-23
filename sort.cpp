#include <iostream>
#include <stdint.h>

void insert_sort(uint32_t *a , size_t len) {
    for (size_t i = 1; i < len; ++i) {
        for (size_t j = i; j > 0; --j) {
            if (a[j] > a[j-1]) {
                break;
            }
            uint32_t tmp = a[j];
            a[j] = a[j-1];
            a[j-1] = tmp;
        }
    }
}

void bubble_sort(uint32_t *a, size_t len) {
    for (size_t i = 0; i < len-1; ++i) {
        for (size_t j = 0; j+1 < len-i; ++j) {
            if (a[j] > a[j+1]) {
                uint32_t tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void choose_sort(uint32_t *a, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        uint32_t min_idx = i;
        for (size_t j = i+1; j < len; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        uint32_t tmp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = tmp;
    }
}

void do_quick_sort(uint32_t *a, uint32_t left, uint32_t right) {
    if (left >= right) return;
    uint32_t i = left;
    uint32_t j = right;
    uint32_t num = a[left];
    while (i < j) {
        while (i < j && a[j] > num) {
            --j;
        }
        if (i == j) break;

        while (i < j && a[i] < num) {
            ++i;
        }
        if (i == j) break;

        uint32_t tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    if (a[i] < num) {
        uint32_t tmp = a[left];
        a[left] = a[i];
        a[i] = tmp;
    }

    do_quick_sort(a, left, i-1);
    do_quick_sort(a, i+1, right);
}

void quick_sort(uint32_t *a, size_t len) {
    do_quick_sort(a, 0, len-1);
}

void heap_sort_exchange(uint32_t *a, uint32_t idx, uint32_t len_idx) {
    uint32_t left = 2 * idx + 1;
    uint32_t right = left + 1;
    uint32_t max_idx = idx;
    if (left > len_idx) {
        return;
    }
    if (left <= len_idx && a[left] > a[max_idx]) {
        max_idx = left;
    }
    if (right <= len_idx && a[right] > a[max_idx]) {
        max_idx = right;
    }
    if (max_idx != idx) {
        uint32_t tmp = a[idx];
        a[idx] = a[max_idx];
        a[max_idx] = tmp;
        heap_sort_exchange(a, max_idx, len_idx);
    }
}

void do_heap_sort(uint32_t *a, size_t len) {
    uint32_t begin_idx = len/2 -1;
    for (int i = begin_idx; i >= 0; --i) {
        heap_sort_exchange(a, i, len-1);
    }
}

void heap_sort(uint32_t *a, size_t len) {
    for (uint32_t i = 0; i < len; ++i) {
        do_heap_sort(a, len-i);
        uint32_t tmp = a[0];
        a[0] = a[len-1-i];
        a[len-1-i] = tmp;
    }
}

void print(uint32_t* a, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        std::cout << a[i] << ",";
    }
    std::cout << std::endl;
}

int main() {
    uint32_t a[6] = {2, 1, 3, 5, 4, 6};
    //insert_sort(a, sizeof(a) / sizeof(a[0]));
    //bubble_sort(a, sizeof(a) / sizeof(a[0]));
    //choose_sort(a, sizeof(a) / sizeof(a[0]));
    //quick_sort(a, sizeof(a) / sizeof(a[0]));
    heap_sort(a, sizeof(a) / sizeof(a[0]));
    print(a, sizeof(a) / sizeof(a[0]));
    return 0;
}
