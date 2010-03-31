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
void avg(double buffered[], double incomingData[MAX_SIZE]);

int main(){
	
	int time[MAX_SIZE];
	double inputx[MAX_SIZE];
	double inputy[MAX_SIZE];
	double inputz[MAX_SIZE];
	
	double bufferx[MAX_SIZE-MOVING_AVG];
	double buffery[MAX_SIZE-MOVING_AVG];
	double bufferz[MAX_SIZE-MOVING_AVG];
	
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
		
		avg(bufferx, inputx);
		avg(buffery, inputy);
		avg(bufferz, inputz);
		
		for (int i = 0; i < MAX_SIZE - MOVING_AVG; i++) {
			printf("%lf, %lf, %lf", bufferx[i], buffery[i], bufferz[i]);
		}
		
	}
	
	
	//Match Gesture
	
	//Store the comparison into array size of COMPARE_SIZE
	double avgdataset, avgcompare[COMPARE_SIZE], difference[COMPARE_SIZE];
	for (j=0; j<COMPARE_SIZE; j++) {
		avgcompare[j] = compare[0]-compare[j+1]/j+1;
	}
	
	//starting at the beginning of data set
	//for comparison set of COMPARE_SIZE
	for(i =0; i < MAX_SIZE; i++){
		for (j=0; j < COMPARE_SIZE; j++) {
	
		//find difference between slope intial and increment of comparison window
	
		//find difference between slope intial and increment of data
			avgdataset = (bufferx[i]-bufferx[i+j])/j+1;
			
			
		//find difference between two slopes and store in array of COMPARE_SIZE
			difference[j] = avgcompare[j]-avgdataset;
			
		}
	
	// average the differences and check if within the tolerance
	//if tolerance match return match, else move to next in the data set and try again
		int totalavg;
		for (j=0; j<COMPARE_SIZE; j++) {
			totalavg = total avgdifference[j];
		}
		totalavg =totalavg/COMPARE_SIZE;
		
	}
	
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


//Compute avg of first num items
void avg(double buffered[], double incomingData[MAX_SIZE]){
	float runningtotal = 0;
	
	for(int i = 0; i < MAX_SIZE - MOVING_AVG; i++){
		for(int j = 0; j < MOVING_AVG; j++){
			runningtotal = runningtotal + incomingData[i+j];
		}
		buffered[i] = runningtotal / MOVING_AVG;
	}
	
}
												  

