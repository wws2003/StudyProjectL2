//
//  Command.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/1/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "Command.h"

@implementation Command
-(id) init:(int)commandCode withString:(NSString *)commandStr {
    if(self = [super init]) {
        [self setM_commandCode:commandCode];
        [self setM_commandStr:commandStr];
    }
    return self;
}

@end
