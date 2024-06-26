// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sort'.
// Implementation of sort.hpp.
#include "Sort.hpp"

std::vector<int>
Sort::random_data(int quantity, int min_number, int max_number) {
    std::vector<int> data;
    if (quantity > max_number) {
        std::cerr << "The maximum random number is less than the number of target sequence!";
        return data;
    }

    std::random_device                 device;            /// Random number generation seed.
    std::default_random_engine         engine(device());  /// The generated seed is initialized.
    std::uniform_int_distribution<int> distribution_number(
        min_number, max_number);  /// Define how random numbers are distributed.

    for (int i = 0; i < quantity; ++i)
        data.push_back(distribution_number(engine));  /// Add random number.
    return data;
}

void
Sort::display_mode(const short Options, const std::string& filename) {
    if (Options == 3 && filename.empty())
        std::cerr << "Please enter file path!";

    /// Create a file if it does not exist; If present, empty the content.
    _outfile.open(filename, std::ios::out);

    if (!filename.empty() && !_outfile.is_open()) {
        std::cerr << "Can't open \"" << filename << "\" to write." << std::endl;
        _output_specified_file = false;
        return;
    }

    switch (Options) {
        case 0:
            _output_parameter_list  = false;
            _output_sorted_sequence = false;
            _output_specified_file  = false;
            break;
        case 1:
            _output_parameter_list  = true;
            _output_sorted_sequence = true;
            _output_specified_file  = false;
            break;
        case 2:
            _output_parameter_list  = true;
            _output_sorted_sequence = false;
            _output_specified_file  = false;
            break;
        case 3:
            _output_parameter_list  = true;
            _output_sorted_sequence = true;
            _output_specified_file  = true;
        default: break;
    }
}

void
Sort::print(const std::vector<int>& data, const std::string& algorithm_name, const long time_diff) {
    if (_output_parameter_list) {
        fmt::format_to(
            std::back_inserter(_buffer),
            "------------------------------------------------------\n"
            "Algorithm name: {}\nSpend time: {}ms\n"
            "------------------------------------------------------\n",
            algorithm_name, time_diff);
    }
    if (_output_sorted_sequence) {
        fmt::format_to(
            std::back_inserter(_buffer),
            "------------------------------------------------------\n"
            "The data is: \n");
        for (const auto& element : data)
            fmt::format_to(std::back_inserter(_buffer), "{} ", element);
        fmt::format_to(std::back_inserter(_buffer), "\n------------------------------------------------------\n");
    }
}

long
Sort::time_calculation(const clock_t time_diff) {
    double cpu_time_used = ((double) (time_diff)) / CLOCKS_PER_SEC;
    return (long) (cpu_time_used * 1000);  /// In my OS(Linux Base), 1 Clock tick is equal to 1 microsecond
}

void
Sort::select_sort() {
    auto data  = _data;
    auto start = clock();

    for (auto i = 0; i < data.size(); ++i) {
        auto index = i;  /// "index" indicates the index of the largest number.
        for (auto j = i + 1; j < data.size(); ++j)
            if (data[j] < data[index])  /// Choose a smallest number.
                index = j;              /// Forward ergodic.
        if (index != i)
            std::swap(data[i], data[index]);  /// Swap with the smallest number.
    }

    auto end = clock();
    print(data, "Select Sort", time_calculation(end - start));
}

void
Sort::bubble_sort() {
    auto data  = _data;
    auto start = clock();

    bool change = true;                                     /// Whether an element exchange occurs.
    for (auto i = data.size() - 1; i > 1 && change; --i) {  /// Note: i = data.size() -1
        change = false;
        for (auto j = 0; j < i; ++j) {    /// Traversal search.
            if (data[j] > data[j + 1]) {  /// Find a bigger number.
                std::swap(data[j], data[j + 1]);
                change = true;
            }
        }
    }

    auto end = clock();
    print(data, "Bubble Sort", time_calculation(end - start));
}

void
Sort::insertion_sort() {
    auto data  = _data;
    auto start = clock();

    for (int i = 1; i < data.size(); ++i) {  /// By default, the first element is already sorted.
        int key = data[i];                   /// Extract element.
        int j   = i - 1;

        while (j >= 0 && data[j] > key) {  /// Traversal search.
            data[j + 1] = data[j];         /// Data moves back.
            j           = j - 1;           /// Search forward.
        }
        data[j + 1] = key;
    }

    auto end = clock();
    print(data, "Selection Sort", time_calculation(end - start));
}
