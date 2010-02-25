//
//  MotionUnlockAppDelegate.h
//  MotionUnlock
//
//  Created by Brian Reber on 2/24/10.
//  Copyright Iowa State University 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MotionUnlockViewController;

@interface MotionUnlockAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    MotionUnlockViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet MotionUnlockViewController *viewController;

@end

