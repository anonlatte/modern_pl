#include <iostream>
#include <iomanip>
#include <map>

#define N 5

using namespace std;

// Минимум матрицы
float minOfMatrix(float m[N][N]) {

    float min = m[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < min) min = m[i][j];
        }
    }

    return min;
}

// Максимум матрицы
float maxOfMatrix(float m[N][N]) {

    float max = m[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > max) max = m[i][j];
        }
    }

    return max;
}

// Минимум нижнетреугольной матрицы
float minTriangleBottom(float m[N][N]) {
    float min = m[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            if (m[i][j] < min) min = m[i][j];
        }
    }

    return min;
}

// Максимум нижнетреугольной матрицы
float maxTriangleBottom(float m[N][N]) {
    float max = m[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            if (m[i][j] > max) max = m[i][j];
        }
    }

    return max;
}

// Минимум верхнетреугольной матрицы
float minTriangleTop(float m[N][N]) {
    float min = m[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] < min) min = m[i][j];
        }
    }

    return min;
}

// Максимум верхнетреугольной матрицы
float maxTriangleTop(float m[N][N]) {
    float max = m[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] > max) max = m[i][j];
        }
    }

    return max;
}

// Минимум главной диагонали
float minDiagonalMain(float m[N][N]) {
    float min = m[0][0];

    for (int i = 0; i < N; i++) {
        if (m[i][i] < min) min = m[i][i];
    }

    return min;
}

// Максимум главной диагонали
float maxDiagonalMain(float m[N][N]) {
    float max = m[0][0];

    for (int i = 0; i < N; i++) {
        if (m[i][i] > max) max = m[i][i];
    }

    return max;
}

// Минимум второстепенной диагонали
float minDiagonalSecondary(float m[N][N]) {
    float min = m[0][0];

    for (int x = 0; x < N; x++) {
        int y = N - 1 - x;
        if (m[x][y] < min) min = m[x][y];
    }

    return min;
}

// Максимум второстепенной диагонали
float maxDiagonalSecondary(float m[N][N]) {
    float max = m[0][0];

    for (int x = 0; x < N; x++) {
        int y = N - 1 - x;
        if (m[x][y] > max) max = m[x][y];
    }

    return max;
}

// Среднеарифметическое значение матрицы
float getAverage(float m[N][N]) {
    float total = 0.;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            total += m[i][j];
        }
    }

    float average = total / (N * N);
    return average;
}

// Среднеарифметическое значение нижнетреугольной матрицы
float averageTriangleBottom(float m[N][N]) {
    float total = 0.;

    for (int i = 0; i < N; i++)
        for (int j = i; j >= 0; j--)
            total += m[i][j];

    float average = total / (N * N);

    return average;
}

// Среднеарифметическое значение верхнетреугольной матрицы
float averageTriangleTop(float m[N][N]) {
    float total = 0.;

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            total += m[i][j];

    float average = total / (N * N);

    return average;
}

// Сумма строк
std::map<int, float> sumRows(float m[N][N]) {
    std::map<int, float> sum_values;
    float total;

    for (int i = 0; i < N; i++) {
        total = 0.;

        for (int j = 0; j < N; j++)
            total += m[i][j];

        sum_values[i] = total;
    }

    return sum_values;
}

// Сумма столбцов
std::map<int, float> sumCols(float m[N][N]) {
    std::map<int, float> sum_values;
    float total;

    for (int y = 0; y < N; y++) {
        total = 0.;

        for (int x = 0; x < N; x++)
            total += m[x][y];

        sum_values[y] = total;
    }

    return sum_values;
}

// Минимум строк
std::map<int, float> minRows(float m[N][N]) {
    std::map<int, float> min_values;
    float min;

    for (int i = 0; i < N; i++) {
        min = m[i][0];

        for (int j = 0; j < N; j++)
            if (m[i][j] < min) min = m[i][j];

        min_values[i] = min;
    }

    return min_values;
}

// Максимум строк
std::map<int, float> maxRows(float m[N][N]) {
    std::map<int, float> max_values;
    float max;

    for (int i = 0; i < N; i++) {
        max = m[i][0];

        for (int j = 0; j < N; j++)
            if (m[i][j] > max) max = m[i][j];

        max_values[i] = max;
    }

    return max_values;
}

// Минимум столбцов
std::map<int, float> minCols(float m[N][N]) {
    std::map<int, float> min_values;
    float min;

    for (int y = 0; y < N; y++) {
        min = m[0][y];

        for (int x = 0; x < N; x++)
            if (m[x][y] < min) min = m[x][y];

        min_values[y] = min;
    }

    return min_values;
}

// Максиммум столбцов
std::map<int, float> maxCols(float m[N][N]) {
    std::map<int, float> max_values;
    float max;

    for (int j = 0; j < N; j++) {
        max = m[0][j];

        for (int i = 0; i < N; i++)
            if (m[i][j] > max) max = m[i][j];

        max_values[j] = max;
    }

    return max_values;
}

// Среднеарифметическое значение строк
std::map<int, float> averageRowValue(float m[N][N]) {
    std::map<int, float> avg_values;
    float rowTotal, rowAverage;

    for (int i = 0; i < N; i++) {
        rowTotal = 0.;

        for (int j = 0; j < N; j++)
            rowTotal += m[i][j];

        rowAverage = rowTotal / N;
        avg_values[i] = rowAverage;
    }

    return avg_values;
}

// Среднеарифметическое значение столбцов
std::map<int, float> averageColValue(float m[N][N]) {
    std::map<int, float> avg_values;
    float colTotal, colAverage;

    for (int y = 0; y < N; y++) {
        colTotal = 0.;

        for (int x = 0; x < N; x++)
            colTotal += m[x][y];

        colAverage = colTotal / N;
        avg_values[y] = colAverage;
    }

    return avg_values;
}

// Сумма нижнетреугольной матрицы
float triangleBottomSum(float m[N][N]) {
    float total = 0.;

    for (int i = 0; i < N; i++)
        for (int j = i; j >= 0; j--)
            total += m[i][j];

    return total;
}

// Сумма верхнетреугольной матрицы
float triangleTopSum(float m[N][N]) {
    float total = 0.;

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            total += m[i][j];

    return total;
}

// Ближайшее к среднеарифметическому значению матрицы
float closestToAverage(float m[N][N]) {

    float average = getAverage(m);
    float closest = m[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (abs(m[i][j] - average) < closest) closest = m[i][j];

    return closest;
}

int main() {
    float m[N][N];
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = float(rand() / 10.);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << setw(8) << setprecision(5) << m[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Min of matrix: " << minOfMatrix(m) << endl;
    cout << "Max of matrix: " << maxOfMatrix(m) << endl;

    cout << "Min of triangle bottom: " << minTriangleBottom(m) << endl;
    cout << "Max of triangle bottom: " << maxTriangleBottom(m) << endl;

    cout << "Min of triangle top: " << minTriangleTop(m) << endl;
    cout << "Max of triangle top: " << maxTriangleTop(m) << endl;

    cout << "Min of diagonal main: " << minDiagonalMain(m) << endl;
    cout << "Max of diagonal main: " << maxDiagonalMain(m) << endl;

    cout << "Min of diagonal secondary: " << minDiagonalSecondary(m) << endl;
    cout << "Max of diagonal secondary: " << maxDiagonalSecondary(m) << endl;

    cout << "Average of matrix: " << getAverage(m) << endl;

    cout << "Average of triangle bottom: " << averageTriangleBottom(m) << endl;
    cout << "Average of triangle top: " << averageTriangleTop(m) << endl;

    cout << "Sum of rows: " << endl;
    for (auto const &[key, val]: sumRows(m)) {
        cout << "\tRow " << key << " sum = " << val << endl;
    }

    cout << "Sum of cols: " << endl;
    for (auto const &[key, val]: sumCols(m)) {
        cout << "\tColumn " << key << " sum = " << val << endl;
    }

    cout << "Min of rows: " << endl;
    for (auto const &[key, val]: minRows(m)) {
        cout << "\tRow " << key << " min value = " << val << endl;
    }

    cout << "Max of rows: " << endl;
    for (auto const &[key, val]: maxRows(m)) {
        cout << "\tRow " << key << " max value = " << val << endl;
    }

    cout << "Min of cols: " << endl;
    for (auto const &[key, val]: minCols(m)) {
        cout << "\tColumn " << key << " min value = " << val << endl;
    }

    cout << "Max of cols: " << endl;
    for (auto const &[key, val]: maxCols(m)) {
        cout << "\tColumn " << key << " max value = " << val << endl;
    }

    cout << "Average of rows: " << endl;
    for (auto const &[key, val]: averageRowValue(m)) {
        cout << "\tRow " << key << " average value = " << val << endl;
    }

    cout << "Average of cols: " << endl;
    for (auto const &[key, val]: averageColValue(m)) {
        cout << "\tColumn " << key << " average value = " << val << endl;
    }

    cout << "Triangle bottom sum: " << triangleBottomSum(m) << endl;
    cout << "Triangle top sum: " << triangleTopSum(m) << endl;

    cout << "Closest to average: " << closestToAverage(m) << endl;

    return 0;
}
