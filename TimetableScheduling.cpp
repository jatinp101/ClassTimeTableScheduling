/* before we run the program, we need to know these information:
 * 1. total courses which need to be schedule: total_course
 * 2. when is the last avaliable time for taking a course: total_time
 * 3. how many classrooms we have: total_classroom
 * 4. how many teachers we have: total_teacher
 */
#include <iostream>
#include "first.cpp"
#include "second.cpp"
#include "third.cpp"

using namespace std;

int main() {
	// set up these premise variable
    int total_course = 10;
    int total_time = 10; // as the row_max
    int total_classroom = 10;// as the col_max
    int total_teacher = 10;
    
    //total cost that is class clash
    int cost = 0;
    //the key is crn, store another map that hold time & location
    map<int, map<int, int> > classTable;
    //schedule1 records the time and location for counting class clash
    vector<vector<int> > schedule;
    //schedule2 records the time and teacher for counting class clash
    vector<vector<int> > schedule2;
    //to record the courses and teachers
    vector<int> course_teacher;
    
    
	return 0;
}
