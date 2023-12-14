//Qns 1 -> Steel Grade
// Checks for grade of steel based on certain conditions for hardness, carbon, tensile strength etc

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int steel_grade(int h, float c, int t) {
    int grade;
    bool c1 = false, c2 = false, c3 = false;
    if(h > 50){
        c1 = true;
    }
    if(c < 0.7){
        c2 = true;
    }
    if(t > 5600){
        c3 = true;
    }
    if(c1 ==  true && c2 == true && c3 == true){
        grade = 10;
    }
    else if (c1 == true && c2 == true && c3 == false){
        grade = 9;
    }
    else if (c1 == false && c2 == true && c3 == true){
        grade = 8;
    }
    else if (c1 == true && c2 == false && c3 == true){
        grade = 7;
    }
    else if (c1 == true || c2 == true || c3 == true){
        grade = 6;
    }
    else {
        grade = 5;
    }
    return grade;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int hard, tensile, grade;
    float carbon;
    cin >> hard >> carbon >> tensile;
    grade = steel_grade(hard, carbon, tensile);
    cout<<grade;
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------

//Qns 2 -> Frog Race
// Two frogs race up a well, they each ascend a certain level and descend a certain level then at one jump, 1000m deep well

#include <iostream>
#include <string>
using namespace std;;

int race(int prime_up, int prime_down, int tron_up, int tron_down){
    string winner;
    int jumps, prime_m, tron_m;
    jumps = 0; prime_m = 0; tron_m = 0;
    while(prime_m <= 1000 || tron_m <= 1000){
        jumps += 1;prime_m += prime_up; tron_m += tron_up;
        if (prime_m >= 1000 && tron_m < 1000){
            tron_m -= tron_down;
            cout <<"Jump "<< jumps << endl;
            cout <<"Frog Prime has cleared the well!" << endl;
            cout <<"Frogatron is at " << tron_m <<" meters."<<endl;
            cout <<"** END OF RACE **"<<endl;
            cout <<"Frog Prime wins in "<< jumps << " jumps!"<<endl;
            break;
        }
        else if (prime_m < 1000 && tron_m >= 1000){
            prime_m -= prime_down;
            cout << "Jump "<< jumps << endl;
            cout << "Frog Prime is at " << prime_m << " meters." << endl;
            cout << "Frogatron has cleared the well!"<<endl;
            cout <<"** END OF RACE **"<<endl;
            cout <<"Frogatron wins in "<< jumps<< " jumps!"<<endl;
            break;
        }
        else if (prime_m >= 1000 && tron_m >= 1000){
            cout << "Jump "<< jumps << endl;
            cout <<"Frog Prime has cleared the well!" << endl;
            cout << "Frogatron has cleared the well!"<<endl;
            cout <<"** END OF RACE **"<<endl;
            cout <<"TIE in "<< jumps << " jumps!"<<endl;
            break;
        }
        else if (prime_m < 1000 && tron_m < 1000) {
            prime_m -= prime_down; tron_m -= tron_down;
            cout <<"Jump "<< jumps<< endl;
            cout <<"Frog Prime is at " << prime_m << " meters."<< endl;
            cout <<"Frogatron is at " << tron_m << " meters." << endl;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
  int prime_up, prime_down, tron_up, tron_down;
  std::cin >> prime_up >> prime_down >> tron_up >> tron_down;
  race(prime_up, prime_down, tron_up, tron_down);
  return 0;
}

//------------------------------------------------------------------------------------------------------------------------

// Qns 3 -> Fibonacci's Rule
// Use fibonacci's rule to calculate the next terms in the series upto nth term.

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int series(int term_0, int term_1, int n){
    int next_term;
    for (int i = 0; i <= n; i += 1){
        if(i == 0){
            cout << term_0;
        }
        else if (i == 1) {
            cout << ", " << term_1;
        }
        else {
            next_term = term_0 + term_1; term_0 = term_1, term_1 = next_term;
            cout << ", " << next_term ;
        }
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int term_0, term_1, n;
    cin >> term_0 >> term_1 >> n;
    series(term_0, term_1, n);
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------

// Qns 4 -> Count holes
// Each number has holes, like 0 has 1 one, 8 has 2, 1 has none. So it counts the total number of holes in any integer number

#include<iostream>
using namespace std;
int countHoles(int num){
    int holes, temp_num; holes = 0, temp_num = 0;
    while (num != 0){
        temp_num = num % 10; num /= 10;
        if (temp_num == 0 || temp_num == 4 || temp_num == 6 || temp_num == 9){
            holes += 1;
        }
        else if (temp_num == 8) {
            holes += 2;
        }
    }
    return holes;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num;
    cin>>num;
    cout<<countHoles(num)<<" holes";
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------

// Qns 5 -> Exponent result using multiplication
// Base is between 1 and 10, exponent is between 0 and 5

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int base, exponent, result;
    cin >> base >> exponent;
    result = 1;
    if ((base < 1 || base > 10) || (exponent < 0 || exponent > 5)){
        cout<<"Invalid input!";
    }
    else {
        for(int i = 0; i < exponent; i += 1){
            result *= base;
        }
        cout << base << " to the power of " << exponent << " is: " << result;
    }
    return 0;
}
