#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

//initialize the size of the array to be compatible to hold the dataset
vector<int> H;
//int heapSize = H.size();
int heapSize = -1;


//Declaring functions

int parent(int i)       // i = child node
{
    return ((i-1) / 2);         
}

int leftChild(int i)    // i = parent node
{
    return (2 * i + 1);         
}

int rightChild(int i)   // i = parent node
{
    return (2 * i + 2);
}

void shiftUp(int i)
{
    while (i > 0 && H[i] > H[parent(i)]){
        
        //swap parent and current node
        swap(H[parent(i)], H[i]);

        //update node to be current parent
        i = parent(i);
    }
}

void shiftDown(int i)
{
   int tempParent = i;

   //Compare to left child
   int left = leftChild(i);

    if (left <= heapSize && H[left] > H[tempParent]){
        tempParent = left;
    }
    
    //Compare to right child
    int right = rightChild(i);
    if (right <= heapSize && H[right] > H[tempParent]){
        tempParent = right;
    }

    // If i not same as tempParent
    if (i != tempParent) {
        swap(H[i], H[tempParent]);
        shiftDown(tempParent);
    }
}

void enqueue(long long int p)
{
    // heapSize += 1;
    H.push_back(p);
    heapSize = H.size() - 1;
    //compare to parents, if larger shift up
    if (p > H[parent(p)]){
        shiftUp(heapSize);
    }

    // Print the queue after every insertion
    cout << " Priority Queue (enqueue): ";
    for (int k = 0; k <= heapSize; k++){
        cout << H[k] << " ";
    }
    cout << endl;
}

void heapify()
{
    for (int i = (heapSize - 1) / 2; i >= 0; i--)     //starts from last non-leaf nodes
    {
        shiftDown(i);
    }
}

// void printArrayOutputFile(vector<int>& H, ostream& os)
// {
//     //print to output file
//     for (int i = 0; i < heapSize; i++){
//         os << H[i] << " ";
//     }
//     os << endl;
//     cout << endl;
// }

void heapsort(vector<int>& H)
{
    heapSize = H.size() - 1;
    heapify();
    for (int i = heapSize; i > 0; i--)
    {
        swap(H[0], H[i]);
        heapSize--;
        shiftDown(0);

        // Print the updated queue
        cout << "Priority Queue : ";
        for (int k = 0; k <= H.size() - 1; k++){
            cout << H[k] << " ";
        }
        cout << endl;
    }

    // // Print the queue after every dequeue
    // cout << " Priority Queue (sorted): ";
    // for (int k = 0; k <= heapSize; k++){
    //     cout << H[k] << " ";
    // }
    // cout << endl;
    
    heapSize = H.size() - 1;
}

int main()
{
    // ifstream inputFile;
    // string filePath = "C:\\Users\\IZZATI ALIA.LAPTOP-ERD37JJV\\Downloads\\ALGORITHM DESIGN\\Assignment\\Q1\\d1\\set_1.txt";
    // inputFile.open(filePath);

    // ofstream os;
    // string outputFilePath = "output.txt";
    // os.open(outputFilePath);
    

    // if (inputFile.is_open()){
    //     int num;
    //     while (inputFile >> num) {
    //         enqueue(num); // assuming H is a vector<int>
    //     }
    //     inputFile.close();
    // }
    // else {
    //     std::cerr << "Unable to open file " << filePath << std::endl;
    //     return 1;
    // }

    // Print the queue after every insertion
    cout << " Priority Queue (enqueue): ";
    for (int k = 0; k <= heapSize; k++){
        cout << H[k] << " ";
    }
    cout << endl;

    auto startTimeEnqueue = chrono::high_resolution_clock::now();      //Record start time

    enqueue(90);
    enqueue(69);
    enqueue(13);
    enqueue(30);
    enqueue(60);
    enqueue(150);
    enqueue(109);
    enqueue(111);
    enqueue(110);

    auto endTimeEnqueue = chrono::high_resolution_clock::now();      //Record end time

    //Calculate duration enqueue time in ms
    auto durationEnqueueTime = chrono::duration_cast<chrono::milliseconds>(endTimeEnqueue - startTimeEnqueue).count();
    cout << "Execution time : " << durationEnqueueTime << "ms" << endl;

    cout << "\n";

    auto startTimeHeapsort = chrono::high_resolution_clock::now();      //Record start time

    heapsort(H);

    auto endTimeHeapsort = chrono::high_resolution_clock::now();      //Record end time

    //Calculate duration dequeue time in ms
    auto durationHeapsortTime = chrono::duration_cast<chrono::milliseconds>(endTimeHeapsort - startTimeHeapsort).count();
    cout << "Execution time : " << durationHeapsortTime << "ms" << endl;

    //  // Save output to another text file
    // if (os.is_open()) {
    //     os << "\n";
    //     os << "Sorted array: ";
    //     printArrayOutputFile(H, os);
    //     os << "\n";

    //     os << "Execution time: " << durationHeapsortTime << "ms" << endl;
    //     os.close();
    // } else {
    //     std::cerr << "Unable to open file " << outputFilePath << std::endl;
    //     return 1;
    // }
    
    // inputFile.close();
    return 0;
}
