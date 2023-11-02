#include <iostream>
#include <vector>
#include <Windows.h>


double findMinElement(const std::vector<double>& arr) {
    if (arr.empty()) {
        std::cerr << "The array is empty" << std::endl;
        return 0.0;
    }

    double minElement = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    return minElement;
}


double sumBetweenFirstAndLastPositive(const std::vector<double>& arr) {
    double sum = 0.0;
    bool firstPositiveFound = false;
    size_t firstPositiveIndex = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > 0) {
            if (!firstPositiveFound) {
                firstPositiveFound = true;
                firstPositiveIndex = i;
            }
            else {
                for (size_t j = firstPositiveIndex + 1; j < i; ++j) {
                    sum += arr[j];
                }
                break;
            }
        }
    }

    return sum;
}


void transformArray(std::vector<double>& arr) {
    if (arr.empty()) {
        return;
    }

    size_t zeroCount = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0.0) {
            std::swap(arr[i], arr[zeroCount]);
            zeroCount++;
        }
    }
}

int main() {
    
    size_t n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    
    std::vector<double> arr(n);
    for (size_t i = 0; i < n; ++i) {
        std::cout << "Введіть " << (i + 1) << "-й елемент: ";
        std::cin >> arr[i];
    }

   
    double minElement = findMinElement(arr);
    std::cout << "1.1. Мінімальний елемент масиву: " << minElement << std::endl;

    
    double sum = sumBetweenFirstAndLastPositive(arr);
    std::cout << "1.2. Сума елементів між першим і останнім додатними: " << sum << std::endl;

   
    transformArray(arr);

 
    std::cout << "2. Масив після перетворення: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}