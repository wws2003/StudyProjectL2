//
//  DBLoadDocument.h
//  SQLiteBasic
//
//  Created by wws2003 on 3/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface DBLoadDocument : NSDocument

-(void)loadDBFromURL:(NSURL*)url;

-(void) afterDBLoaded;

@property (assign) IBOutlet NSProgressIndicator *priLoadDB;

@end
