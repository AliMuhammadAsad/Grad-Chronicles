#include <iostream>
using namespace std;

// -------------------------------------------------------------------------------- //
// Q1) Simple Calculator - Using Switch Case
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n1, n2; char op;
    cin >> n1 >> n2 >> op;
    switch(op){
        case '+': cout << n1 << " + " << n2 << " = " << n1 + n2; break;
        case '-': cout << n1 << " - " << n2 << " = " << n1 - n2; break;
        case '*': cout << n1 << " * " << n2 << " = " << n1 * n2; break;
        case '/': cout << n1 << " / " << n2 << " = " << n1 / n2; break;
        default: cout << "Error! The operator is not correct"; break;
    }
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q2) Library information:

void book_information(int category, int subcategory, int borrow_days) {
   switch(borrow_days > 15){
       case 1: cout << "You can not issue a book for more than 15 days at our library!" << endl; break;
       case 0:{
           switch(category){
               case 1:{
                   switch(subcategory){
                       case 1: cout << "Issued you a novel in the subcategory of Murder Mystery for " << borrow_days << " days." << endl; break;
                       case 2: cout << "Issued you a novel in the subcategory of Thriller for " << borrow_days << " days." << endl; break;
                       case 3: cout << "Issued you a novel in the subcategory of Science Fiction for " << borrow_days << " days." << endl; break;
                       default: cout << "Issued you a novel for " << borrow_days << " days." << endl; break;
                   }
               }
               break;
               case 2:{
                    switch(subcategory){
                        case 1: cout << "Issued you a course book in the subcategory of Mathematics for " << borrow_days << " days." << endl; break;
                        case 2: cout << "Issued you a course book in the subcategory of Physics for " << borrow_days << " days." << endl; break;
                        case 3: cout << "Issued you a course book in the subcategory of Biology for " << borrow_days << " days." << endl; break;
                        default: cout << "Issued you a course book for " << borrow_days << " days." << endl; break;
                    }
               }
           }
       }
   }
}
int main() {
    
    int category, subcategory, borrow_days;
    cin >> category >> subcategory >> borrow_days;
  
    book_information(category, subcategory, borrow_days);

    return 0;
}



// -------------------------------------------------------------------------------- //
// Q3) Chronological Human History

void input_years(int yrs[], int num_yrs){
    for (int i = 0; i < num_yrs; i++){
        cin >> yrs[i];
        while(yrs[i] < 0 || yrs[i] > 9999){
            cout << "Year can be between 0 and 9999! Try Again!" << endl;
            cin >> yrs[i];
        }
    }
}

void print_yrs_array(int yrs[], int num_yrs){
    cout << yrs[0];
    for(int i = 1; i < num_yrs; i++){
        cout << ", " << yrs[i];
    }
}

void chronological_order(int yrs[], int num_yrs){
    for(int i = 0; i < num_yrs - 1; i++){
        for(int j = 0; j < num_yrs - i -1; j++){
            if(yrs[j] > yrs[j+1]){
                int swapper = yrs[j]; yrs[j] = yrs[j + 1]; yrs[j + 1] = swapper;
            }
        }
    }
}

int main(){
    int num_yrs; cin >> num_yrs;
    while(num_yrs < 2){
        cout << "Need at least 2 years to sort! Try Again!"<<endl;
        cin >> num_yrs;
    }
    int yrs[num_yrs];
    input_years(yrs, num_yrs);
    cout << "The initial array is: "; print_yrs_array(yrs, num_yrs);
    chronological_order(yrs, num_yrs);
    
    cout << "\nThe sorted array is: "; print_yrs_array(yrs, num_yrs); 
}

// -------------------------------------------------------------------------------- //
// Q4) Vector Operations
#include<iostream>
using namespace std;

void print_vector(int size,int vector[]){
    for(int i = 0; i < size; i++){
        cout << vector[i] << " ";
    }
}

void input_vector(int size, int vector[]){
    for (int i = 0; i < size; i++){
        cin >> vector[i];
    }  
}

void add_vectors(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] + vector2[i];
    }
}

void subtract_vectors(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] - vector2[i];
    }
}

bool compare_vectors(int size, int vector1[], int vector2[]){
    bool flag = true;
    for (int i = 0; i < size; i++){
        if (vector1[i] != vector2[i]) {flag = false; break;}
    }
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
// Q5) Matrix Arithmetic

void print_matrix(int row, int col, int size,int vector[]){
    for(int i = 0; i < col; i++){
        cout << vector[i] << " ";
    }
    cout <<endl;
    for(int i = col; i < size; i++){
        cout << vector[i] << " ";
    }
}

void input_matrix(int size, int vector[]){
    for (int i = 0; i < size; i++){
        cin >> vector[i];
    }  
}

void add_matrices(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] + vector2[i];
    }
}

void subtract_matrices(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] - vector2[i];
    }
}

int main(){
    int row, col, size; cin >> row >> col;
    size = row * col;
    // bool flag;
    int vector1[size], vector2[size], vector3[size];
    input_matrix(size, vector1); input_matrix(size, vector2);
    char sign; cin >> sign;
    switch(sign){
        case '+':
            add_matrices(size, vector1, vector2, vector3);
            print_matrix(row, col, size, vector3);
            break;
        case '-':
            subtract_matrices(size, vector1, vector2, vector3);
            print_matrix(row, col, size, vector3);
            break;
    }
}