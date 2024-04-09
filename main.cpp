#include <iostream>
#include <iostream>
#include <cmath>

std::string SwapBases(int number, int base) {
    std::string code = "0123456789ABCDEF";
    std::string sum = "";
    while (number > 0) {
        sum += code[number % base];
        number /= base;
    }
    std::string result = "";
    for (int i = sum.length() - 1; i >= 0; i--) result += sum[i];
    return result;
}
// Функция для конвертации числа N из десятичной системы в p-ичную (по значению)
std::string convertByValue(int N, int p) {
    std::string result = "";
    result = SwapBases(N, p) + result; 
    return result; 
}

// Функция для конвертации числа N из десятичной системы в p-ичную (по ссылке)
void convertByReference(int N, int p, std::string& result) {
    result = ""; 
    result = SwapBases(N, p) + result;
}

// Функция для конвертации числа N из десятичной системы в p-ичную (через указатель)
void convertByPointer(int N, int p, std::string* result) {
    *result = ""; 
    *result = SwapBases(N, p) + *result; 
}

int main() {
    setlocale(LC_ALL, "Russian");
    int p, N;

    std::cout << "Введите основние для перевода: ";
    std::cin >> p;
    std::cout << "Введите число в десятичной CC для перевода: ";
    std::cin >> N;

    // Передача параметров по значению
    std::string resultByValue = convertByValue(N, p);
    std::cout << "Через значения: " << resultByValue << std::endl;

    // Передача параметров по ссылке
    std::string resultByReference;
    convertByReference(N, p, resultByReference);
    std::cout << "Через ссылки: " << resultByReference << std::endl;

    // Передача параметров через указатель
    std::string resultByPointer;
    convertByPointer(N, p, &resultByPointer);
    std::cout << "Через указатели: " << resultByPointer << std::endl;

    return 0;
}
