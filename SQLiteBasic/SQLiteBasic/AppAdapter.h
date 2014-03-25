//
//  AppAdapter.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppModel.h"

@protocol AppAdapter <NSObject>
-(void)registModelForView:(AppModel*)model forView:(NSView*)view;
-(void)initViewFromModel;
-(void)notifyView;
@property (assign) AppModel* m_model;
@property (assign) NSView* m_view;
@end
