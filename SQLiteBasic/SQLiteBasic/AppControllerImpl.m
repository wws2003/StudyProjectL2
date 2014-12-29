//
//  AppControllerImpl.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/18/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "AppControllerImpl.h"
#import "AppController.h"
#import "Common.h"

@interface AppControllerImpl(private)
-(void)updateModelByDuplicateRow:(AppModel*)model;
@end

@implementation AppControllerImpl(private)
-(void)updateModelByDuplicateRow:(AppModel*)model {
    @autoreleasepool {
        NSInteger numberOfRow = [model getNumberOfRows];
        NSArray* lastDataRow = [model getRowDataAtIndex:numberOfRow - 1];
        [model pushRowData:lastDataRow];
        
        NSInteger numberOfColumn = [model getNumberOfColumns];
        NSArray* lastDataColumn = [model getColumnDataAtIndex:numberOfColumn - 1];
        [model pushColumnData:lastDataColumn];
        
        //sleep(20);
    
        //Update GUI in main thread
        if(![NSThread isMainThread]) {
            SEL notifyViewSelector = @selector(notifyView);
            [[self m_appAdapter] performSelectorOnMainThread:notifyViewSelector withObject:nil waitUntilDone:FALSE];
        } else {
            [[self m_appAdapter] notifyView];
        }
    }
}
@end

@implementation AppControllerImpl

-(void)initModelAndView:(AppModel*)model withView:(NSView*)view {
    
}

-(void)initModelAndViewByAdapter:(NSObject<AppAdapter>*)adapter {
    [self setM_appAdapter:adapter];
}

-(void)receiveCommand:(Command*)command {
    if ([command m_commandCode] == COMMAND_CODE_DUMMY) {
        bool doInBackground = [[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBackgroundThread"] boolValue];
        
        if (doInBackground) {
            SEL job = @selector(updateModelByDuplicateRow:);
            NSThread* thread = [[NSThread alloc] initWithTarget:self selector:job object:[self.m_appAdapter m_model]];
            
            //Join (wait for) the thread to run ? - Require posix thread!
            [thread start];
        }
        else {
            [self updateModelByDuplicateRow:[self.m_appAdapter m_model]];
        }
    }
}

@end
