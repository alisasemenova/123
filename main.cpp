#include <iostream>
#include <iostream>
#include <cmath>
/**
 * @brief Функция для перевода числа в другую сс
 * 
 * @param number принимает число для перевода
 * @param base - система, счисления в которую переводим
 * @return std::string - возвращает 
 */

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
/**
 * @brief Функция для конвертации числа N из десятичной системы в p-ичную (по значению)
 * 
 * @param N - число для перевода
 * @param p - основание системы
 * @return std::string - возвращает число в новой сс в формате строки
 */

std::string convertByValue(int N, int p) {
    std::string result = "";
    result = SwapBases(N, p) + result; 
    return result; 
}

/**
 * @brief Функция для конвертации числа N из десятичной системы в p-ичную (по ссылке)
 * 
 * @param N - число для перевода
 * @param p - основание системы
 * @param result - результирующее число в формате строки
 */
 
void convertByReference(int N, int p, std::string& result) {
    result = ""; 
    result = SwapBases(N, p) + result;
}

/**
 * @brief Функция для конвертации числа N из десятичной системы в p-ичную (через указатель) 
 * 
 * @param N - число для перевода
 * @param p - новое основание
 * @param result - строка, в которой хранится число в новой сс
 */
 
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
