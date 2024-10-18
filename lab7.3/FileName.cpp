#include <iostream>
#include <vector>
#include <iomanip> 
#include <cstdlib>
#include <ctime>   

using namespace std;

// обмін двох рядків 
void swapRows(vector<vector<int>>& matrix, int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

void gaussElimination(vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        // 1. Обираємо перший зліва стовпчик, що містить ненульовий елемент
        int pivotColumn = i;
        if (matrix[i][pivotColumn] == 0) {
            // 2. Якщо верхній елемент – нуль, шукаємо рядок, де цей стовпчик не нульовий, і міняємо місцями
            for (int j = i + 1; j < rows; j++) {
                if (matrix[j][pivotColumn] != 0) {
                    swapRows(matrix, i, j, cols);
                    break;
                }
            }
        }

        // 3. Ділимо всі елементи рядка на верхній елемент стовпчика
        if (matrix[i][pivotColumn] != 0) {
            int divisor = matrix[i][pivotColumn];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] /= divisor;
            }
        }

        // 4. Від рядків, що залишились, віднімаємо перший рядок, помножений на перший елемент відповідного рядка
        for (int j = i + 1; j < rows; j++) {
            int factor = matrix[j][pivotColumn];
            for (int k = 0; k < cols; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

// Функція для підрахунку кількості рядків, середнє арифметичне яких менше заданої величини
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

int main() {
    int rows, cols, lowerBound, upperBound, threshold;

   
    srand(time(0));

    
    cout << "rows : ";
    cin >> rows;
    cout << "cols : ";
    cin >> cols;

    
    cout << "lower : ";
    cin >> lowerBound;
    cout << "upper : ";
    cin >> upperBound;

    
    vector<vector<int>> matrix(rows, vector<int>(cols));

   
    cout << "START M :" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (upperBound - lowerBound + 1) + lowerBound; 
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    
    gaussElimination(matrix, rows, cols);

    
    cout << "TRIANGLE M :" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    
    cout << "MIDDLE A : ";
    cin >> threshold;

    
    int count = countRowsWithAvgLessThan(matrix, rows, cols, threshold);
    cout << "n of rows " << threshold << ": " << count << endl;

    return 0;
}
