/* randomly generating samples.
 * we assume all course take same hours.
 * and we can find some relationship between real hours and indexs of container
 */

#include <stdio.h>
#include <time.h>
#include <iterator>
#include <random>
#include <map>
#include <vector>
#define T 10000 //depends on how many course we have
using namespace std;

// the parameter should be pass value by address
int first(map<int, map<int,int> >& classTable, vector<vector<int> >& schedule, vector<vector<int> >& schedule2, vector<int> course_inf[], int row_max, int col_max){
    int cost = 0;//The number of class clash
    int i = 0; //The number of current iteration
    
    
    while(i<T){
        int crn_course = i;
        int index_teacher = course_inf[crn_course];// each crn_course have their own teacher numbers
        
        int row_tem = rand() % row_max;//time
        int col_tem = rand() % col_max;//location
        map<int,int> time_loc;
        
        time_loc.insert(pair<int, int>(row_tem, col_tem));
        classTable[crn_course] = time_loc;
        schedule[row_tem][col_tem] ++; // at this time, the room gonna hold the course
        schedule2[row_tem][index_teacher] ++; // at this time, the teacher gonna teach the course
        
       if(schedule[row_tem][col_tem]>1) cost++;
        if(schedule2[row_tem][index_teacher]>1) cost++;
        i++;
    }
    return cost;
}
