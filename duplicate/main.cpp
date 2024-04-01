#include <iostream>
#include <random>

float getRandomFloat(float min, float max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

void printArray(float arr[], int size) {
    for (int i = 0; i <size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

bool checkDublicates(float arr[], int size){
    for (int j = 0; j < size-1; ++j) {
        for (int i = j+1; i < size; ++i) {
            if (arr[j] == arr[i]){
                return true;
            }
        }
    }
    return false;

}

int main(){
    int size = 5;
    float *nums = new float[size];
    for (int i = 0; i < size; ++i) {
        nums[i] = getRandomFloat(-10, 10);
    }
    printArray(nums, size);
    if (checkDublicates(nums, size) == true) std::cout<<"True\n";
    else std::cout<<"False\n";

    system("pause");
    return 0;
}