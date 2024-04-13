#include <iostream>
#include <string>
#include <random>

int getRandomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void getProduct(int arr[], int size) {
    int *result = new int[size];
    for (int current_num = 0;  current_num < size;  ++current_num) {
        int calculate = 0;
        for (int num = 0;  num < size;  ++num) {
            if (num != current_num){
                calculate += arr[num];
            }
        }
        result[current_num] = calculate;
    }
    printArray(result, size);
}

int main() {
    int size = 5;
    int *nums = new int[size];
    std::string input;
    do {
        for (int i = 0; i < size; ++i) {
            nums[i] = getRandomInt(0, 10);
        }
        printArray(nums, size);

        getProduct(nums, size);

        std::cout << "";
        std::getline(std::cin, input);
    } while(input.empty());
    return 0;
}