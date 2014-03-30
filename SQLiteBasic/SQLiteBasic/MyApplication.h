//
//  MyApplication.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SQLiteDatabase.h"

@interface MyApplication : NSObject
{
    SQLiteDatabase* m_sqliteDB;
}

+(MyApplication*)getInstance;

-(SQLiteDatabase*)getDBInstance;
-(void)setDBInstance:(SQLiteDatabase*)sqliteDB;
@end
