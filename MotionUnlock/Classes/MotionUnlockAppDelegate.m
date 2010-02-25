//
//  MotionUnlockAppDelegate.m
//  MotionUnlock
//
//  Created by Brian Reber on 2/24/10.
//  Copyright Iowa State University 2010. All rights reserved.
//

#import "MotionUnlockAppDelegate.h"
#import "MotionUnlockViewController.h"

@implementation MotionUnlockAppDelegate

@synthesize window;
@synthesize viewController;


- (void)applicationDidFinishLaunching:(UIApplication *)application {    
    
    // Override point for customization after app launch    
    [window addSubview:viewController.view];
    [window makeKeyAndVisible];
}


- (void)dealloc {
    [viewController release];
    [window release];
    [super dealloc];
}


@end
