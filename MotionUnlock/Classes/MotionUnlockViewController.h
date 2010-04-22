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
	
	IBOutlet UIButton *originalButton;
	IBOutlet UIButton *finalButton;
	IBOutlet UIActivityIndicatorView *running;
	
	IBOutlet UITextField *x;
	IBOutlet UITextField *y;
	IBOutlet UITextField *z;
	
	IBOutlet UISlider *xSlide;
	IBOutlet UISlider *ySlide;
	IBOutlet UISlider *zSlide;	
	
	IBOutlet UILabel *status;
	
	bool collectData;
	
	int tempIndex;
	
	int dataIndex;
	int dataIndexFinal;
	NSMutableArray *data;
	
	double xData[ARRAY_CAPACITY];
	double yData[ARRAY_CAPACITY];
	double zData[ARRAY_CAPACITY];
	
	double xDataFinal[ARRAY_CAPACITY];
	double yDataFinal[ARRAY_CAPACITY];
	double zDataFinal[ARRAY_CAPACITY];
	
	bool finalData;
	
}

@property (nonatomic, retain) UIAccelerometer *accelerometer;

- (void) startStop;
- (void) emailData:(id)sender;
- (void) mailTo:(NSString *)to withBody:(NSString *)body;

- (void) originalData:(id)sender;
- (void) finalData:(id)sender;
- (void) compareData:(id)sender;

@end

