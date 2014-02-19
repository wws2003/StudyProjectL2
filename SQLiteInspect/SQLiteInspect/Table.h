//
//  Table.h
//  SQLiteInspect
//
//  Created by wws2003 on 2/18/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Column.h"
#import "DBElement.h"
#import "JoinDecider.h"

@interface Table : NSObject
{
    
}

-(id) init : (NSString*) name : (NSArray*) columns;
-(unsigned int) getDBElementsCount;
-(NSArray*) getDBElement : (unsigned int)startIndex : (unsigned int)endIndex;
-(Table*) join : (Table*)table : (NSObject<JoinDecider>*) joinDecider;

@end
