//
//  DBDocumentController.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/29/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "DBDocumentController.h"

@implementation DBDocumentController

//@Override
- (NSInteger)runModalOpenPanel:(NSOpenPanel *)openPanel forTypes:(NSArray *)types {
    NSLog(@"Types size:%ld",[types count]);
    if ([types count] > 0) {
        NSLog(@"%@",types);
    }
    NSMutableArray* editedTypes = [NSMutableArray arrayWithArray:types];
    return [super runModalOpenPanel:openPanel forTypes:editedTypes];
}

-(void)openDocumentWithContentsOfURL:(NSURL *)url display:(BOOL)displayDocument completionHandler:(void (^)(NSDocument *, BOOL, NSError *))completionHandler {
    @try {
        NSLog(@"Going to open URL %@", [url absoluteString]);
        
        [super openDocumentWithContentsOfURL:url display:displayDocument completionHandler:completionHandler];
    }
    @catch (NSException *exception) {
        NSLog(@"%@", exception);
    }
    @finally {
        
    }
    
}
@end
