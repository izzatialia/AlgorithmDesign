#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

//initialize the size of the array to be compatible to hold the dataset
vector<int> A;
//int arraySize = 0;

void printArray(vector<int>& A, int n)
{
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    cout << endl;
}

void printArrayOutputFile(vector<int>& A, int n, ostream& os)
{
    //print to output file
    for (int i = 0; i < n; i++){
        os << A[i] << " ";
    }
    os << endl;
    cout << endl;
}

void selectionsort(vector<int>& A, int n, ostream& os)
{
    for (int i = 0; i < n - 1; i++){
        int minValue = i;

        for (int j = i+1; j < n; j++){
            if (A[j] < A[minValue]){
                minValue = j;
            }
        }

        swap(A[minValue], A[i]);

        // Print the array after every iteration
        cout << "\n";
        cout << "Iteration " << i+1 << ": ";
        printArray(A, n);
        printArrayOutputFile(A, n, os);
    }
}

int main()
{
    ifstream inputFile;
    string filePath = "C:\\Users\\IZZATI ALIA.LAPTOP-ERD37JJV\\Downloads\\ALGORITHM DESIGN\\Assignment\\Q1\\d1\\set_1.txt";
    inputFile.open(filePath);

    ofstream os;
    string outputFilePath = "output.txt";
    os.open(outputFilePath);

    if (inputFile.is_open()){
        int num;
        while (inputFile >> num) {
            A.push_back(num); // assuming A is a vector<int>
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open file " << filePath << std::endl;
        return 1;
    }
    
    //int A[] = {640, 215, 122, 22, 311};
    int n = A.size();
    
    cout << "Original array : ";
    printArray(A, n);
    cout << "\n";

    // Write original array to output file
    if (os.is_open()) {
        os << "Original array: ";
        printArrayOutputFile(A, n, os);
        os << "\n";
    }
    
    auto startTime = chrono::high_resolution_clock::now();      //Record start time

    selectionsort(A, n, os);

    auto endTime = chrono::high_resolution_clock::now();      //Record end time

    cout << "\n";
    cout << "Sorted array : ";
    printArray(A, n);

    //Calculate duration enqueue time in ms
    auto durationTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
    cout <<"\n" << "Execution time : " << durationTime << "ms" << endl;

    cout << "\n";

    // Save output to another text file
    if (os.is_open()) {
        os << "\n";
        os << "Sorted array: ";
        printArrayOutputFile(A, n, os);
        os << "\n";

        os << "Execution time: " << durationTime << "ms" << endl;
        os.close();
    } else {
        std::cerr << "Unable to open file " << outputFilePath << std::endl;
        return 1;
    }

    return 0;
}