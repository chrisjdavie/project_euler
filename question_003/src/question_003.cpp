/*
 * question_003.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: chris
 *
 *  Project Euler Question 3
 *
 *  https://www.hackerrank.com/contests/projecteuler/challenges/euler003
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of a given number N?
 *
 * ------------------------------
 * Got all the speedups but the sqrt, which is irritating.
 * ------------------------------
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

long int calc(long int);

int main() {

	// T - number of test cases
	// N - number to find the largest integer of
	long int T, N;

	cin >> T;

	while (T--) {
		cin >> N;
		cout << calc(N) << endl;
	}
}

long int calc(long int N){

	// i - test counter, test if it's a divisor
	long int i = 2;
	// N_loop - constant target N for the loop
	long int N_loop = i + 1;
	// N_new - if a divisor i is found, only have to explore to N/i
	long int N_new = N;


	while(i < sqrt(N_loop) + 1){
		N_loop = N_new;
		for (; i < sqrt(N_loop) + 1; ++i) {
			if (!(N_loop%i)){
				N_new = N_loop/i;
				break;
			}
		}
	}
	return N_loop;

}


