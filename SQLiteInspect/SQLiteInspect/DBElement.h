//
//  DBElement.h
//  SQLiteInspect
//
//  Created by wws2003 on 2/18/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Tuple.h"
#import "Column.h"

@interface DBElement : NSObject
{
    
}

-(id)init : (Tuple*) tuple : (NSArray*) columns;
-(NSValue*) getValueByColumnName : (NSString*) columnName;
-(NSValue*) getValueByColumnIndex : (unsigned int) columnIndex;

@end
