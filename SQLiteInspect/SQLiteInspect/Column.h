//
//  Column.h
//  SQLiteInspect
//
//  Created by wws2003 on 2/17/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Column : NSObject
{
    
}

//Public methods
- (id)init: (NSString*) columnName : (NSString*) columnDataType;
- (NSString*) getColumnName;
- (NSString*) getColumnDataType;
@end

