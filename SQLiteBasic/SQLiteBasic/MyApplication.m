//
//  MyApplication.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "MyApplication.h"

@implementation MyApplication

static MyApplication* applicationInstance = nil;

+(MyApplication*)getInstance {
    if (applicationInstance == nil) {
        applicationInstance = [[MyApplication allocWithZone:NULL] init];
    }
    return applicationInstance;
}

-(id)init {
    if (self = [super init]) {
        m_sqliteDB = [SQLiteDatabase alloc];
    }
    return self;
}

-(SQLiteDatabase*)getDBInstance {
    return m_sqliteDB;
}

-(void)setDBInstance:(SQLiteDatabase*)sqliteDB {
    m_sqliteDB = sqliteDB;
}

@end
