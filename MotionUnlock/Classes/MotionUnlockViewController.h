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
	
	IBOutlet UITextView *output;
	
	bool collectData;
	
}

@property (nonatomic, retain) UIAccelerometer *accelerometer;

- (void) startStop:(id)sender;


@end

