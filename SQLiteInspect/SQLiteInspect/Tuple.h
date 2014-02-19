//
//  Tuple.h
//  SQLiteInspect
//
//  Created by wws2003 on 2/18/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Tuple : NSObject
{
    
}

-(id) init : (unsigned int) size;
-(NSString*) getValueAtIndex : (unsigned int) index;
-(NSString*) setValueAtIndex : (unsigned int) index : (NSString*) value;
-(Tuple*) join : (Tuple*)tuple;
@end
