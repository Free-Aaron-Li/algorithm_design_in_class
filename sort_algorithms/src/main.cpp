//
// This 'main' belongs  to the algorithm_design
//
// Created by aaron on 23-9-19.
// Copyright (c) 2023 aaron. All rights reserved.
//
// The source file follows the GPL3.0 protocol and is distributed with the file.
// If you do not receive the GPL4.0 protocol ontology or you find a bug,
// please let me know (email: fly_aaron.li@outlook.com)

#include <iostream>
#include <random>
#include <string>
#include <vector>

void             random_data(std::vector<int> &data, int quantity, int min_number, int max_number);
std::vector<int> copy_container(std::vector<int> &data);
void             print_sorted_list(bool selection);
void             print(std::vector<int> &vector, std::string algorithm_name, clock_t time_difference);
void             Bubble_Sort(std::vector<int> vector);
void             quick_sort(std::vector<int> vector);
void             quick_sort_algorithm(std::vector<int> &vector, int left, int right);
void             selection_sort(std::vector<int> vector);
void             insertion_sort(std::vector<int> vector);
static bool      flag = false;


int main() {
    std::vector<int> data;

    /** Get random number */
    random_data(data, 60000, 2, 100000);

    /** Whether to print sorted documents */
    print_sorted_list(false);
    Bubble_Sort(copy_container(data));
    quick_sort(copy_container(data));
    selection_sort(copy_container(data));
    insertion_sort(copy_container(data));
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
 * copy_container
 * @description
 * Copy sequence containers to ensure consistency in sorting input sequences
 * @memberof
 * data ： Sequence container prototype
 * @return
 * Copy prototype
 */
std::vector<int> copy_container(std::vector<int> &data) {
    std::vector<int> data_temp;
    data_temp.assign(data.cbegin(), data.cend());
    return data_temp;
}


/**
 * @title
 * print_sorted_list
 * @description
 * Whether to print the sorted sequence
 * @memberof
 * selection : Boolean option
 * @return
 * Boolean option
 */
void print_sorted_list(bool selection) { flag = selection; }

/**
 * @title
 * print
 * @description
 * Printing the sorted sequence obtained by the algorithm,
 * the algorithm name, and the sorting consumes time(ms)
 * @memberof
 * vector : Enter the sequence to be sorted
 * @memberof
 * algorithm_name : Sort algorithm name
 * @memberof
 * time_difference : Algorithmic sorting takes time
 * @return
 * Algorithm name and time consuming
 */
void print(std::vector<int> &vector, const std::string algorithm_name, const clock_t time_difference) {
    // If you want to see if the sorting is correct, open the comment
    if (flag) {
        std::cout << "the data is :\n";
        for (auto const &c : vector) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
    /** I use the linux os,so clock() number need multiply by 1000 */
    std::cout << "The " << algorithm_name << " takes " << time_difference / 1000 << "ms\n\n";
}

/**
 * @title
 * Bubble_Sort
 * @description
 * Bubble sort(Unoptimized)
 * @memberof
 * vector : Enter the sequence to be sorted
 * @return
 * void
 */
void Bubble_Sort(std::vector<int> vector) {
    clock_t start = clock();
    for (int i = 0; i < vector.size() - 1; ++i) {
        for (int j = 0; j < vector.size() - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                int temp      = vector[j];
                vector[j]     = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    clock_t end = clock();
    print(vector, "Bubble_sort", end - start);
}

/**
 * @title
 * quick_sort
 * @description
 * quick sort(Unoptimized)
 * @memberof
 * vector : Enter the sequences to be sorted
 * @return
 * void
 */
void quick_sort(std::vector<int> vector) {
    clock_t start = clock();
    quick_sort_algorithm(vector, 0, static_cast<int>(vector.size() - 1));
    clock_t end = clock();
    print(vector, "Quick_sort", end - start);
}

/**
 * @title
 * quick_sort_algorithm
 * @description
 * Quick sort core
 * @memberof
 * vector : Enter the sequences to be sorted
 * @memberof
 * left : Fist member of sequences
 * @memberof
 * right : Last member of sequences
 * @return
 * void
 */
void quick_sort_algorithm(std::vector<int> &vector, int left, int right) {
    if (left < right) {
        int left_temp, right_temp, base;

        left_temp  = left;
        right_temp = right;
        base       = vector[left_temp];

        while (left_temp < right_temp) {
            while (left_temp < right_temp && vector[right_temp] > base)
                /** left to right,find the first number that is less than 'base' */
                --right_temp;
            if (left_temp < right_temp)
                vector[left_temp++] = vector[right_temp];
            while (left_temp < right_temp && vector[left_temp] < base)
                /** right to left,find the first number that is greater than 'base' */
                ++left_temp;
            if (left_temp < right_temp)
                vector[right_temp--] = vector[left_temp];
        }
        vector[left_temp] = base;
        quick_sort_algorithm(vector, left, left_temp - 1);
        quick_sort_algorithm(vector, left_temp + 1, right);
    } else
        return;
}

/**
 * @title
 * selection_sort
 * @description
 * Selection sort(Unoptimized)
 * @memberof
 * vector : Enter the sequences to be sorted
 * @return
 * void
 */
void selection_sort(std::vector<int> vector) {
    clock_t start = clock();
    for (int i = 0; i < vector.size(); ++i) {
        int index = i;
        for (int j = i + 1; j < vector.size(); ++j)
            if (vector[index] > vector[j])
                index = j;
        std::swap(vector[i], vector[index]);
    }
    clock_t end = clock();
    print(vector, "Selection_sort", end - start);
}

/**
 * @title
 * insertion_sort
 * @description
 * Insertion sort(Unoptimized)
 * @memberof
 * vector : Enter the sequences to be sorted
 * @return
 * void
 */
void insertion_sort(std::vector<int> vector) {
    clock_t start = clock();
    for (int i = 1; i < vector.size(); ++i) {
        int key = vector[i];
        int j   = i - 1;
        while (j >= 0 && vector[j] > key) {
            vector[j + 1] = vector[j];
            --j;
        }
        vector[j + 1] = key;
    }
    clock_t end = clock();
    print(vector, "Insertion_sort", end - start);
}