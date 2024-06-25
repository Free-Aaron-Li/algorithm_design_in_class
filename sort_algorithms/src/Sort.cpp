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
Sort::random_data( int quantity, int min_number, int max_number) {
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

    std::cout << _ss.str();
}

void
Sort::print(const std::vector<int>& data, const std::string& algorithm_name, const long time_diff) {
    if (_output_parameter_list) {
        Sort::_ss << "------------------------------------------------------\n";
        Sort::_ss << "Algorithm name: " << algorithm_name << "\nSpend time: " << time_diff << "ms\n"
                  << "------------------------------------------------------\n";
    }
    if (_output_sorted_sequence) {
        Sort::_ss << "------------------------------------------------------\n";
        Sort::_ss << "The data is: \n";
        for (const auto& element : data)
            Sort::_ss << element << " ";
        Sort::_ss << "\n------------------------------------------------------\n";
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
    for (int i = 0; i < data.size(); ++i) {
        int index = i;
        for (int j = i + 1; j < data.size(); ++j)
            if (data[j] < data[index])
                index = j;
        if (index != i)
            std::swap(data[i], data[index]);
    }
    auto end = clock();

    print(data, "Select Sort", time_calculation(end - start));
}
