#include<iostream>
using namespace std;

int main(){
    // Conditionals(if else, switch case) and Loops(for, while)
    
    // // Decision Making , if else if 
    // float attendance; int CP; //attendance and class participation
    // cout << "Enter total attendance in percentage: "; cin >> attendance;
    // cout << "Enter total Class Participation in percentage: "; cin >> CP;
    // if (attendance >= 85 && attendance <= 100)
    //     cout << "Habib ki attendance policy se main thak gaya hun" << endl;
    // else if (CP >= 80 && CP <= 100){
    //     cout << "Attendance ne marwaya, lkn CP ne bacha liya shukr hai" << endl;
    //     cout << "Attendance is " << attendance << "and Cp is" << CP << endl;
    // }
    // else cout << "Le bhai, RO ne tou course se nikal dena hai ab" << endl;

    // // Notice that i've used {} and have not used. Why so? Agar aik hi statement hai condition k baad, tou phir {} ki zaroorat nhi, lkn agar aik se zyada statements aani hein condition k baad, tou phir tou {} ki zaroorat hai and statements will be inside {}.

    // //Switch case - personally my fav and sassy
    // int choice; cout << "Please select payment option:\n" << "1.Debit card \n2.Cash \n3.Bank transfer \n4.exit\n";
    // cin >> choice;

    // switch(choice){
    //     case 1: cout << "Enter debit card number ..... \n";
    //     break; //this break statement will break out of the condition, also this doesn't have to be in the next line necessarily
    //     case 2: cout << "Enter amount ..... \n"; break;
    //     case 3: cout << "Enter account details ..... \n"; break;
    //     case 4: cout << "No option selected, exiting ..... \n"; break;
    //     default: cout << "Invalid option \n"; break; 
    // }

    // //Note: 
    // // 0 - 65535 --> total values = 65536
    // //overflow warning message
    // // unsigned short int num = 65536 ;
    // // cout << num << endl;

    // Loops
    
    cout << "For Loop:" << endl;
    int sum = 0;
    // Syntax of for loop:  for (iter variable; iteration condition; increment) {statements}. V simple syntax
    for (int i = 0; i <= 5; i++){ //We have to declare the local variable for the loop, the stopping condition and the increment 
        sum += i;
        cout << "Iteration :" << i;
        cout << "\tSum is : " << sum << endl;
    }

    cout << "While Loop:" << endl;
    // Decalre var whatever for while loop, while (condition) {statements}. V simple syntax 
    int j = 0;
    while (j <= 5){
        cout << "Iteration :" << j << endl;
        j++;
    }

    cout << "Do-While Loop:" << endl; //Not much used and blegh for me personally, a lil muhskil syntax and can always be replaced by while and for loops. I don't like this at all and haven't used it ever in anything - literally faltu hai
    int k = 1;
    do {
        cout << "Iteration: " << k << endl;
        k++;
    } while (k <= 5);

    system("pause");
}