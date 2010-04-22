/*
 *  ToddsCompare.c
 *  MotionUnlock
 *
 *  Created by Todd Lyon on 4/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ToddsCompare.h"
#include "math.h"
#include "stdio.h"

#define DATA_NUM 3000
//length is the length of the incoming data, passed in
#define LENGTH 100
#define SAMPLE_LENGTH 10
#define TOLERANCE 0.1
#define TRUE 1
#define ARRAY_TOLERANCE 10
#define START 10

int compareCaller(double x_data[], double y_data[], double z_data[], double x_compare[], double y_compare[], double z_compare[]){
	int i =0;
	
	double data_x_slopes[DATA_NUM];
	double data_y_slopes[DATA_NUM];
	double data_z_slopes[DATA_NUM];
	
	double compare_x_slopes[SAMPLE_LENGTH];
	double compare_y_slopes[SAMPLE_LENGTH];
	double compare_z_slopes[SAMPLE_LENGTH];
	
	
	
	//Find slopes in selection window
	calculateSlopes(x_compare, compare_x_slopes, START, START + SAMPLE_LENGTH);
	calculateSlopes(y_compare, compare_y_slopes, START, START + SAMPLE_LENGTH);
	calculateSlopes(z_compare, compare_z_slopes, START, START + SAMPLE_LENGTH);
	
	//Find slopes for data to compare
	calculateSlopes(x_data, data_x_slopes, 0, LENGTH);
	calculateSlopes(y_data, data_y_slopes, 0, LENGTH);
	calculateSlopes(z_data, data_z_slopes, 0, LENGTH);
	
	int x_pass = 0, y_pass = 0, z_pass =0;
	
	//Compare Slopes
	for (i = 0; i < LENGTH - SAMPLE_LENGTH; i++) {
		x_pass = compare(compare_x_slopes, data_x_slopes, i, i + SAMPLE_LENGTH);
		y_pass = compare(compare_y_slopes, data_y_slopes, i, i + SAMPLE_LENGTH);
		z_pass = compare(compare_z_slopes, data_z_slopes, i, i + SAMPLE_LENGTH);
		printf("Pass? %d, %d, %d \n", x_pass, y_pass, z_pass);
		if (x_pass && y_pass && z_pass) {
			return 1;
		}
	}
	
	return 0;
	
}

void calculateSlopes(double preValues[], double postValues[], int start, int end){
	int i;
	int j = 0;
	for (i = start; i < end; i++) {
		
		double slope = (preValues[i+1]-preValues[i]);
		
		postValues[j] = slope;
	}
}

int compare(double preSlope[], double postSlope[], int start, int end) {
	
	int difference = 0;
	
	int i , j; 
	
	for(i = start; i <= end; i++) {
		if(abs(postSlope[START] - preSlope[i]) <= TOLERANCE) {
			for(j = i + 1; j < SAMPLE_LENGTH - 1 && difference <= TOLERANCE; j++) {
				difference = abs(postSlope[j] - preSlope[j]);
			}
		}
	}
	
	if(j == SAMPLE_LENGTH - 1) return 1;
	else return 0;
}