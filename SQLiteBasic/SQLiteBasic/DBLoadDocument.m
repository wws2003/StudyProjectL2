//
//  DBLoadDocument.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/30/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "DBLoadDocument.h"
#import "MyApplication.h"

@implementation DBLoadDocument

- (id)init
{
    self = [super init];
    if (self) {
        // Add your subclass-specific initialization here.
    }
    return self;
}

- (NSString *)windowNibName
{
    // Override returning the nib file name of the document
    // If you need to use a subclass of NSWindowController or if your document supports multiple NSWindowControllers, you should remove this method and override -makeWindowControllers instead.
    return @"DBLoadDocument";
}

- (void)windowControllerDidLoadNib:(NSWindowController *)aController
{
    [super windowControllerDidLoadNib:aController];
    // Add any code here that needs to be executed once the windowController has loaded the document's window.
    [self.priLoadDB startAnimation:self];
    
    NSLog(@"Going to load DB");
    
    SEL job = @selector(loadDBFromURL:);
    NSThread* thread = [[NSThread alloc] initWithTarget:self selector:job object:[[self fileURL] path]];
    [thread start];
    
}

- (NSData *)dataOfType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to write your document to data of the specified type. If outError != NULL, ensure that you create and set an appropriate error when returning nil.
    // You can also choose to override -fileWrapperOfType:error:, -writeToURL:ofType:error:, or -writeToURL:ofType:forSaveOperation:originalContentsURL:error: instead.
    if (outError) {
        *outError = [NSError errorWithDomain:NSOSStatusErrorDomain code:unimpErr userInfo:nil];
    }
    return nil;
}

- (BOOL)readFromData:(NSData *)data ofType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to read your document from the given data of the specified type. If outError != NULL, ensure that you create and set an appropriate error when returning NO.
    // You can also choose to override -readFromFileWrapper:ofType:error: or -readFromURL:ofType:error: instead.
    // If you override either of these, you should also override -isEntireFileLoaded to return NO if the contents are lazily loaded.
    if (outError) {
        *outError = [NSError errorWithDomain:NSOSStatusErrorDomain code:unimpErr userInfo:nil];
    }
    return YES;
}

+ (BOOL)autosavesInPlace
{
    return YES;
}

-(void)loadDBFromURL:(NSString*)path {
    sleep(5);
    NSLog(@"Open DB file: %@", path);
    MyApplication* applicationInstance = [MyApplication getInstance];
    SQLiteDatabase* db = [applicationInstance getDBInstance];
    db = [db initByFilePath:path];
    [applicationInstance setDBInstance:db];
    
    SEL afterDBLoadedJob = @selector(afterDBLoaded);
    [self performSelectorOnMainThread:afterDBLoadedJob withObject:nil waitUntilDone:TRUE];
}

-(void)afterDBLoaded {
    [self.priLoadDB stopAnimation:self];
    [self.windowForSheet close];
    //[self.wdMain close];
}


@end
