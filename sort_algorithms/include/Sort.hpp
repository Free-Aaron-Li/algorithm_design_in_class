// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sort'.
// Include common sorting algorithms: selection, bubbling, fast, etc.
// Sort in ascending order.
#ifndef ALGORITHM_DESIGN_SORT_HPP
#define ALGORITHM_DESIGN_SORT_HPP

#include <random>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <fmt/core.h>
#include <fmt/format.h>

/**
 * @brief Sort.
 * @details Includes common algorithms: Select, Bubble, Insert, quick, Merge, Heap, Shell, Radix, etc.\n All algorithms
 * are sorted in ascending order.
 */
class Sort {

 private:
    /// Input sequence data.
    const std::vector<int> _data;

    /// temporary sequence data.
    std::vector<int> _data_temp;

    /// Specifies that the string stream is used to store the sorted sequence.
    fmt::memory_buffer _buffer;

    /// Whether to use standard output.
    bool _output_sorted_sequence = false;

    /// Whether to output a sort parameter list
    bool _output_parameter_list = false;

    /// Whether to use the specified file output
    bool _output_specified_file = false;

    /// specified file stream
    std::ofstream _outfile;

    /**
     * @brief Print complete sort sequence and add additional remarks.
     * @param data Sort completion sequence.
     * @param algorithm_name Algorithm name.
     * @param time_diff Algorithm time.
     */
    void print(const std::vector<int>& data, const std::string& algorithm_name, long time_diff);

    /**
     * @brief Generate a sequence of random numbers.
     * @details Generate reliable random numbers using std::random_device & std::default_random_engine in the \<random>.
     * @param quantity Sequence size.
     * @param min_number Lower bound of random number distribution.
     * @param max_number Top of random number distribution.
     */
    static std::vector<int> random_data(int quantity, int min_number, int max_number);

    /**
     * @brief Calculation algorithm time.
     * @details Calculate the operation time by the difference of the clock ticks of the CPU operation.
     * @param time_diff The difference in clock ticks.
     */
    static long time_calculation(clock_t time_diff);

 public:
    /**
     * @brief Sort and get the result and time.
     * @details Specific sorting algorithms are: selection etc.
     * @param quantity Sequence size.
     * @param min_number Lower bound of random number distribution.
     * @param max_number Top of random number distribution.
     */
    Sort(int quantity, int min_number, int max_number) : _data(random_data(quantity, min_number, max_number)) {}

    /**
     * @brief Sort and get the result and time.
     * @details Specific sorting algorithms are: selection etc.
     * @param data The sequence data that needs to be sorted.
     */
    explicit Sort(const std::vector<int>& data) : _data(data) {}

    /**
     * @brief Output result sequence and algorithm information.
     */
    ~Sort() {
        if (!_output_specified_file)
            fmt::print(fmt::to_string(_buffer));
        if (_output_specified_file && _outfile) {
            _outfile << fmt::to_string(_buffer) << std::endl;
            fmt::print("Successfully output to the specified file.\n");
        }
    }

    /**
     * @brief Select the program sequence print method.
     * @details The output information is divided into two parts, sorting parameter information (sorting algorithm name,
     * time spent) and the sequence obtained after sorting. You have @p Options to choose from.
     *
     * @param Options ==0 No printing required. \n
     *                ==1 All print on terminal. \n
     *                ==2 Output only parameter information to the terminal. \n
     *                ==3 All print in the specified file.
     * @param filename Absolute file path or relative executable file path.
     */
    void display_mode(short Options, const std::string& filename = "");

 public:
    /**
     * @brief Selection sort.
     * @details \n
     * Basic Idea: <b>Select</b> \n
     * - Select the <b>smallest(or largest)</b> element from the unsorted data and place it at the beginning of the
     * sequence. \n
     * - Then, find the smallest(or largest) from the remaining elements and put it at the end of the sorted sequence.
     * \n
     * - Repeat the second step until the number of all data elements to be sorted is zero.\n
     * \n
     * Time complexity: worst: O(n^2), average: O(n^2), best: O(n^2).
     */
    void select_sort();

    /**
     * @brief Bubble sort.
     * @details \n
     * Basic Idea: <b>Swap</b> \n
     * - <b>Compare adjacent</b> elements, and if the first is greater(lesser) than the second, swap them. \n
     * - Do the same work for every pair of adjacent elements, from the first pair to the last pair. After those steps,
     * the last element will be the largest(smallest) number. \n
     * - Repeat the above step for all elements, except for those that already been sorted at the end. \n
     * - Continue to repeat the above steps for increasingly smaller number of elements until no pair of numbers needs
     * to be compared.\n
     * \n
     * Time complexity: worst: O(n^2), average: O(n^2), best: O(1).
     */
    void bubble_sort();

    /**
     * @brief Insertion Sort.
     * @details \n
     * Basic Idea: <b>Move</b>\n
     * Start from the second element of the array and consider it as the new element. \n
     * <b>Compare</b> the new element with the <b>previous element</b> in the sorted portion. If the new element is
     * smaller (for ascending order), move the previous element one position ahead.\n Keep comparing with the next
     * adjacent element until reach an element that is smaller than the new element or until reach the start of the
     * array.\n Place the new element in its correct position where it is no longer smaller than the adjacent element.\n
     * Move to the next element in the array and repeat the process, each time requiring fewer comparisons as the sorted
     * portion grows.\n Continue the above steps until the last element is inserted into its correct position, at which
     * point the array becomes fully sorted.\n
     * \n
     * Time complexity: worst: O(n^2), average: O(n^2), best: O(n).
     */
    void insertion_sort();

    /**
     * @brief
     */
    void quick_sort();
};
#endif  // ALGORITHM_DESIGN_SORT_HPP
