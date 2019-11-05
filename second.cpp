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
//void MonteCarlo (map*, vector*, vector*, int*);
// Why did we switch the MonteCarlo method from void to int?
int MonteCarlo (map<int, map<int, int> >& classTable, vector<vector<int> >& schedule, vector<vector<int> >& schedule2, vector<int> crnTeacher, int cost) {
	int unincrease, iteration, max_iteration, dif_cost;
	srand((unsigned int)time(NULL));
	iteration = 0;
	max_iteration = 100;
	unincrease = 0;
	dif_cost = 0; // move if > 0
        int max_unincrease = 100;


	while (iteration < max_iteration) {
		int crn_course = (rand() % 10) + 1;
        	//get the index number of teacher from the container
		int index_teacher = crnTeacher[crn_course]; 
        
        	int loc_tem, time_tem, row_tem, col_tem;
		// still not too sure how to get those values either
        
        //get the loc_tem and time_tem from the map, it is inside of ClassTable
        map<int,int> temp = classTable[crn_course];
         time_tem = temp.begin()->first;
         loc_tem = temp.begin()->second;
        //the bounds of two variable depend on our total courses and classroom
		row_tem = (rand() % 10) + 1; //time
		col_tem = (rand() % 10) + 1; //location
		
		if (schedule[time_tem][col_tem] >  1) { // clash
			if (schedule [row_tem][col_tem] == 0)
				dif_cost++;
		} else { //no clash
			if (schedule[row_tem][col_tem] > 0)
				dif_cost--;
		}

		if (schedule2[time_tem][index_teacher] > 1) { // there is a clash in time&teach
			if (schedule2[row_tem][index_teacher] == 0)
				dif_cost++;	
		} else {
			if (schedule2[row_tem][index_teacher] > 0) 
				dif_cost--;
		}

		if (dif_cost > 0) {
			schedule[time_tem][loc_tem]--;
			schedule[row_tem][col_tem]++;
			schedule2[time_tem][index_teacher]--;
			schedule2[row_tem][index_teacher]++;
			cost = cost - dif_cost;
			//(row_tem,col_tem) -> classTable[crn_course];
            map<int, int> temp;
            temp[row_tem] = col_tem;
            classTable.erase(crn_course);
            classTable[crn_course] = temp;
			unincrease = 0;
		} else {
			unincrease++;
		}
		if (unincrease == max_unincrease) break;
		if (cost == 0) break;
		iteration++;
	}
	return cost;
}
