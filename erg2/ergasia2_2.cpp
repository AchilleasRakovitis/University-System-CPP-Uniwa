#include <iostream>
#include <string>
#include <fstream>

int SumandFactorial(const int&, unsigned long long int&, unsigned long long int&);
void printResults(const unsigned long long int&, const unsigned long long int&, const int&, const int& );

using namespace std;

int main(int argc, char** argv) {
    int N;
    unsigned long long int sum = 0;
    unsigned long long int factorial = 1;
    unsigned long long int median_sum = 0;
    unsigned long long int median_factorial = 0;
    int counter = 0;
    int counterS = 0;

    string natural;
    while(getline(cin, natural)){ //read each number and store it in natural
        N = stoi(natural); // convert every number string  to integer type
			   //
        SumandFactorial(N, sum, factorial); // function call

        if(sum != 0){ // if not overflow
            median_sum += sum; // total sum of every N calculation
	    counterS++;
        }

        if(factorial != 0){ // if not overflow 
            median_factorial += factorial; // total factorial of every N calculation
            counter++; 
        }
    }

    printResults(median_sum, median_factorial, counter, counterS); // print function called
    return 0;
}

int SumandFactorial(const int& N, unsigned long long int& sum, unsigned long long int& factorial) {
    sum = 0;
    factorial = 1;
    unsigned long long int flagSum;
    unsigned long long int flagFact;

    sum = N * (N + 1) / 2;  // sum of integers 1 - N

    // overflow check for sum 
    if(sum < N){  
        sum = 0;
        return 0;  
    }


    for(int i = 1; i <= N; i++){

        //flagSum = sum;
        flagFact = factorial;

        factorial *= i;

	//different way for computing the sum of the integers 1-N (does not work but i'm not sure why)
	
	//sum += i;
       /* if(sum < flagSum){
            sum = 0;
            return 0;
        } */
	
	// overflow check for factorial
        if(factorial / i  < flagFact){
            factorial = 0;
            return 0;
        }
    }

    return 1;
}

void printResults(const unsigned long long int& median_sum, const unsigned long long int& median_factorial, const int& counter, const int& counterS) {
    cout << "Average value of Sum: " << (double)median_sum / counterS << endl;
    cout << "Average value of Factorial: " << (double)median_factorial / counter << endl;
 // cout << "Counter of Factorial: " << counter << endl;
 // cout << "Counter of Sum " << counterS << endl;

}
