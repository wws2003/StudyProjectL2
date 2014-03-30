//
//  AppDelegate.m
//  SQLiteBasic
//
//  Created by wws2003 on 2/22/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "AppDelegate.h"
#import "Common.h"
#import "AdapterFactory.h"
#import "ModelFactory.h"
#import "ControllerFactory.h"
#import "DBDocumentController.h"

@interface AppDelegate (private)
-(void) initResultTable;
-(void) initResultTableModel;
-(void) initResultTableView;
-(void) initResultTableController;
@end

@implementation AppDelegate (private)

-(void) initResultTable {
    [self initResultTableModel];
    [self initResultTableView];
    [self initResultTableController];
}

-(void) initResultTableModel {
    self.model = [ModelFactory getAppModel];
}

-(void) initResultTableView {
    self.adapter = [AdapterFactory getAppAdapter:TABLE_VIEW_ADAPTER];
    if (self.adapter == nil) {
        NSLog(@"Adapter has not been initialized");
        assert(false);
    }
    [self.adapter registModelForView:self.model forView:self.tbvResultTable];
}

-(void) initResultTableController {
    self.resultTableController = [ControllerFactory getAppController];
    if (self.resultTableController == nil) {
        NSLog(@"Controller has not been initialized");
    }
    [self.resultTableController initModelAndViewByAdapter:self.adapter];
}

@end

@implementation AppDelegate

-(void)applicationWillFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    [self initResultTable];
    
    NSDocumentController* documentController = [[DBDocumentController alloc] init];
    [self setDbDocumentController:documentController];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return YES;
}

- (IBAction)openDocument:(NSMenuItem *)sender {
    NSDocumentController* documentController = [NSDocumentController sharedDocumentController];
    [documentController openDocument:sender];
}

- (IBAction)onBtnExecuteClicked:(NSButtonCell *)sender {

    [self.priResultIndicator startAnimation:self];
    Command* command = [[Command alloc] init:COMMAND_CODE_DUMMY withString:@""];
    [self.resultTableController receiveCommand:command];
    [self.priResultIndicator stopAnimation:self];
}

@end
