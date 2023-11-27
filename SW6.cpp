//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <random>
//
//using namespace std;
//
//bool validateInput(int &value) {
//    double input;
//    if (cin >> input && modf(input, &input) == 0) {
//        value = static_cast<int>(input);
//        return true;
//    } else {
//        cerr << "Invalid input. Please enter an integer." << endl;
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        return false;
//    }
//}
//
//void randomizeArray(double* arr, int length) {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_real_distribution<> dis(0.0, 100.0);
//
//    for (int i = 0; i < length; i++) {
//        arr[i] = round(dis(gen) * 100.0) / 100.0;
//    }
//}
//
//double findMaxValue(double* arr, int length) {
//    if (length == 0) {
//        cerr << "Array is empty!" << endl;
//        return 0.0;
//    }
//    const double* ptr = arr;
//    double maxValue = *ptr;
//    for (int i = 1; i < length; ++i) {
//        ++ptr;
//        if (*ptr > maxValue) {
//            maxValue = *ptr;
//        }
//    }
//    return maxValue;
//}
//
//double findMinValue(const double* arr, int length) {
//    if (length == 0) {
//        std::cerr << "Array is empty!" << std::endl;
//        return 0.0;
//    }
//    const double* ptr = arr;
//    double minValue = *ptr;
//    for (int i = 1; i < length; ++i) {
//        ++ptr;
//        if (*ptr < minValue) {
//            minValue = *ptr;
//        }
//    }
//    return minValue;
//}
//
//void printArray(const double* arr, int length) {
//    const double* ptr = arr;
//    for (int i = 0; i < length; ++i) {
//        cout << *ptr << " ";
//        ++ptr;
//    }
//}
//
//void writeToFile(const double* arr, int length, double max, double min, const string& filename, bool cleartxt) {
//    ofstream fout(filename, cleartxt ? ios::trunc : ios::app);
//
//    const double* ptr = arr;
//    for (int i = 0; i < length; ++i) {
//        fout << *ptr << " ";
//        ++ptr;
//    }
//
//    fout << "\nmax: " << max << endl;
//    fout << "min: " << min << endl;
//    fout << "sum: " << min + max << endl;
//
//    fout.close();
//}
//
//int main() {
//    bool writeToTextFile = false;
//    bool cleartxt = false;
//    string write;
//    cout << "Do you want to write the result to the text.txt file (press y or clear all press c)" << endl;
//    cin >> write;
//    transform(write.begin(), write.end(), write.begin(), ::tolower);
//    write.erase(remove(write.begin(), write.end(), ' '), write.end());
//
//    if (write == "y") {
//        writeToTextFile = true;
//    } else if (write == "c") {
//        writeToTextFile = true;
//        cleartxt = true;
//    }
//
//    int len;
//    bool validInput = false;
//    while (!validInput) {
//        cout << "Enter a positive integer n: ";
//        validInput = validateInput(len) && len > 0;
//    }
//
//    double* mainArr = new double[len];
//
//    try {
//        randomizeArray(mainArr, len);
//        printArray(mainArr, len);
//
//        double max = findMaxValue(mainArr, len);
//        double min = findMinValue(mainArr, len);
//        cout << "\nMAX:" << max << endl;
//        cout << "MIN:" << min << endl;
//        cout << "sum:" << min + max << endl;
//
//        if (writeToTextFile) {
//            writeToFile(mainArr, len, max, min, "text.txt", cleartxt);
//        }
//    } catch (exception &e) {
//        cerr << "An error occurred: " << e.what() << endl;
//    }
//
//    delete[] mainArr;
//
//    return 0;
//}