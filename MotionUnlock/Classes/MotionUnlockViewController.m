//
//  MotionUnlockViewController.m
//  MotionUnlock
//
//  Created by Brian Reber, Todd Lyon, Ashley Nelson on 2/24/10.
//  Copyright 2010. All rights reserved.
//

#import "MotionUnlockViewController.h"
#import "Compare.h"

@implementation MotionUnlockViewController

@synthesize accelerometer;

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
	
	//We don't want to collect data right off the bat
	collectData = NO;
	
	tempIndex = 0;
	
	finalData = NO;
	
	buttonPressCount = 0;
	
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
	
	if (collectData){
		
		if (!finalData) {
			xData[tempIndex] = acceleration.x;
			yData[tempIndex] = acceleration.y;
			zData[tempIndex] = acceleration.z;
			dataIndex = tempIndex;
		} else {
			xDataFinal[tempIndex] = acceleration.x;
			yDataFinal[tempIndex] = acceleration.y;
			zDataFinal[tempIndex] = acceleration.z;
			dataIndexFinal = tempIndex;
		}
		tempIndex++;
		
		//We don't want to overflow the NSArray
		if (tempIndex == ARRAY_CAPACITY) {
			if (finalData) {
				[self finalData:self];
			} else {
				[self originalData:self];
			}
		}
		
		//Set the value of the textfields
		[x setText: xVal];
		[y setText: yVal];
		[z setText: zVal];
		
		//Set the slider values
		[xSlide setValue:acceleration.x];
		[ySlide setValue:acceleration.y];
		[zSlide setValue:acceleration.z];
	}
}

- (void) buttonPressed:(id)sender {
	switch (buttonPressCount) {
		case 0:
			[self originalData:self];
			[status setText:@"Press the lock to complete your baseline movement."]; 
			buttonPressCount++;
			break;
		case 1:
			[self originalData:self];
			[status setText:@"Press the lock to attempt to unlock the device."]; 
			buttonPressCount++;
			break;
		case 2:
			[self finalData:self];
			[status setText:@"Press the lock to complete your attempt."]; 
			buttonPressCount++;
			break;
		case 3:
			[self finalData:self];
			[self compareData:self];
			[status setText:@"Press the lock to reset the data."]; 
			buttonPressCount++;
			break;
		case 4:
			buttonPressCount = 0;
			[status setText:@"Press the lock to record your baseline movement"]; 
			break;
		default:
			break;
	}
	
}

- (void) originalData:(id)sender {
	finalData = NO;
	[self startStop];
}

- (void) finalData:(id)sender {
	finalData = YES;
	[self startStop];
}

- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}

/*
 Called when the user presses the button.  We switch the button label, and set the collectData bool
 value to the opposite of what it was.
 */
- (void) startStop
{	
	if (collectData)
	{
		collectData = NO;
		[status setText:@"Stopped"];
		
		[originalButton setTitle:@"Original Data" forState:UIControlStateNormal];
		[finalButton setTitle:@"Final Data" forState:UIControlStateNormal];
		
		//Clear the output text fields
		[x setText: @""];
		[y setText: @""];
		[z setText: @""];
		
		[xSlide setValue:0.0];
		[ySlide setValue:0.0];
		[zSlide setValue:0.0];
		
		[running stopAnimating];
	} else {
		collectData = YES;
		
		tempIndex = 0;
		
		[status setText:@"Collecting Data"];
		if (finalData) {
			[finalButton setTitle:@"Stop" forState:UIControlStateNormal];
		} else {
			[originalButton setTitle:@"Stop" forState:UIControlStateNormal];
		}
		[running startAnimating];
	}
}

- (void) compareData:(id)sender {

	int temp = compareCaller(xData, yData, zData, xDataFinal, yDataFinal, zDataFinal);
	bool passed = (temp == 1);
	
	UIAlertView *alert = [[UIAlertView alloc]
						  initWithTitle:[[NSString alloc] initWithString:@"Did we pass!?!"] 
						  message:passed ? @"We passed!":@"We failed..."
						  delegate:self
						  cancelButtonTitle:@"OK"
						  otherButtonTitles:nil];
	
	[alert show];
	
}


- (void)dealloc {
    [super dealloc];
}

@end
