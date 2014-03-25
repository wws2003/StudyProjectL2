//
//  ControllerFactory.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/18/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppController.h"

@interface ControllerFactory : NSObject
+(NSObject<AppController>*) getAppController;
@end
