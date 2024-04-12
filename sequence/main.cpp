#include <iostream>
#include <random>
#include <string>
#include <set>

void PrintSet(std::set<int> nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
}

std::set<int> generateRandomSet(int size, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    std::set<int> nums;

    for (int i = 0; i != size; ++i) {
        nums.insert(dis(gen));
    }
    return nums;
}

void longest_consecutive_sequence(std::set<int> nums) {
    int longest_seq_len = 0;
    int curr_seq_len = 0;
    // std::set<int> seq_nums;

    for (int num : nums) {
        if (nums.find(num-1) == nums.end()) {
            curr_seq_len = 1;
        }
        else {
            curr_seq_len += 1;
        }
        if (curr_seq_len > longest_seq_len) {
            longest_seq_len = curr_seq_len;
            // seq_nums.insert(num);
        }
    }
    // std::cout << "\n";
    // PrintSet(seq_nums);
    std::cout << "\nMax len: " << longest_seq_len << "\n";
}

int main() {
    int size = 20;
    std::string input;
    do {
        std::set<int> nums = generateRandomSet(size, 0, 30);

        PrintSet(nums);
        longest_consecutive_sequence(nums);
        
        std::cout << "";
        std::getline(std::cin, input);
    } while (input.empty());
    return 0;
}