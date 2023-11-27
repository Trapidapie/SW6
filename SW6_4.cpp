//#include <algorithm>
//#include <iostream>
//#include <cstdlib>
//#include <cfloat>
//#include <iomanip>
//#include <random>
//#include <fstream>
//
//
//using namespace std;
//
//int random(int min, int max) {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> distribution(min, max);
//    return distribution(gen);
//}
//
//int** createMatrix(int rows, int columns, std::ifstream& conf) {
//    int** matrix = new int*[rows];
//
//    for (int i = 0; i < rows; ++i) {
//        matrix[i] = new int[columns];
//    }
//
//    conf.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//    std::cout << "Matrix:" << std::endl;
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            conf >> matrix[i][j];
//            std::cout << matrix[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    return matrix;
//}
//
//double firstStep(int x) {
//    if (x < 0 && x % 2 == -1) {
//        double y = x / 3.0;
//        return y;
//    }
//    return (x);
//}
//
//double* SecondStep(double** matrix, int rows, int cols) {
//    double* res = new double[cols];
//    for (int j = 0; j < cols; ++j) {
//        double smallest = DBL_MAX;
//        for (int i = 0; i < rows; ++i) {
//            if ((matrix[i][j]) < smallest) {
//                smallest = (matrix[i][j]);
//            }
//        }
//        res[j] = smallest;
//    }
//    return res;
//}
//
//auto delMatrix = [](int** matrix, int rows) {
//    for (int i = 0; i < rows; ++i) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//    };
//
//void printMatrixToFile(double** doublArr, int rows, int cols, const std::string& filename) {
//    std::ofstream outfile(filename);
//
//    if (!outfile.is_open()) {
//        std::cerr << "Unable to open the file for writing." << std::endl;
//        return;
//    }
//
//    outfile << std::fixed << std::setprecision(2);
//
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            outfile << doublArr[i][j] << " ";
//        }
//        outfile << "\n";
//    }
//
//    outfile.close();
//}
//
//int main() {
//    ifstream conf("conf.txt");
//
//    int n, m;
//    conf >> n >> m;
//    int** arr = createMatrix(n, m, conf);
//
//    cout << "\nFirst step\n";
//
//    double** doublArr = new double*[n];
//    for (int i = 0; i < n; ++i) {
//        doublArr[i] = new double[m];
//    }
//
//    string firstStepFile = "step1.txt";
//
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            auto x = firstStep(arr[i][j]);
//            doublArr[i][j] = x;
//            cout << fixed << setprecision(2);
//            if (x == static_cast<int>(x)) {
//                cout << static_cast<int>(x) << " ";
//                
//            } else {
//                cout << x << " ";
//            }
//        }
//        cout << "\n";
//    }
//
//    printMatrixToFile(doublArr, n, m, firstStepFile);
//
//    double* newArr = SecondStep(doublArr, n, m);
//
//    cout << "\nSmallest element in each column:\n";
//    ofstream secondStep("step2.txt");
//    for (int j = 0; j < m; ++j) {
//        cout << "Column " << j << ": " << newArr[j] << "\n";
//        secondStep << "Column " << j << ": " << newArr[j] << "\n";
//    }
//
//    delMatrix(arr, n);
//    delete[] newArr;
//    return 0;
//}
