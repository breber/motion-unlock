#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_NUM 3000
#define LENGTH 10
#define SAMPLE_LENGTH 10
#define POST_SAMPLE_LENGTH 30
#define TOLERANCE 0.1
#define TRUE 1
#define ARRAY_TOLERANCE 10
#define START 10

int main() {
	int pre_t[DATA_NUM], post_t[DATA_NUM];
	double pre_x[DATA_NUM], pre_y[DATA_NUM], pre_z[DATA_NUM], post_x[DATA_NUM], post_y[DATA_NUM], post_z[DATA_NUM], temp[DATA_NUM];
	FILE *inp;
	char *status;
	double pre_xSlope[SAMPLE_LENGTH - 1], pre_ySlope[SAMPLE_LENGTH - 1], pre_zSlope[SAMPLE_LENGTH - 1], post_xSlope[SAMPLE_LENGTH - 1], post_ySlope[SAMPLE_LENGTH - 1], post_zSlope[SAMPLE_LENGTH - 1];
	double difference = 0;
	
	int pass_x = 0;
	int pass_y = 0;
	int pass_z = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int n = 0;
	inp = fopen("pre_t.txt", "r");
	
	// Fills arrays with stored movement and random movement components
	for (i = 0; !feof(inp) && i < DATA_NUM; i++) {
		fscanf(inp, "%d", &pre_t[i]);
	}
	
	i = 0;
	inp = fopen("pre_x.txt", "r");

	for (i = 0; !feof(inp) && i < DATA_NUM; i++) {
		fscanf(inp, "%lf", &pre_x[i]);
	}
 
	i = 0;
	inp = fopen("pre_y.txt", "r");

	for (i = 0; !feof(inp) && i < DATA_NUM; i++) {
		fscanf(inp, "%lf", &pre_y[i]);
	}
	
	i = 0;
	inp = fopen("pre_z.txt", "r");
	
	for (i = 0; !feof(inp) && i < DATA_NUM; i++) {
		fscanf(inp, "%lf", &pre_z[i]);
	}
	
	i = 0;
	inp = fopen("post_t.txt", "r");
	
	for (i = 0; !feof(inp) && i < DATA_NUM; i++) {
		fscanf(inp, "%d", &post_t[i]);
	}
	
	i = 0;
	inp = fopen("post_x.txt", "r");
	
	for (i = 0; !feof(inp) && i < DATA_NUM; i++) {
		fscanf(inp, "%lf", &post_x[i]);
	}

	i = 0;
	inp = fopen("post_y.txt", "r");
	
	for (i = 0; !feof(inp) && i < DATA_NUM; i++) {
		fscanf(inp, "%lf", &post_y[i]);
	}

	i = 0;
	inp = fopen("post_z.txt", "r");
	
	for (i = 0; !feof(inp) && i < DATA_NUM; i++) {
		fscanf(inp, "%lf", &post_z[i]);
	} 
	
	/*
	
	// Fills arrays of slopes from stored movement sample
	
	for(i = 0; i < SAMPLE_LENGTH - 1; i++) {
		pre_xSlope[i] = pre_x[i + 1] - pre_x[i];
	}
	
	for(i = 0; i < SAMPLE_LENGTH - 1; i++) {
		pre_ySlope[i] = pre_y[i + 1] - pre_y[i];
	}
	
	for(i = 0; i < SAMPLE_LENGTH - 1; i++) {
		pre_zSlope[i] = pre_z[i + 1] - pre_z[i];
	}
	
	for(i = 0; i < SAMPLE_LENGTH - 1; i++) {
		post_xSlope[i] = post_x[i + 1] - post_x[i];
	}
	
	for(i = 0; i < SAMPLE_LENGTH - 1; i++) {
		post_ySlope[i] = post_y[i + 1] - post_y[i];
	}
	
	for(i = 0; i < SAMPLE_LENGTH - 1; i++) {
		post_zSlope[i] = post_z[i + 1] - post_z[i];
	}
	
	// Compare slopes to see if they are within range
	
	for(i = 0; i < SAMPLE_LENGTH - 1; i++) {
		if(abs(post_xSlope[START] - pre_xSlope[i]) <= TOLERANCE) {
			for(j = i + 1; j < SAMPLE_LENGTH - 1 && difference <= TOLERANCE; j++) {
				difference = abs(post_xSlope[j] - pre_xSlope[j]);
			}
		}
	}
	
	if(j == SAMPLE_LENGTH - 1) {
		pass_x = TRUE;
		printf("X: %d\n", pass_x);
		for(k = i - ARRAY_TOLERANCE; k <= i + ARRAY_TOLERANCE; k++) {
			if(abs(post_ySlope[START] - pre_ySlope[k]) <= TOLERANCE) {
				for(l = k + 1; l < SAMPLE_LENGTH - 1 && difference <= TOLERANCE; l++) {
					difference = abs(post_xSlope[l] - pre_xSlope[l]);
				}
			}			
		}
		
		if(l == j) {
			pass_y = TRUE;
			printf("Y: %d\n", pass_y);
			for(m = i - ARRAY_TOLERANCE; m <= i + ARRAY_TOLERANCE; m++) {
				if(abs(post_ySlope[START] - pre_ySlope[m]) <= TOLERANCE) {
					for(n = m + 1; n < SAMPLE_LENGTH - 1 && difference <= TOLERANCE; n++) {
						difference = abs(post_xSlope[n] - pre_xSlope[n]);
					}
				}			
			}
		}
		
		if(n == j) {
			pass_z = TRUE;
			printf("Z: %d\n", pass_z);
		}
	} 
	 
	 */
	
	
	
	//Todd's Section
	
	//Find slopes in selection window
	calculateSlopes(pre_xSlope, post_xSlope, START, START + SAMPLE_LENGTH);
	calculateSlopes(pre_ySlope, post_ySlope, START, START + SAMPLE_LENGTH);
	calculateSlopes(pre_zSlope, post_zSlope, START, START + SAMPLE_LENGTH);
	
	//Find slopes for data to compare
	calculateSlopes(<#int [] preValues#>, <#int [] postValues#>, <#int start#>, <#int end#>);
	calculateSlopes(<#int [] preValues#>, <#int [] postValues#>, <#int start#>, <#int end#>);
	calculateSlopes(<#int [] preValues#>, <#int [] postValues#>, <#int start#>, <#int end#>);
	
	//Compare Slopes
	
	
	return 0;
}

void calculateSlopes(int preValues[], int postValues[], int start, int end){
	int i;
	int j = 0;
	for (i = start; i < end; i++) {
		//add here
		
		postValues[j] = preValues[i];
	}
}

int compareSlopes(int data[], int compareSet[]){
	
}



