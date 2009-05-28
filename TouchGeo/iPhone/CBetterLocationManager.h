//
//  CBetterLocationManager.h
//  TouchCode
//
//  Created by Jonathan Wight on 05/06/08.
//  Copyright 2008 toxicsoftware.com. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>

#import <CoreLocation/CoreLocation.h>

#define CBetterLocationManagerDidUpdateToLocationNotification @"CBetterLocationManagerDidUpdateToLocationNotification"
#define CBetterLocationManagerDidStartUpdatingLocationNotification @"CBetterLocationManagerDidStartUpdatingLocationNotification"
#define CBetterLocationManagerDidStopUpdatingLocationNotification @"CBetterLocationManagerDidStopUpdatingLocationNotification"

@interface CBetterLocationManager : NSObject <CLLocationManagerDelegate> {
	CLLocationManager *locationManager;
	CLLocation *location;
	BOOL updating;
	NSDate *startedUpdatingAtTime;
	CLLocationDistance stopUpdatingAccuracy;
	NSTimeInterval stopUpdatingAfterInterval;
	NSTimer *timer;
}

@property (readwrite, nonatomic, retain) CLLocationManager *locationManager;
@property(readwrite, nonatomic, assign) CLLocationDistance distanceFilter;
@property(readwrite, nonatomic, assign) CLLocationAccuracy desiredAccuracy;
@property(readonly, nonatomic, retain) CLLocation *location;
@property(readonly, nonatomic, assign) BOOL updating;
@property(readonly, nonatomic, retain) NSDate *startedUpdatingAtTime;
@property(readwrite, nonatomic, assign) CLLocationDistance stopUpdatingAccuracy;
@property(readwrite, nonatomic, assign) NSTimeInterval stopUpdatingAfterInterval;

+ (CBetterLocationManager *)instance;

- (void)startUpdatingLocation;
- (void)stopUpdatingLocation;

@end
