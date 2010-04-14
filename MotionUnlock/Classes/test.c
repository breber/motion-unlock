/*
 *  test.c
 *  MotionUnlock
 *
 *  Created by Brian Reber on 4/14/10.
 *  Copyright 2010 Iowa State University. All rights reserved.
 *
 */

#include "stdio.h"

/* A test function to prove that we can call into C code from our iPhone Objective-C Code */
int testFunction(int number)
{
	return number * 2;
}
