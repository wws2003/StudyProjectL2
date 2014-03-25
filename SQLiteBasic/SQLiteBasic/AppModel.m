//
//  AppModel.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "AppModel.h"

@implementation AppModel
-(id)init {
    if (self = [super init]) {
        [self setM_data:[NSMutableArray array]];
    }
    return self;
}

-(NSInteger)getNumberOfRows {
    return [self.m_data count];
}

-(NSInteger)getNumberOfColumns {
    return [[self.m_data objectAtIndex:0] count];
}

-(void)pushRowData:(NSArray*)rowData {
    [[self m_data] addObject:rowData];
}

-(void)pushRowData:(NSArray*)rowData toIndex:(NSInteger)rowIndex {
    [self.m_data insertObject:rowData atIndex:rowIndex];
}

-(void)pushColumnData:(NSArray*)columnData {
    for (NSUInteger i = 0; i < [self.m_data count]; i++) {
        NSMutableArray* row = (NSMutableArray*)[self.m_data objectAtIndex:i];
        [row addObject:[columnData objectAtIndex:i]];
    }
}

-(void)pushColumnData:(NSArray*)columnData toIndex:(NSInteger)columnIndex  {
    for (NSUInteger i = 0; i < [self.m_data count]; i++) {
        NSMutableArray* row = (NSMutableArray*)[self.m_data objectAtIndex:i];
        [row insertObject:[columnData objectAtIndex:i] atIndex:columnIndex];
    }
}

-(NSArray*) getRowDataAtIndex:(NSInteger)rowIndex {
    NSArray* dataRow = (NSArray*)[self.m_data objectAtIndex:rowIndex];
    return dataRow;
}

-(NSArray*) getColumnDataAtIndex:(NSInteger)columnIndex {
    NSMutableArray* dataColumn = [NSMutableArray array];
    for (NSUInteger i = 0; i < [self.m_data count]; i++) {
        NSMutableArray* row = (NSMutableArray*)[self.m_data objectAtIndex:i];
        [dataColumn addObject:[row objectAtIndex:columnIndex]];
    }
    return dataColumn;
}

-(NSString*)getTextDataAtCellAtRow :(NSUInteger)row column:(NSUInteger)column {
    NSArray* dataRow = (NSArray*)[self.m_data objectAtIndex:row];
    NSString* text = (NSString*)[dataRow objectAtIndex:column];
    return text;
}

@end
