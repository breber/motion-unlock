//
//  MotionUnlockViewController.m
//  MotionUnlock
//
//  Created by Brian Reber, Todd Lyon, Ashley Nelson on 2/24/10.
//  Copyright 2010. All rights reserved.
//

#import "MotionUnlockViewController.h"

@implementation MotionUnlockViewController

@synthesize accelerometer;


/*
 // Implement loadView to create a view hierarchy programmatically, without using a nib.
 - (void)loadView {
 }
 */


// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
	
	output.text = @"Temporary to test output in form of \"x,y,z\"";
	
	collectData = NO;
	
	//Set up the accelerometer
	self.accelerometer = [UIAccelerometer sharedAccelerometer];
	self.accelerometer.updateInterval = .1;
	self.accelerometer.delegate = self;
	
}


/**
 Overridden to allow us to read the accelerometer data.
 This method gets automatically called when the accelerometer updates.  It will print out 
 the acceleration data into our text fields right now.
 */
-(void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration
{
	NSString *xVal = [NSString stringWithFormat:@"%f", acceleration.x];
	NSString *yVal = [NSString stringWithFormat:@"%f", acceleration.y];
	NSString *zVal = [NSString stringWithFormat:@"%f", acceleration.z];
	
	[xVal retain];
	[yVal retain];
	[zVal retain];
	
	[x setText: xVal];
	[y setText: yVal];
	[z setText: zVal];
	
	//This doesn't really do anything right now for some reason...
	if (collectData)
	{
		output.text = [[NSString alloc] stringByAppendingFormat:@"%@\n%@, %@, %@", [output text], xVal, yVal, zVal];
	}
}

- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}


//TODO: The start button doesn't do anything right now. I tried a couple things, but the app froze, so I commented it out.
- (void) startStop:(id)sender
{
	//	if (collectData)
	//		accelerometer.delegate = nil;
	//	else accelerometer.delegate = self;
	
	if (collectData)
		collectData = NO;
	else collectData = YES;
}


- (void)dealloc {
    [super dealloc];
}

@end
