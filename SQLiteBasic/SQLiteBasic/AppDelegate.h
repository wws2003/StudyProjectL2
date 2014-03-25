//
//  AppDelegate.h
//  SQLiteBasic
//
//  Created by wws2003 on 2/22/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "AppController.h"
#import "AppModel.h"
#import "AppAdapter.h"

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSTextField* tfSqlQuery;
@property (assign) IBOutlet NSButton *btnExecute;
@property (assign) IBOutlet NSTableView *tbvResultTable;
@property (assign) IBOutlet NSScrollView *srvResultTable;
@property (assign) IBOutlet NSProgressIndicator *priResultIndicator;

@property (assign) AppModel* model;
@property (assign) NSObject<AppAdapter>* adapter;
@property (assign) NSObject<AppController>* resultTableController;

- (IBAction)onBtnExecuteClicked:(NSButtonCell *)sender;

@end
