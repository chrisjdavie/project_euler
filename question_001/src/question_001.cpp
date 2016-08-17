//============================================================================
// Name        : project_euler.cpp
// Author      : Chris Davie
// Version     :
// Copyright   : Your copyright notice
// Description : Project Euler number 1.
// https://www.hackerrank.com/contests/projecteuler/challenges/euler001
// "If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// "Find the sum of all the multiples of 3 or 5 below N."
//============================================================================

#include <iostream>
using namespace std;

long int sum_multis(long int, long int);

int main() {

	// variables to hold the sum of the multiple to N
	long int sum_3, sum_5, sum_15;

	// T - number of test cases
	// Upper limit
	long int T, N;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;

		// sum of multiples of 3 and 5 to N
		sum_3  = sum_multis(3,  N);
		sum_5  = sum_multis(5,  N);

		// remove duplicates at 15, as 3*5 = 15
		sum_15 = sum_multis(15, N);

		cout << sum_3 + sum_5 - sum_15 << endl;
	}
}


long int sum_multis(long int multiple, long int limit) {
	long int num_mults;
	num_mults = (limit-1)/multiple;

	return multiple*num_mults*(num_mults + 1)/2;

}
