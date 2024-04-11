#include <iostream>
#include <string>
#include <cctype>

void printArray(std::string arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

std::string uncode(std::string arr[], int size) {
    std::string result1, result2;
    for (int i = 0; i < size; ++i) {
        int len = arr[i].length();
        result1 += arr[i][0];
        result1 += std::to_string(len);
        result2 += arr[i];
    }
    return result1 + result2;
}

int main() {
    const int size = 3;
    std::string arr[size] {"apple", "banana", "cherry"};

    printArray(arr, size);
    std::string result = uncode(arr, size);
    std::cout << result << "\n";

    system("pause");
    return 0;
}