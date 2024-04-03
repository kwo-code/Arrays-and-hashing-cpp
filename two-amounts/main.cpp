#include <iostream>
#include <random>

float getRandomFloat(float min, float max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

void printArray(float arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void findSum(float arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == target) {
                std::cout << i << " " << j << "\n";
                return ; 
            }
        }
    }
    std::cout << "None\n";
}

int main() {
    int target;
    int size = 10;
    float *nums = new float[size];
    for (int i = 0; i < size; ++i) {
        nums[i] = getRandomFloat(1, 10);
    }
    printArray(nums, size);
    
    std::cout << "target:";
    std::cin >> target;

    findSum(nums, size, target);

    system("pause");
    return 0;
}