#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../lab7.3/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// Прототип функції, яку ми тестуємо
int countRowsWithAvgLessThan(vector<vector<int>>& matrix, int rows, int cols, int threshold);

namespace UnitTestProject
{
    TEST_CLASS(UnitTestProject)
    {
    public:

        TEST_METHOD(TestCountRowsWithAvgLessThan)
        {
            // Створюємо тестову матрицю
            vector<vector<int>> matrix = {
                {1, 2, 3},   // Середнє арифметичне: 2
                {10, 10, 10}, // Середнє арифметичне: 10
                {4, 5, 6}    // Середнє арифметичне: 5
            };

            int rows = 3;
            int cols = 3;
            int threshold = 6;

            // Очікувана кількість рядків із середнім меншим за 6
            int expectedCount = 2;

            // Викликаємо функцію для підрахунку рядків
            int result = countRowsWithAvgLessThan(matrix, rows, cols, threshold);

            // Перевіряємо, чи результат відповідає очікуванню
            Assert::AreEqual(expectedCount, result);
        }
    };
}

// Реалізація функції (для тестування, вона буде в іншому файлі програми)
int countRowsWithAvgLessThan(vector<vector<int>>& matrix, int rows, int cols, int threshold) {
    int count = 0;

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        int avg = sum / cols;
        if (avg < threshold) {
            count++;
        }
    }

    return count;
}
