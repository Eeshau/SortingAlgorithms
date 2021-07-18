#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

///BUBBLE SORT
void bubbleSort( vector<int> numbers) {
    for(int i=0; i<numbers.size(); i++) {
        for(int j=0; j<(numbers.size()-i-1); j++) {
            //checking if the number to the left is larger
            if(numbers[j]>numbers[j+1]) {

                for (int k=0; k<numbers.size();k++) {
                    cout <<numbers[k] << " ";
                }
                cout<<"-->";
                // if the number is larger than swap them out.
                int temp = numbers[j]; //use a temporary variable
                numbers[j]= numbers[j+1]; //swap them
                numbers[j+1]=temp; // set the number on the left to the next number
                for (int k=0; k<numbers.size();k++) {
                    cout << numbers[k] << " ";
                }
                cout<<endl;
            }
        }
    }
}



///SELECTION SORT
void selectionSort(vector<int> numbers) {
    int minVal,temp;
    for (int i=0; i<numbers.size()-1; i++) {
        minVal=i;
        for (int j=i+1; j<numbers.size(); j++) {

            for (int k=0; k<numbers.size();k++) {
                cout <<numbers[k] << " ";
            }
            cout<<" Min val: " <<numbers[minVal]<<"    --> ";

            if ( numbers[j]< numbers[minVal]) {
                minVal=j;
            }
        }
        temp = numbers[minVal];
        numbers[minVal]=numbers[i];
        numbers[i]=temp;

        for (int k=0; k<numbers.size();k++) {
            cout <<numbers[k] << " ";
        }
        cout<<endl;
    }
}

///INSERTION SORT
void insertionSort(vector<int> numbers) {
    for(int i=0; i<numbers.size(); i++) {
        int value = numbers[i];
        int hole = i;

        for (int k=0; k<numbers.size();k++) {
            cout <<numbers[k] << " ";
        }
        cout<<" hole at "<<numbers[hole]<<" --->";

        while (hole>0 && numbers[hole-1] > value) {
            numbers[hole]= numbers[hole-1];
            hole--;
        }

        numbers[hole]=value;

        for (int k=0; k<numbers.size();k++) {
            cout <<numbers[k] << " ";
        }
        cout<<endl;
    }
}




///MERGE SORT MERGE FUNCTION
vector<int> merge(vector <int> &numbers, vector<int> &left, vector<int> &right) {
    int li=0;
    int ri=0;
    vector<int> temp;
        while( li<left.size() && ri< right.size()) {
            if (left[li] < right[ri]){
                temp.push_back(left[li]);
                for (int k=0; k<temp.size();k++) {
                    cout <<temp[k] << " ";
                }
                cout<<endl;
                li++;
            } else {
                temp.push_back(right[ri]);
                for (int k=0; k<temp.size();k++) {
                    cout <<temp[k] << " ";
                }
                cout<<endl;
                ri++;
            }
        }
    while(li < left.size()){
        // push the rest of the values back because they're sorted
        temp.push_back(left[li]);
        for (int k=0; k<temp.size();k++) {
            cout <<temp[k] << " ";
        }
        cout<<endl;
        li++;
    }
    while(ri < right.size()){
        // do the same for the right
        temp.push_back(right[ri]);
        for (int k=0; k<temp.size();k++) {
            cout <<temp[k] << " ";
        }
        cout<<endl;
        ri++;
    }
    return temp;
}

///MERGE SORT
vector<int> mergeSort(vector<int> &temp) {
    // base case, we are done!
    if(temp.size() == 1) {

        return temp;
    }

    // find the middle split
    vector<int>::iterator mid = temp.begin() + (temp.size() / 2);
    //split into new vectors right and left
    vector<int> left(temp.begin(), mid);
    vector<int> right(mid, temp.end());


    //recursively call on the new right and left vectors
    left = mergeSort(left);
//    cout<<"\n Left side: ";
//    for (int k=0; k<left.size();k++) {
//        cout <<left[k] << " ";
//    }
//    cout<<endl;

    right = mergeSort(right);

//    cout<<"\n right side: ";
//    for (int k=0; k<right.size();k++) {
//        cout <<right[k] << " ";
//    }
//    cout<<endl;

    //merge them back
    return merge(temp, left, right);
}








///QUICK SORT
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// makes last element pivot, puts the pivot element at its correct position in sorted vector, left smaller right bigger than pivot
int partition (vector<int> &numbers, int low, int high)
{
    int pivot = numbers[high];    // pivot number
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++) {
        // If current element is smaller than or equal to pivot
        if (numbers[j] <= pivot) {
            i++;    // increment index of smaller element
            swap(&numbers[i], &numbers[j]);
        }
    }
    swap(&numbers[i + 1], &numbers[high]);
    for (int k=0; k<numbers.size(); k++) {
        cout<<numbers[k]<< " ";
    }
    cout<<endl;
    return (i + 1);
}

///QUICK SORT
void quickSort(vector<int> &numbers, int low, int high) {
    //checking that there's more than one number in the vector
    if (low <= high) {
        // pi is partitioning index, vector[p] is now at right place
        int pi = partition(numbers, low, high);

        // Separately sort elements before and after partition
        quickSort(numbers, low, pi - 1);
        quickSort(numbers, pi + 1, high);
    }
}





int main() {
    fstream inFile;
    string line;
    inFile.open("/Users/eeshaulhaq/CLionProjects/BubbleSort/data.txt");
    vector<int> numbers;

    //READ THE NUMBERS FROM THE FILE INTO THE NUMBERS VECTOR
    if (inFile.is_open()) {
        while ( getline (inFile,line) ) {
            int num = stoi(line);
            numbers.push_back(num);
        }
        inFile.close();
    }

    for (int k=0; k<numbers.size(); k++) {
        cout<<numbers[k]<< " ";
    }
    cout<<endl;
    quickSort(numbers, 0, numbers.size()-1);


//    vector<int> newNumbers = mergeSort(numbers);
//    for (int k=0; k<newNumbers.size();k++) {
//        cout <<newNumbers[k] << " ";
//    }

    return 0;
}