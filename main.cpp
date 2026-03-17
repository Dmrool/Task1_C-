#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

// создание матрицы в куче
int** createMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    return matrix;
}

// ввод матрицы
void inputMatrix(int** matrix, int rows, int cols)
{
    cin.ignore(); // очистка буфера

    for (int i = 0; i < rows; )
    {
        cout << "Введите строку " << i + 1 << ": ";

        string line;
        getline(cin, line);

        stringstream ss(line);
        int value;
        int count = 0;

        while (ss >> value)
        {
            if (count < cols)
                matrix[i][count] = value;
            count++;
        }

        if (count != cols || !ss.eof())
        {
            cout << "Ошибка! Необходимо ввести точное количество символов. "
                 << cols << " integers.\n";
            continue;
        }

        i++;
    }
}

// вывод
void printMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// перестановка
void reverseColumns(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols / 2; j++)
            swap(matrix[i][j], matrix[i][cols - 1 - j]);
}

// очистка
void deleteMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int rows, cols;

    cout << "Введите количество строк: ";
    cin >> rows;

    cout << "Введите количество столбцов: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0)
    {
        cout << "Неправильно введены размеры!\n";
        return 1;
    }

    int** matrix = createMatrix(rows, cols);

    inputMatrix(matrix, rows, cols);

    cout << "\nИсходная матрица:\n";
    printMatrix(matrix, rows, cols);

    reverseColumns(matrix, rows, cols);

    cout << "\nОбратная матрица:\n";
    printMatrix(matrix, rows, cols);

    deleteMatrix(matrix, rows);

    cout << "\nНажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}
