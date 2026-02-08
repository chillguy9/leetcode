// #include<iostream>
// using namespace std;

// class node{
// public:

// int data ;
// node* next;

// node(int x){
//     data = x;
//     next = NULL;
// }
// };
// class ll{

// public :

// node* head = NULL;
// node* tail = NULL;

// void push_back(int x){
//     node* newnode = new node(x);
//     if(head ==  NULL){
//       head = tail = newnode;
//     }
//     else{
//      tail->next =newnode;
//      tail = newnode;
//     }
// }
// void insert(int num , int idx){
//     node* newnode = new node(num);
//     if(idx<0){
//        cout<<" invalide ";
//         return;
//     }

//     node* temp = head;
//     int index =0;
//     while(index != idx-1){
//         temp = temp->next;
//         index++;
//     }
//     newnode->next = temp->next;
//     temp->next = newnode;
    
//     //r(1) = 5;
    

// }
// void delet(int idx){
   
//     node* temp = head;

//     int i=0;
//     while(i != idx-1){
//         temp = temp->next;
//         i++;
//     }
//     node* x = temp->next;

//     temp->next = x->next;
//     x->next = NULL;
//     delete x;

// }

// void display(){
//  node* temp = head;

//  while(temp != NULL){
//   cout<<temp->data<<" ";
//   temp = temp->next;
     
//  }

// }
// };
// int main(){

//      ll l1;

//      l1.push_back(1);
//      l1.push_back(2);
//      l1.push_back(3);
//      l1.push_back(4);
//      l1.insert(9,3);
//      l1.delet(3);
// l1.display();
// }
#include <iostream>
using namespace std;

//swap two numbers
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Bubble sort
void bubbleSort(int array[], int size) {
    bool swapped = false; //intialize for swapping
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
               swapped =false;
            }
            if(swapped) return;  // If no swaps, array is sorted
        }
    }
}

// For quick sort, partition is used here. 
int partition(int array[], int start, int end) {
    int pivot = array[end];
    int pIndex = start - 1;  //  pIndex for partition index

    for (int j = start; j < end; ++j) {
        if (array[j] <= pivot) {
            ++pIndex;
            swap(array[pIndex], array[j]);
        }
    }
    swap(array[pIndex + 1], array[end]);
    return pIndex + 1;
}

//quick sort recursive function.
void quickSort(int array[], int start, int end) {
    if (start < end) {
        int pi = partition(array, start, end);
        quickSort(array, start, pi - 1);
        quickSort(array, pi + 1, end);
    }
}

// Merge sort 
void merge(int array[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    // dynamic allocation for left and right arrays
    int *leftArray = new int[leftSize];
    int *rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; ++i)
        leftArray[i] = array[left + i];
    for (int j = 0; j < rightSize; ++j)
        rightArray[j] = array[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        } else {
            array[k++] = rightArray[j++];
        }
    }

    // Copy any leftovers
    while (i < leftSize) array[k++] = leftArray[i++];
    while (j < rightSize) array[k++] = rightArray[j++];

    delete[] leftArray;
    delete[] rightArray;  
}

// The merge sort itself, recursive divide and conquer.
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;  
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

// Linear search
int linearSearch(int array[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) return i;
    }
    return -1;  // Not found
}

// Binary search
int binarySearch(int array[], int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (array[mid] == target) return mid;
        if (array[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

//print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    int numbers[size], backup[size];  // Backup to reset for each sort
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
        backup[i] = numbers[i];
    }

    int option;
   
        cout << "\nWhich Sorting do you to perform? \n";
        cout << "1. Bubble Sort it\n";
        cout << "2. Quick Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Quit\n";
        cout << "Pick: ";
        cin >> option;

        // Reset to original each time
        for (int i = 0; i < size; ++i) numbers[i] = backup[i];

        cout << "\nStarting with: ";
        printArray(numbers, size);

        switch (option) {
            case 1:
                bubbleSort(numbers, size);
                cout << "Bubble Sorting donr: ";
                printArray(numbers, size);
                break;
            case 2:
                quickSort(numbers, 0, size - 1);
                cout << "Quick Sorted done: ";
                printArray(numbers, size);
                break;
            case 3:
                mergeSort(numbers, 0, size - 1);
                cout << "Merge Sorted done: ";
                printArray(numbers, size);
                break;
            case 4:
                cout << "Sorting Completed\n";
                break;
            default:
                cout << "Fail\n";
        }

        if (option >= 1 && option <= 3) {
            int searchOpt, target;
            cout << "\nWhat Searching you want to perform? \n";
            cout << "1. Linear\n";
            cout << "2. Binary\n";
            cout << "3. Back\n";
            cout << "Choose: ";
            cin >> searchOpt;

            if (searchOpt == 1 || searchOpt == 2) {
                cout << "Enter the number you want to find ? :";
                cin >> target;

                int foundAt;
                if (searchOpt == 1) {
                    foundAt = linearSearch(numbers, size, target);
                    cout << "Linear Search : ";
                } else {
                    foundAt = binarySearch(numbers, 0, size - 1, target);
                    cout << "Binary Search: ";
                }

                if (foundAt != -1) {
                    cout << "Found at position " << foundAt << endl;
                } else {
                    cout << "Position not found\n";
                }
            }
        }
   

    return 0;
}


