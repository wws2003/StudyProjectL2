//
//  AdapterFactory.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/8/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "AdapterFactory.h"
#import "AppAdapterImpl.h"

@implementation AdapterFactory
+(NSObject<AppAdapter>*) getAppAdapter:(NSUInteger)adapterType {
    NSObject<AppAdapter>* result = nil;
    switch (adapterType) {
        case TABLE_VIEW_ADAPTER:
            result = [[AppAdapterImpl alloc] init];
            break;
        default:
            break;
    }
    return result;
}
@end
