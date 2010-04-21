/*
 *  ToddsCompare.c
 *  MotionUnlock
 *
 *  Created by Todd Lyon on 4/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ToddsCompare.h"

#define DATA_NUM 3000
#define LENGTH 10
#define SAMPLE_LENGTH 10
#define TOLERANCE 0.1
#define TRUE 1
#define ARRAY_TOLERANCE 10
#define START 10

int compareCaller(array data from iphone){
	
	
	
}

void findAverage(double preData[], double postData[]){
	
	
}

int compare(double preSlope[], double postSlope[], int start, int end) {
	
	int difference = 0;
	
	for(int i = start; i <= end; i++) {
		if(abs(postSlope[START] - preSlope[i]) <= TOLERANCE) {
			for(int j = i + 1; j < SAMPLE_LENGTH - 1 && difference <= TOLERANCE; j++) {
				difference = abs(postSlope[j] - preSlope[j]);
			}
		}
	}
	
	if(j == SAMPLE_LENGTH - 1) return 1;
}