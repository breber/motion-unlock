//
//  MotionUnlockViewController.h
//  MotionUnlock
//
//  Created by Brian Reber, Todd Lyon, Ashley Nelson on 2/24/10.
//  Copyright 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MotionUnlockViewController : UIViewController <UIAccelerometerDelegate> {

	UIAccelerometer *accelerometer;
	
}

@property (nonatomic, retain) UIAccelerometer *accelerometer;


@end

