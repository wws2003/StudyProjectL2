//
//  ModelFactory.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/8/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppModel.h"
@interface ModelFactory : NSObject
+(AppModel*) getAppModel;
@end
