//
//  AppController.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/1/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Command.h"
#import "AppAdapter.h"
#import "AppModel.h"

@protocol AppController <NSObject>
-(void)initModelAndView:(AppModel*)model withView:(NSView*)view;
-(void)initModelAndViewByAdapter:(NSObject<AppAdapter>*)adapter;
-(void)receiveCommand:(Command*)command;

@end
