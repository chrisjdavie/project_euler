/*
 * question_002.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: chris
 *
 *  Description : Project Euler number 2.
 *
 *  https://www.hackerrank.com/contests/projecteuler/challenges/euler002
 *
 *  Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 *  By considering the terms in the Fibonacci sequence whose values do not exceed N, find the sum of the even-valued terms.
 *
 */

#include <iostream>
using namespace std;

int main() {
	//
	// In implementing this, I'm using the following relations
	//
	// That every 3rd Fibonacci number is even (obvious from thinking
	// and inspection)
	//
	// I now restructure Fibonacci to extract only the 3rd terms.
	// This is not to speed up calculation, but to reduce the amount
	// of code (both solutions are O(n))
	//
	// Standard Fibonacci relation
	// F(n) = F(n-1) + F(n-2) (1)
	//
	// Shift to once place back recursively
	// F(n) = 2*F(n-2) + F(n-3) (2)
	//
	// Expand F(n-2), then F(n-4) using (1)
	// F(n) = 3*F(n-3) + 2*F(n-5) + 2*F(n-6)
	//
	// Then, using (2)
	// F(n) = 4*F(n-3) + F(n-6)
	//
	// move to 3*n -> m, and set F(m=0) = 0, F(m=1) = 2
	// F(m) = 4*F(m-1) + F(m-2)

	// Fibonacci numbers to hold in each loop
	long int F_m, F_m1, F_m2;
	long int sum_evens;

	// T - number of test cases
	// N - upper limit
	long int T, N;

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> N;

		// handle starting values

		// initialise variables
		F_m = 2;
		F_m2 = -1;
		F_m1 = 0;

		sum_evens = 0;

		while(F_m < N){
			sum_evens += F_m;
			F_m2 = F_m1;
			F_m1 = F_m;
			F_m = 4*F_m1 + F_m2;
		}

		cout << sum_evens << endl;

	}

}



