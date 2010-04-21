//
//  MotionUnlockViewController.m
//  MotionUnlock
//
//  Created by Brian Reber, Todd Lyon, Ashley Nelson on 2/24/10.
//  Copyright 2010. All rights reserved.
//

#import "MotionUnlockViewController.h"
#import "ComparisonAsh.h"

@implementation MotionUnlockViewController

@synthesize accelerometer;

//The default size of our NSArray
//#define ARRAY_CAPACITY 1000

/*
 // Implement loadView to create a view hierarchy programmatically, without using a nib.
 - (void)loadView {
 }
 */


// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
	
	//We don't want to collect data right off the bat
	collectData = NO;
	
	tempIndex = 0;
	data = [[NSMutableArray alloc] initWithCapacity: ARRAY_CAPACITY];
	
	startingData = YES;
	
	//Set up the accelerometer
	self.accelerometer = [UIAccelerometer sharedAccelerometer];
	self.accelerometer.updateInterval = .1;
	self.accelerometer.delegate = self;
	
	UIAlertView *alert = [[UIAlertView alloc]
						  initWithTitle:[[NSString alloc] initWithString:@"Test!"] 
						  message:@"Test1"
						  delegate:self
						  cancelButtonTitle:@"OK"
						  otherButtonTitles:nil];
	
	[alert show];
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
		[xVal retain];
		[yVal retain];
		[zVal retain];
		
		if (startingData) {
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

		//Insert a string of our acceleration data into our NSArray
		[data insertObject:[NSString stringWithFormat:@"%@,%@,%@", xVal, yVal,zVal] atIndex:tempIndex];
		tempIndex++;
		
		//We don't want to overflow the NSArray
		if (tempIndex == ARRAY_CAPACITY)
			[self startStop:self];
		
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

- (void) startingData:(id)sender {
	startingData = !startingData;
	[self startStop:self];
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

/*
 Called when the user presses the button.  We switch the button label, and set the collectData bool
 value to the opposite of what it was.
 */
- (void) startStop:(id)sender
{	
	if (collectData)
	{
		collectData = NO;
		[status setText:@"Stopped"];
		[toggle setTitle:@"Collect Data" forState:UIControlStateNormal];
		
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
		
		//Reset the array
		//We may change this when we start comparing data
		data = nil;
		data = [[NSMutableArray alloc] initWithCapacity:ARRAY_CAPACITY];
		tempIndex = 0;
		
		[status setText:@"Collecting Data"];
		[toggle setTitle:@"Stop" forState:UIControlStateNormal];
		[running startAnimating];
	}
}

- (void) compareData:(id)sender {

	bool passed = NO;
	
	if (compare(dataIndex, xData, yData, zData, dataIndexFinal, xDataFinal, yDataFinal, zDataFinal) == 1)
		passed = YES;
	
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

/*
 Called when you click on the "email" button
 */
-(void) emailData:(id)sender
{
	NSArray *arr = [[NSArray alloc] initWithArray:data];
	if ([arr count] != 0)
		[self mailTo:@"reber.brian@gmail.com" withBody:[arr componentsJoinedByString:@"\n"]];
}

/*
 Formulates an email with the given address and body
 */
- (void)mailTo:(NSString *)to withBody:(NSString *)body
{
	NSString *message = [NSString stringWithFormat:@"mailto:?to=%@&subject=MotionUnlockOutputData&body=%@",
						 [to stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
						 [body stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding]];
	
	[[UIApplication sharedApplication] openURL:[NSURL URLWithString: message]];
}

@end
