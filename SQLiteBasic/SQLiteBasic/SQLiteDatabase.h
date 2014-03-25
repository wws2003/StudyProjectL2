//
//  SQLiteDatabase.h
//  SQLiteBasic
//
//  Created by wws2003 on 2/22/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@interface SQLiteDatabase : NSObject
{
    sqlite3* m_database;
}

-(id)initByFilePath : (NSString*) filePath;
-(NSArray*) performQuery : (NSString*) query;

@end
