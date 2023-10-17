//
// This 'main' belongs to the 'algorithm_design',part of the 'linear_time' project
//
// Created by aaron on 23-10-10.
// Copyright (c) 2023 aaron. All rights reserved.
//
// The source file follows the GPL3.0 protocol and is distributed with the file.
// If you do not receive the GPL3.0 protocol ontology or you find a bug,
// please let me know (email: fly_aaron.li@outlook.com)

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void   random_data(std::vector<int> &data, int quantity, int min_number, int max_number);
void   print(std::vector<int> &data, int data_size, int k, char option);
size_t Randomized_Partition(std::vector<int> data, size_t low_index, size_t high_index);
int    Randomized_Select(std::vector<int> data, size_t reference_element_index, size_t end_element_index, size_t k);
size_t Partition(std::vector<int> &data, size_t low_index, size_t high_index, int x);
int    Linear_Select(std::vector<int> &data, size_t reference_element_index, size_t end_element_index, size_t k);

int main() {
    std::vector<int> data;
    int              data_size;
    int              k;
    char             option;

    std::cout << "您想要的序列大小为：";
    std::cin >> data_size;
    std::cout << "如果想要获取第x小的元素，请输入x值：";
    std::cin >> k;
    std::cout << "是否打印序列？(y/n)";
    std::cin >> option;
    print(data, data_size, k, option);
    return 0;
}

/**
 * @title
 * random_data
 * @memberof
 * data : Sequence object of elements to be generated
 * @memberof
 * quantity : The number of sequences to be produced
 * @memberof
 * min_number : Minimum value of the random number generation interval
 * @memberof
 * max_number : Maximum value of the random number generation interval
 * @description
 * Obtain uniformly distributed random numbers through the random number engine
 */
void random_data(std::vector<int> &data, int quantity, int min_number, int max_number) {
    if (quantity > max_number) {
        std::cerr << "The maximum random number is less than the number of target sequences!";
        return;
    }
    std::random_device                 device;
    /** Generate unpredictable random numbers */
    std::default_random_engine         engine(device());
    std::uniform_int_distribution<int> distribution_number(min_number, max_number);
    for (int i = 0; i < quantity; ++i) {
        data.push_back(distribution_number(engine));
    }
}

/**
 * @title
 * print
 * @description
 * Printing the sorted sequence obtained by the algorithm,
 * the algorithm name, and the sorting consumes time(ms)
 * @memberof
 * data: Enter the sequence to be sorted
 * @memberof
 * data_size: Sequence size
 * @memberof
 * k: Ascending index value(the "k"th smallest element in the sequence)
 * @memberof
 * option: Whether to print sequence option
 * @return
 * void
 */
void print(std::vector<int> &data, int data_size, int k, char option) {
    if (k <= 0) {
        std::cerr << "您输入的k值错误！";
        return;
    }

    /** Get random number */
    random_data(data, data_size, 1, data_size * 2);

    std::sort(data.begin(), data.end());
    if (option == 'y' || option == 'Y') {
        int tag = 1;
        for (const auto &c : data) {
            std::cout << c << " ";
            if (tag % 10 == 0)
                std::cout << "\n";
            ++tag;
        }
        std::cout << "\n";
    }

    clock_t start_time  = clock();
    int     min_element = Randomized_Select(data, 0, data.size() - 1, k);
    clock_t end_time    = clock();
    std::cout << "在随机选择中：第" << k << "小的元素是：" << min_element << ",耗时为：" << (end_time-start_time) << "ms\n";

    start_time  = clock();
    min_element = Randomized_Select(data, 0, data.size() - 1, k);
    end_time    = clock();
    std::cout << "在线性选择中：第" << k << "小的元素是：" << min_element << ",耗时为：" << (end_time-start_time)/1000<<"ms\n";
}

/**
 * @title
 * Randomized_Partition
 * @description The sequence is randomly segmented
 * @memberof
 * data: Target sequence
 * @memberof
 * low_index: Target sequence reference leftmost element index
 * @memberof
 * high_index: Target sequence reference rightmost element index
 * @return
 * Index of the element where the divider resides(pivot index)
 */
size_t Randomized_Partition(std::vector<int> data, size_t low_index, size_t high_index) {
    size_t i = std::rand() % (high_index - low_index + 1) + low_index;
    std::swap(data[i], data[high_index]);

    int    pivot = data[high_index];
    size_t j     = low_index;

    for (size_t h = low_index; h < high_index; ++h) {
        if (data[h] <= pivot) {
            std::swap(data[h], data[j]);
            ++j;
        }
    }

    std::swap(data[j], data[high_index]);
    return j;
}

/**
 * @title
 * Randomized_Select
 * @description
 * Select the "k"th smallest element of the sequence
 * @memberof
 * data: Target sequence
 * @memberof
 * reference_element_index: Target sequence reference leftmost element index
 * @memberof
 * end_element_index: Target sequence reference rightmost element index
 * @memberof
 * k: Ascending index value(the "k"th smallest element in the sequence)
 * @return
 * "K"th smallest element
 */
int Randomized_Select(std::vector<int> data, size_t reference_element_index, size_t end_element_index, size_t k) {
    if (reference_element_index == end_element_index)
        return data[reference_element_index];
    if (k == 1)
        return static_cast<int>(*std::min_element(
          data.begin() + static_cast<int>(reference_element_index), data.begin() + static_cast<int>(end_element_index) + 1));

    size_t i = Randomized_Partition(data, reference_element_index, end_element_index);
    size_t j = i - reference_element_index + 1;

    if (k <= j)
        return Randomized_Select(data, reference_element_index, i, k);
    else
        return Randomized_Select(data, i + 1, end_element_index, k - j);
}

/**
 * @title
 * Partition
 * @description
 * Linear selection separation
 * @memberof
 * data: Target sequence
 * @memberof
 * low_index: Target sequence reference leftmost element index
 * @memberof
 * high_index: Target sequence reference rightmost element index
 * @memberof
 * x: Reference object
 * @return
 * Index of the element where the divider resides(pivot index)
 */
size_t Partition(std::vector<int> &data, size_t low_index, size_t high_index, int x) {
    size_t i = low_index - 1;
    size_t j = high_index + 1;

    while (true) {
        do
            ++i;
        while (data[i] < x);
        do
            --j;
        while (data[j] > x);
        if (i >= j)
            break;
        std::swap(data[i], data[j]);
    }
    return j;
}

/**
 * @title
 * Linear_Select
 * @description
 * Select the "k"th smallest element of the sequence
 * @memberof
 * data: Target sequence
 * @memberof
 * reference_element_index: Target sequence reference leftmost element index
 * @memberof
 * end_element_index: Target sequence reference rightmost element index
 * @memberof
 * k: Ascending index value(the "k"th smallest element in the sequence)
 * @return
 * "k"th smallest element
 */
int Linear_Select(std::vector<int> &data, size_t reference_element_index, size_t end_element_index, size_t k) {
    size_t left_index  = reference_element_index;
    size_t right_index = end_element_index;

    if (right_index - left_index < 75) {
        for (size_t i = left_index; i < right_index; ++i) {
            for (size_t j = i + 1; j <= right_index; ++j) {
                if (data[j] < data[i])
                    std::swap(data[i], data[j]);
            }
        }
        return data[left_index + k - 1];
    }

    for (size_t i = 0; i <= (right_index - left_index - 4) / 5; ++i) {
        size_t min_index = left_index + 5 * i + 2;
        for (size_t j = left_index + 5 * i; j <= left_index + 5 * i + 4; ++j) {
            if (data[j] < data[min_index])
                min_index = j;
        }
        std::swap(data[left_index + 1], data[min_index]);
    }

    int    x = Linear_Select(data, left_index, left_index + (right_index - left_index - 4) / 5, (right_index - left_index - 4) / 10);
    size_t j = Partition(data, left_index, right_index, x) - left_index + 1;

    if (k <= j)
        return Linear_Select(data, left_index, j, k);
    else
        return Linear_Select(data, j + 1, right_index, k - j);
}