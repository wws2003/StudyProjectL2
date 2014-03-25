//
//  ControllerFactory.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/18/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "ControllerFactory.h"
#import "AppControllerImpl.h"

@implementation ControllerFactory
+(NSObject<AppController>*) getAppController {
    NSObject<AppController>* result;
    result = [[AppControllerImpl alloc]init];
    return result;
}
@end
