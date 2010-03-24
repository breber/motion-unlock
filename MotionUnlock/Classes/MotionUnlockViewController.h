//
//  MotionUnlockViewController.h
//  MotionUnlock
//
//  Created by Brian Reber, Todd Lyon, Ashley Nelson on 2/24/10.
//  Copyright 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MotionUnlockViewController : UIViewController <UIAccelerometerDelegate>{

	UIAccelerometer *accelerometer;
	
	IBOutlet UIButton *toggle;
	
	IBOutlet UITextField *x;
	IBOutlet UITextField *y;
	IBOutlet UITextField *z;
	
	IBOutlet UILabel *status;
	
	bool collectData;
	
	int index;
	NSMutableArray *data;
	
}

@property (nonatomic, retain) UIAccelerometer *accelerometer;

- (void) startStop:(id)sender;
-(void) emailData:(id)sender;
- (void)mailTo:(NSString *)to withBody:(NSString *)body;

@end

