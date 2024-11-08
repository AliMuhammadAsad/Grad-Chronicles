/*
Datarates Class
In telecommunications and computing, data rate is the number of bits that are conveyed or processed per unit of time. The data rate is quantified using the bits per second unit (symbol: "bit/s"), often in conjunction with an SI prefix such as "kilo" (1 kbit/s = 1,000 bit/s), "mega" (1 Mbit/s = 1,000 kbit/s), "giga" (1 Gbit/s = 1,000 Mbit/s). The non-standard abbreviation "bps" is often used to replace the standard symbol "bit/s", so that, for example, "1 Mbps" is used to mean one million bits per second.

As you are working with a project that involves manipulation of data rate that uses standard/non-standard notations of data, you decided to create a class DataRate to handle the data rate in efficient way.

You're required to design and implement a class DataRate with necessary functions/operators/constructors to make main function running with your code.

Functions Description
DataRate object can work with cin => overload >> operator => the Input will be in different data units convert them into bps
DataRate object are printed with cout=> overload << operator, It prints the value in bps. e.g. 4 kbps will be printed as 4000 bps
DataRate ojects can be converted to integers
Supported notations are (case sensitive):
bps, bit/s, b/s
kbps, kbit/s, kb/s
Mbps, Mbit/s, Mb/s
Gbps, Gbit/s, Gb/s

You are also required to provide implementation to BubbleSort function to sort the array of DataRate objects. The sum of all the data rates is also to be found. Follow the comments given in the main function.

Constraints:
the attributes of the class must be private. Getter/Setter functions CANNOT be used.
▶ Input Format For Custom Testing

▼ Sample Case 0

Sample Input For Custom Testing

2
50 kbps
30 kbit/s

Sample Output
DataRate objects after sorting:
30000 bps
50000 bps
Total datarate is: 80000 bps

Explanation
First line is 2, hence 2 objects array is created.
It's sorted, and the elements are printed in ascending order, in bps.
Total of all the data rates are printed. i.e. 30000+50000 = 80000 bps.
*/

#include<bits/stdc++.h>
using namespace std;

class DataRate{
    unsigned int rate;

    public:
    DataRate(){
        // Implement here
        rate = 0;
    }

    friend istream& operator >> (istream& in, DataRate& d1){
        // Implement istream
        string unit; int r;
        in >> r; in >> unit;
        if(unit == "bps" || unit == "bit/s" || unit == "b/s") d1.rate = r;
        else if(unit == "kbps" || unit == "kbit/s" || unit == "kb/s") d1.rate = r*1000;
        else if(unit == "Mbps" || unit == "Mbit/s" || unit == "Mb/s") d1.rate = r*1000000;
        else if(unit == "Gbps" || unit == "Gbit/s" || unit == "Gb/s") d1.rate = r*1000000000;
        return in;
    }

    friend ostream& operator << (ostream& out, const DataRate& d1){
        // Implement ostream
        out << d1.rate << " bps";
        return out;
    }

    operator unsigned int(){
        // Implement here
        return rate;
    }

    bool operator > (const DataRate& d1){
        // Implement here
        return rate > d1.rate;
    }
};

void BubbleSort(DataRate rates[], int n){
    // Implement Inplace Sorting
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(rates[j] > rates[j + 1]){
                swap(rates[j], rates[j + 1]);
            }
        }
    }
}


int main(){
    int lines;
    cin>>lines;
    DataRate rates[lines];

    for(int i=0;i<lines; i++){
        // DataRate object can work with cin
        cin>>rates[i];
    }

    // Implement BubbleSort function to sort the DataRate objects
    BubbleSort(rates, lines);

    cout<<"DataRate objects after sorting: "<<endl;
    for(int i=0;i<lines; i++){
        // cout works with DataRate objects
        // It prints all the objects in bps unit. e.g. 4 kbps will be printed as 4000 bps
        cout<< rates[i] <<endl;
    }

    unsigned int total = 0;
    for(int i=0;i<lines;i++){
        // DataRate object can be converted to unsigned int 
        total += rates[i];
    }

    cout<<"Total datarate is: "<< total <<" bps" <<endl;

    return 0;
}