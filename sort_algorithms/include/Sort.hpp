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
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

/**
 * @brief Sort.
 * @details Includes common algorithms: Select, Bubble, Insert, quick, Merge, Heap, Shell, Radix, etc.\n All algorithms are sorted in ascending order.
 */
class Sort {

 private:
    /// Input sequence data.
    const std::vector<int> _data;

    /// temporary sequence data.
    std::vector<int> _data_temp;

    /// Specifies that the string stream is used to store the sorted sequence.
    std::stringstream _ss;

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
            std::cout << _ss.str() << std::endl;
        if (_output_specified_file && _outfile) {
            _outfile << _ss.str() << std::endl;
            std::cout << "Successfully output to the specified file." << std::endl;
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
     * @brief selection sort.
     */
    void select_sort();
};
#endif  // ALGORITHM_DESIGN_SORT_HPP
