/*
 *  GestureMatch.c
 *  
 *
 *  Created by Todd Lyon on 3/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

//Constants
#define TRUE 1
	//Tolerance in Accelerometer values
#define ACCEL_TOLERANCE 1
	//Number of values to take into the moving average
#define MOVING_AVG 5
	//Time in milliseconds that the time the entire movement can vary by
#define TIME_TOLERANCE 1000
	//Max Size of arrarys
#define MAX_SIZE 10000

//Prototypes
void gatherdata(int time[MAX_SIZE], double inputx[MAX_SIZE], double inputy[MAX_SIZE], double inputz[MAX_SIZE]);

int main(){
	
	int time[MAX_SIZE];
	double inputx[MAX_SIZE];
	double inputy[MAX_SIZE];
	double inputz[MAX_SIZE];
	
	int t, abutton, bbutton, home, minus, plus, one, two, up, down, left, right;
	double ax, ay, az;
	
	
	//Train Gesture
	while (TRUE) {
		do{
			scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &abutton, 
					&bbutton, &plus, &home, &minus, &one, &two, &up, &down, &left, &right);
		
		} while(!bbutton);
			
		gatherdata(time, inputx, inputy, inputz);
			
		//output arrays to file
		
		
		
	}
	
	
	//Match Gesture
	
	
	
}

//Get input from the WiiMote and place into the array
void gatherdata(int time[MAX_SIZE], double inputx[MAX_SIZE], double inputy[MAX_SIZE], double inputz[MAX_SIZE]){
	int t, abutton, bbutton, home, minus, plus, one, two, up, down, left, right;
	double ax, ay, az;
	
	for (int i=0; i<MAX_SIZE; i++) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &abutton, 
			  &bbutton, &plus, &home, &minus, &one, &two, &up, &down, &left, &right);
	
			time[i] = t;
			inputx[i] = ax;
			inputy[i] = ay;
			inputz[i] = az;
		
			printf("%d, %lf, %lf, %lf", t, ax, ay, az);
		
			if (bbutton) {
				return;
			}
	
	}

}

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
double updatebuffer(double buffer[], int length, double new_item){
	int i;
	for (i=1; i<length; i++) {
		buffer[i-1] = buffer[i];
	}
	buffer[length-1] = new_item;
	return 1;
}

//Compute avg of first num items
double avg(double buffer[], int num_items){
	float runningtotal = 0;
	int i;
	
	for(i=0; i<num_items; i++){
		runningtotal = runningtotal + buffer[i];
		
	}
	
	return(runningtotal / num_items);
}


