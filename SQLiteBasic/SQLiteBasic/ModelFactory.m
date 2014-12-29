//
//  ModelFactory.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/8/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "ModelFactory.h"

@implementation ModelFactory
+(AppModel*) getAppModel {
    AppModel* result = [[AppModel alloc] init];
    NSMutableArray* row1 = [NSMutableArray array];
    [row1 addObject:[NSString stringWithFormat:@"123"]];
    [row1 addObject:[NSString stringWithFormat:@"456"]];
    [row1 addObject:[NSString stringWithFormat:@"Row1"]];
    [result pushRowData:row1];
    NSMutableArray* row2 = [NSMutableArray array];
    [row2 addObject:[NSString stringWithFormat:@"789"]];
    [row2 addObject:[NSString stringWithFormat:@"101"]];
    [row2 addObject:[NSString stringWithFormat:@"row2"]];
    [result pushRowData:row2];
    NSMutableArray* row3 = [NSMutableArray array];
    [row3 addObject:[NSString stringWithFormat:@"abc"]];
    [row3 addObject:[NSString stringWithFormat:@"def"]];
    [row3 addObject:[NSString stringWithFormat:@"row3"]];
    [result pushRowData:row3];
    return result;
}
@end
