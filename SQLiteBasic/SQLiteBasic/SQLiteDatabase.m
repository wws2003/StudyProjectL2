//
//  SQLiteDatabase.m
//  SQLiteBasic
//
//  Created by wws2003 on 2/22/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "SQLiteDatabase.h"

@interface SQLiteDatabase (private)

-(id)getValueFromColumn : (sqlite3_stmt*) statement : (int) i;

@end

@implementation SQLiteDatabase (private)

-(id)getValueFromColumn : (sqlite3_stmt*) statement : (int) i {
    int columnType = sqlite3_column_type(statement, i);
    id value;
    switch (columnType) {
        case SQLITE_TEXT:
            value = [NSString stringWithFormat:@"%s",sqlite3_column_text(statement, i)];
            break;
        case SQLITE_FLOAT:
            value = [NSNumber numberWithFloat:sqlite3_column_double(statement, i)];
            break;
        case SQLITE_NULL:
            value = [NSNull null];
            break;
        default:
            value = [NSNull null];
            break;
    }
    return value;
}

@end

@implementation SQLiteDatabase

-(id)initByFilePath : (NSString*) filePath {
    if (self = [super init]) {
        sqlite3* dbConnection;
        if (sqlite3_open([filePath UTF8String], &dbConnection) != SQLITE_OK) {
            NSLog(@"Can not open connection to DB");
        }
        m_database = dbConnection;
    }
    return self;
}

-(NSArray*)performQuery: (NSString *)query {
    sqlite3_stmt* statement;
    const char* queryStr = [query UTF8String];
    if(sqlite3_prepare_v2(m_database, queryStr, -1, &statement, NULL) != SQLITE_OK) {
        NSLog(@"Can not prepare sqlite statement");
    }
    else {
        NSMutableArray* result = [NSMutableArray array];
        while(sqlite3_step(statement) == SQLITE_ROW) {
            NSMutableArray* row = [NSMutableArray array];
            for(int i = 0; i < sqlite3_column_count(statement); i++) {
                id columnValue = [self getValueFromColumn:statement:i];
                [row addObject:columnValue];
            }
            [result addObject:row];
        }
        return result;
    }
    return nil;
}

@end
