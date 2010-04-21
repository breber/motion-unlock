//
//  MotionUnlockViewController.h
//  MotionUnlock
//
//  Created by Brian Reber, Todd Lyon, Ashley Nelson on 2/24/10.
//  Copyright 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

#define ARRAY_CAPACITY 1000

@interface MotionUnlockViewController : UIViewController <UIAccelerometerDelegate>{

	UIAccelerometer *accelerometer;
	
	IBOutlet UIButton *toggle;
	IBOutlet UIActivityIndicatorView *running;
	
	IBOutlet UITextField *x;
	IBOutlet UITextField *y;
	IBOutlet UITextField *z;
	
	IBOutlet UISlider *xSlide;
	IBOutlet UISlider *ySlide;
	IBOutlet UISlider *zSlide;	
	
	IBOutlet UILabel *status;
	
	bool collectData;
	
	int index;
	NSMutableArray *data;
	
	double xData[ARRAY_CAPACITY];
	double yData[ARRAY_CAPACITY];
	double zData[ARRAY_CAPACITY];
	
	double xDataFinal[ARRAY_CAPACITY];
	double yDataFinal[ARRAY_CAPACITY];
	double zDataFinal[ARRAY_CAPACITY];
	
	bool startingData;
	
}

@property (nonatomic, retain) UIAccelerometer *accelerometer;

- (void) startStop:(id)sender;
- (void) emailData:(id)sender;
- (void) mailTo:(NSString *)to withBody:(NSString *)body;

- (void) startingData:(id)sender;
- (void) compareData:(id)sender;

@end

