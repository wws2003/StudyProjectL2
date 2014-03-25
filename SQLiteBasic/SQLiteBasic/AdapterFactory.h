//
//  AdapterFactory.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/8/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppAdapter.h"
#import "Common.h"

@interface AdapterFactory : NSObject
+(NSObject<AppAdapter>*) getAppAdapter:(NSUInteger)adapterType;
@end
