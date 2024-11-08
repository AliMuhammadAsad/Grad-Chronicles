#include<bits/stdc++.h>
using namespace std;
// -------------------------------------------------------------------------------- //
// Q1) River records. 
// Given an array of integers, without reordering, determine the maximum difference between any element and any prior smaller element.  
// If there is never a lower prior element, return -1.
// Eg: arr[5, 3, 6, 7, 4]. there is no prior than arr[0]. There is no earlier (smaller) than arr[1] which was 3. For arr[2], the prior smaller element is 3 and 5, so the difference is 6-3 = 3, and 6 - 5 = 1. For arr[3], the prior smaller element is 6, 3, 5, so the difference is 7-6 = 1, 7 - 3 = 4, 7 - 5 =2. For arr[4], the prior smaller element is 3, so the difference is 4-3 = 1. The maximum difference is 4 between arr[3] and arr[1].
// Eg: arr[4, 3, 2, 1]. No element has any prior element smaller than it, so return -1.
// Eg: arr[2, 2, 2, 2, 2]. Same as above, return -1
int maxTrailing(vector<int> arr) {
    int md = -1;
    if(arr.empty()) return md;
    int min = arr[0];
    for(int i = 1; i < arr.size(); i++){
        int curr = arr[i];
        if(curr > min){
            int d = curr - min;
            if(d > md) md = d;   
        }
        if(curr < min) min = curr;
    }
    return md;
}

// -------------------------------------------------------------------------------- //
// Q2) Vector operations

void print_vector(int size, int vector[]){
    for(int i = 0; i < size; i++) cout << vector[i] << " ";
}

void input_vector(int size, int vector[]){
    int value;
    for (int i = 0; i < size; i++){
        cin >> value; vector[i] = value;
    }
}

void add_vectors(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++) vector3[i] = vector1[i] + vector2[i];
}

void subtract_vectors(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++) vector3[i] = vector1[i] - vector2[i];
}

bool compare_vectors(int size, int vector1[], int vector2[]){
    bool flag = true;
    for (int i = 0; i < size; i++) if(vector1[i] != vector2[i]){flag = false; break;}
    return flag;
}

int main(){
    int size; cin >> size;
    bool flag;
    int vector1[size], vector2[size], vector3[size];
    input_vector(size, vector1); input_vector(size, vector2);
    char sign; cin >> sign;
    switch(sign){
        case '+':
            add_vectors(size, vector1, vector2, vector3);
            print_vector(size, vector3);
            break;
        case '-':
            subtract_vectors(size, vector1, vector2, vector3);
            print_vector(size, vector3);
            break;
        case '=':
            flag = compare_vectors(size, vector1, vector2);
            if(flag == true){
                cout << "EQUAL";
            }
            else {cout << "UNEQUAL";}
    }
    
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q3) String Length
// Given a string input by the user, find the length of the string. Since we do not know the length of the string, we are going to reserve sufficient space beforehand.
// We will input the string using cin.get() which read all characters until a newline character instead of cin which reads all characters until the first SPACE.
int string_length(char str[]){
    int len = 0;
    while(str[len] != '\0') len++;
    return len;
}

int main(){
    char str[1000]; cin.get(str, 1000);
    cout << string_length(str) << endl;
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q4) Pointegers
// Perform Bubble Sort and Iterative Binary Search using pointer to array of integers. USE POINTER OPERATIONS TO PERFORM THESE TASKS
// Create the following functions:
// sort_arr that takes two arguments, arr1 - pointer to an array of integers, and sz - an integer that represents the size of the array. The function does not returns any value. It performs Bubble Sort on the given array and update the same one with the sorted values USING POINTER OPERATIONS ONLY.
// binary_search that takes three arguments: arr1 - pointer to an array of integers, val - integer value to be searched, and sz - an integer that represents the size of the array. The function returns the index where the val is present. If not found, return -1. The function performs Iterative Binary Search to search for the given value USING POINTER OPERATIONS ONLY.
// main function should take input from the user: int_arr_len that represents the length of the array. If the value is 0 or negative, it should print a message on a separate line: "Incorrect size! Try Again" and keep on prompting the user until correct length is entered. Then define an array with that size, and take inputs from the user into the array. Finally, take input for the value to be searched. Once all the inputs are in, print the unsorted array in the given format as specified in Sample Output. Then call the sort_arr function to sort the array. After sorting, print the sorted array in the specified format. Then call the binary_search function to search for the inputted value. If the element is found, it should print the message with it's index as specified in the Sample Output. If not found, then print the message accordingly
void sort_arr(int* arr1, int sz){
    for(int i = 0; i < sz - 1; i++){
        for(int j = 0; j < sz - i - 1; j++){
            if(*(arr1 + j) > *(arr1 + j + 1)){
                int swap = *(arr1 + j); *(arr1 + j) = *(arr1 + j + 1); *(arr1 + j + 1) = swap;
            }
        }
    }
}

int binary_search(int* arr1, int val, int sz){
    int left = 0, right = sz - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(*(arr1 + mid) == val) return mid;
        if(*(arr1 + mid) < val) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void print_arr(int size, int* arr){
    cout << arr[0];
    for(int i = 1; i < size; i++) cout << ", " << *(arr + i);
    cout << endl;
}

int main(){
    int int_arr_len; cin >> int_arr_len;
    while(int_arr_len <= 0){
        cout << "Incorrect size! Try Again" << endl; cin >> int_arr_len;
    }
    int* arr = new int[int_arr_len];
    for(int i = 0; i < int_arr_len; i++) cin >> arr[i];
    int val_search; cin >> val_search;
    cout << "Before sorting: "; print_arr(int_arr_len, arr);
    sort_arr(arr, int_arr_len);
    cout << "After sorting: "; print_arr(int_arr_len, arr);
    cout << "\nThe value to be searched: " << val_search << endl;
    int index = binary_search(arr, val_search, int_arr_len);
    if(index == -1) cout << "Element is not present in the array!" << endl;
    else cout << "Element is present at index: " << binary_search(arr, val_search, int_arr_len) << endl;
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q5) Sorting Parts
// Make a struct Part with 3 attributes, modelnumber, years, price. Then create an array of parts type. write functions to take input, sort, and then finally display the sorted array. 
struct Part{
    int model, number; float price;
};

void sort(Part parts[], int N){
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - i - 1; j++){
            if(parts[j].price > parts[j + 1].price){Part swap = parts[j]; parts[j] = parts[j + 1]; parts[j + 1] = swap;}
        }
    }
}

void input(Part parts[], int N){
    for(int i = 0; i < N; i++) cin >> parts[i].price >> parts[i].number >> parts[i].model;
}

void display(Part parts[], int N){
    for(int i = 0; i < N; i++) cout << "Price: " << parts[i].price << ", Part No.: " << parts[i].number << ", Part Model: " << parts[i].model << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; cin >> n; Part parts[n];
    input(parts, n);
    sort(parts, n);
    display(parts, n);
    return 0;
}

// -------------------------------------------------------------------------------- //
// My Code Doesn't Work!
// Q6) ZigZag Array
// Given an array of integers, change it in such a way that it follows a zigzag pattern. A zig-zag array is one where for each integer, its adjacent integers are both greater than or less than itself. In other words, using L to mean a lower value and H to mean higher, the array follows either the pattern [L,H,L,H...] or [H,L,H,L...]. To make the array a zig-zag array, you can replace any element with any other integer (positive, negative, or zero). What is the minimum number of replacements required to accomplish this?
const int MaxInt = numeric_limits<int>::max();
const int MinInt = numeric_limits<int>::min();
 
int lhl(vector<int> arr, int sz){
    int carr[sz]; int count = 0;
    for(int i = 0; i < sz; i++) carr[i] = arr[i];
    // if(carr[0] >= carr[1]) carr[0] = MinInt;
    // if(carr[2] >= carr[1]) carr[2] = MinInt;
    for(int i = 1; i < sz; i++){
        if(i % 2 == 1){
            if(carr[i] <= carr[i - 1] && carr[i] <= carr[i + 1]) carr[i] = MaxInt;
            else{
                if(carr[i] <= carr[i - 1]) carr[i] = MaxInt;
                if(carr[i] <= carr[i + 1]) carr[i] = MaxInt;
            }
        }
        else{
            if(carr[i] >= carr[i - 1] && carr[i] >= carr[i + 1]) carr[i] = MinInt;
            else{
                if(carr[i] >= carr[i - 1]) carr[i] = MinInt;
                if(carr[i] >= carr[i + 1]) carr[i] = MinInt;
            }
        }
    }
    for(int i = 0; i < sz; i++) if(carr[i] == MaxInt || carr[i] == MinInt) count++;
    return count;
}

int hlh(vector<int> arr, int sz){
    int carr[sz]; int count = 0;
    for(int i = 0; i < sz; i++) carr[i] = arr[i];
    if(carr[0] <= carr[1]) carr[0] = MaxInt;
    if(carr[2] <= carr[1]) carr[2] = MaxInt;
    for(int i = 1; i < sz; i++){
        if(i % 2 == 1){
            if(carr[i] >= carr[i - 1] && carr[i] >= carr[i + 1]) carr[i] = MinInt;
            else{
                if(carr[i] >= carr[i - 1]) carr[i] = MinInt;
                if(carr[i] >= carr[i + 1]) carr[i] = MinInt;
            }
        }
        if(i % 2 == 0){
            if(carr[i] <= carr[i - 1] && carr[i] <= carr[i + 1]) carr[i] = MaxInt;
            else{
                if(carr[i] <= carr[i - 1]) carr[i] = MaxInt;
                if(carr[i] <= carr[i + 1]) carr[i] = MaxInt;
            }
        }
    }
    for(int i = 0; i < sz; i++) if(carr[i] == MaxInt || carr[i] == MinInt) count++;
    return count;
}

int minOperations(vector<int> arr){
    int sz = arr.size();
    int v1 = lhl(arr, sz), v2 = hlh(arr, sz);
    return min(v1, v2);
}

// -------------------------------------------------------------------------------- //
// Q7) Delete Element
// Write the function deleteElement that takes as parameters the pointer to the first node, and index within the range [0, length(list)-1].
// The function then deletes the corresponding node at index and returns the pointer to the new first node.

struct Node {
    int data;
    struct Node* next;
};


void printList(struct Node* n){
    cout << "current List : " << "\t";
    while (n != NULL) {
        cout<< n->data << "\t";
        n = n->next;
    }
    cout << "\n";
}

struct Node* deleteElement(struct Node* n, int index){
    // write your code here. 
    // The function takes the pointer to the first node as input argument, and index within the range [0, length(list)-1].
    // The function then deletes the corresponding node at index and returns the pointer to the new first node.
    if(index == 0){
        Node* temp = n->next; delete(n); return temp;
    }
    Node* curr = n; Node* prev = NULL;
    int curr_idx = 0;
    while(curr != NULL && curr_idx != index){
        prev = curr; curr = curr->next; curr_idx++;
    }
    if(curr == NULL) return n;
    prev->next = curr->next; delete(curr); 
    return n;
}

int main(){
    struct Node* list[5];

    // allocate memory for the list
    for (int i = 0; i < 5; i++) list[i] = new Node;

    // initialize the list
    for (int i = 0; i < 5; i++){
        list[i]->data = i*2;
        if (i == 4) list[i]->next = NULL;
        else list[i]->next = list[i + 1];
    }

    Node* header = list[0]; // header points to the first element of the list
    // print the list
    printList(header);

    //delete element at a specific index
    header = deleteElement(header, 4);

    // print the list
    printList(header);

    // de-allocate memory for the list
    Node* n = header;
    while (n != NULL){
        delete(n);
        n = n->next;
    }
    return 0;
}