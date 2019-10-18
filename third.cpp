/* annealing simulated algorithm
 */

#include <stdio.h>
#include <time.h>
#include <random>

using namespace std;
//void annealingSimulated ()
void third(map<int, map<int,int>> *classTable, vector<vector<int>> *schedule, vector<vector<int>> *schedule2, vector<int> crnTeacher, int tCost){
    int T = 100;//the temperature of system, the initial T should be a high temperature
    int T_min = 50;//the temperature of system, the initial T should be a high temperature
    int r = 0.77;//a factor to control the speed of cool down
    int increase_max = 100;//need to test
    int increase = 0;
    int dCost = 0;
    int max_swap = 100;//need to test
    int cur_swap = 0;
    
    while(T > T_min){
        while(cur_swap < max_swap){
            
            int crn_course = rand() % 100;// assume we have 100 courses in campus
            map<int,int> temp = classTable[crn_course];
            int loc_tem = temp->first;
            int time_tem = temp->second;
            int row_tem = rand() % 100;
            int col_tem = rand() % 100;
            
            if(schedule[time_tem][loc_tem]>1){//there is class clash on time&room
                   if(schedule[row_tem][col_tem]==0){
                dCost++;
                }
             }else{// there no class clash on time&room
                  if(schedule[row_tem][col_tem] > 0){
                dCost--;
                }
             }

              if(schedule2[time_tem][index_teacher]>1){// there is a clash about time&tec
                if(schedule2[row_tem][index_teacher]==0){
                    dCost++;
                }
             }else{//there no class clash about time&tec
                  if(schedule2[row_tem][index_teacher] > 0){
                dCost--;
                }
            }
            if(dCost>=0){//after move it, we get a better solution, so we always accept the move
                //accept the move from C(i) to C(i+1)
                schedule[time_tem][loc_tem]--;
                schedule[row_tem][col_tem]++;
                schedule2[time_tem][teacher]--;
                schedule2[row_tem][index_teacher]++;
                tCost = tCost - dCost;
                (row_tem,col_tem) -> classTable[crn_course];
                increase++;
            }
            else
            {
            //if we don't get a better solution or even make it worse, we accept the move by some probability. The probability should decrease as time goes on.
                
            // the range of the function exp(dE/T) is (0,1), if dE/T goes up, the exp(dE/T) also increase.
                if ( exp( -dCost/T ) > random( 0 , 1 ) ){
                    schedule[time_tem][loc_tem]--;
                    schedule[row_tem][col_tem]++;
                    schedule2[time_tem][teacher]--;
                    schedule2[row_tem][index_teacher]++;
                    tCost = tCost - dCost;
                    (row_tem,col_tem) -> classTable[crn_course];
                    increase++;
                }
            }
            if(increase == increase_max){
                increase = 0;
                cur_swap = 0;
                break;
            }
            i++;
            cur_swap++;
        }//ends while
        
        T = r * T ; //decrease the temperature,0<r<1.
        　　/*
        　　* if r is too big, we will have a high probability to get the optimization of whole picture, but it gonna take a long time. If r is too small, the process of searching will be really fast, but we might just get a partial optimization
        　　*/
    }//ends while
}
