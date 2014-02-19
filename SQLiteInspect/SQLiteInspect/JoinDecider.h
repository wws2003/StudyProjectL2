//
//  JoinDecider.h
//  SQLiteInspect
//
//  Created by wws2003 on 2/18/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DBElement.h"

@protocol JoinDecider <NSObject>
-(BOOL)canJoin : (DBElement*) lhs : (DBElement*) rhs;
@end
