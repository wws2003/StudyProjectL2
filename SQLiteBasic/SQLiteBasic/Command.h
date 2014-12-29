//
//  Command.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/1/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Command : NSObject
-(id) init:(int)commandCode withString:(NSString*)commandStr;
@property (assign) NSUInteger m_commandCode;
@property (retain) NSString* m_commandStr;
@end
