//
//  AppModel.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppModel : NSObject
-(id)init;
-(NSInteger)getNumberOfRows;
-(NSInteger)getNumberOfColumns;

-(void)pushRowData:(NSArray*)rowData;
-(void)pushRowData:(NSArray*)rowData toIndex:(NSInteger)rowIndex ;

-(void)pushColumnData:(NSArray*)columnData;
-(void)pushColumnData:(NSArray*)columnData toIndex:(NSInteger)columnIndex ;

-(NSArray*) getRowDataAtIndex:(NSInteger)rowIndex;
-(NSArray*) getColumnDataAtIndex:(NSInteger)columnIndex;

-(NSString*)getTextDataAtCellAtRow :(NSUInteger)row column:(NSUInteger)column;
@property (retain) NSMutableArray* m_data;
@end
