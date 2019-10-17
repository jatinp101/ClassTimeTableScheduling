/* randomly generating samples.
 * we assume all course take same hours.
 * and we can find some relationship between real hours and indexs of container
 */

#include <stdio.h>
#include <time.h>
#include <random>
#include <map>

using namespace std;

int first(map<int, map<int,int>> *classTable, vector<vector<int>> *schedule, vector<vector<int>> *schedule2, vector<int> *course_inf, int row_max, int col_max){
    int cost = 0;//The number of class clash
    int i = 0; //The number of current iteration
    //int num_courses = sizeof(course_inf);
    
    while(i<T){
        int num_courses = sizeof(course_inf);
        int crn_course = rand() % (num_courses - 1);// represent the crn of a course
        course_inf.erase(course_inf.begin() + crn_course);//remove the item I just pick up
        int index_teacher = course_inf[crn_course];// each crn_course have their own teacher numbers
        int row_tem = rand() % row_max;
        int col_tem = rand() % col_max;
        map<int,int> time_loc;
        
        time_loc[row_tem] = col_tem;
        classTable[crn_course] = time_loc;
        schedule[row_tem][col_tem]++; // at this time, the room gonna hold the course
        schedule2[row_tem][index_teacher]++; // at this time, the teacher gonna teach the course

        if(schedule[row_tem][col_tem]>1) cost++;
        if(schedule2[row_tem][index_teacher]>1) cost++;
        i++;
        num_courses--;
    }
}
