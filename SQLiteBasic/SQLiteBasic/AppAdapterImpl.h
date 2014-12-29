//
//  AppAdapterImpl.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppAdapter.h"

@interface AppAdapterImpl : NSObject<AppAdapter, NSTableViewDataSource, NSTableViewDelegate>
@property (atomic, retain) NSMutableDictionary* m_tableColumnIdentifiers;
@end
