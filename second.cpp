/**
 * Monte Carlo Part of the Algorithm
 * @authors Jatin Pandya, Tianhui Zhou
 * @since 10/17/2019
 */

#include <iostream>
#include <random>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
void MonteCarlo (map*, vector*, vector*, int*);

void MonteCarlo (map ClassTable, vector Schedule, vector Schedule1, int cost) {
	int unincrease, iteration, max_iteration, dif_cost;
	void srand(int seed);
	iteration = 0;
	max_iteration = 100;
	unincrease = 0;
	dif_cost = 0; // move if > 0


	while (iteration < max_iteration) {
		int crn_course = (rand() % 10) + 1;
		int index_teacher; // not too sure how to get it :/
		int loc_tem, time_tem, row_tem, col_tem;
		// loc_tem, time_tem not too sure how to get those values either
		row_tem = (rand() % 10) + 1; // Not sure if these are the same bounds
		col_tem = (rand() % 10) + 1; // ""
		
		if (schedule[time_tem] [col_tem] >  1) { // clash 
			if (schedule [row_tem][col_tem] == 0)
				dif_cost++;
		} else { //no clash
			if (schedule[row_tem][col_tem] > 0)
				dif_cost--;
		}

		if (schedule2[time_tem][index_teacher] > 1) { // there is a clash in time&teach
			
		}
	}
}
