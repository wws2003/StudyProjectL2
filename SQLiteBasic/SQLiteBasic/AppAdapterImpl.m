//
//  AppAdapterImpl.m
//  SQLiteBasic
//
//  Created by wws2003 on 3/2/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#import "AppAdapterImpl.h"

@interface AppAdapterImpl(private)
-(void)loadColumnsForTableView;
-(NSUInteger)getColumnIndexByIdentifier:(NSString*)identifier;
@end

@implementation AppAdapterImpl(private)

static CGFloat const COLUMN_WIDTH = 150;
static CGFloat const ROW_HEIGTH = 20;

-(void)loadColumnsForTableView {
    NSTableView* tableView = (NSTableView*)self.m_view;
    
    //Clear previous table columns
    NSArray* oldTableColumns = [[[tableView tableColumns] copy] autorelease];
    NSUInteger oldNumberOfColumns = [oldTableColumns count];
    
    @try {
        for (NSUInteger i = 0; i < oldNumberOfColumns; i++) {
            NSTableColumn* columnToRemove = (NSTableColumn*)[oldTableColumns objectAtIndex:i];
            [tableView removeTableColumn:columnToRemove];
        }
        [self.m_tableColumnIdentifiers removeAllObjects];
    }
    @catch (NSException *exception) {
        NSLog(@"%s %ld",[[exception reason] UTF8String], [oldTableColumns count]);
        NSLog(@"%@", [exception callStackSymbols]);
        exit(1);
    }
    assert([tableView numberOfColumns] == 0);
    
    const NSUInteger numberOfColumns = [self.m_model getNumberOfColumns];
    const NSUInteger numberOfRows = [self.m_model getNumberOfRows];
    
    //This code doesn't work. The table frame size doesn't change
    [tableView setNeedsDisplay:TRUE];
    NSSize tableSize;
    tableSize.width = COLUMN_WIDTH * numberOfColumns;
    tableSize.height = ROW_HEIGTH * numberOfRows;
    [tableView setFrameSize:tableSize];
    
    //This code works ! Any column has the same size as setting
    [tableView setColumnAutoresizingStyle:NSTableViewNoColumnAutoresizing];
    
    //Add columns to table view according model data
    @try {
        if (numberOfRows > 0) {
            for (NSUInteger i = 0; i < numberOfColumns; i++) {
                NSString* columnIdentifier = [NSString stringWithFormat:@"column%ld", i];
                NSTableColumn* newColumn = [[[NSTableColumn alloc] initWithIdentifier:columnIdentifier] autorelease];
                [newColumn setWidth:COLUMN_WIDTH];
                [tableView addTableColumn:newColumn];
//                NSLog(@"-------Data display size [%lf, %lf]", (i + 1) * COLUMN_WIDTH, numberOfRows * ROW_HEIGTH);
//                NSLog(@"-------Table size [%lf, %lf]", tableView.frame.size.width, tableView.frame.size.height);
//                NSLog(@"-------Superview class %s",[[[tableView superview] className] UTF8String]);
//                NSLog(@"-------Clipped size [%lf, %lf]", [tableView superview].frame.size.width, [tableView superview].frame.size.height);
                [self.m_tableColumnIdentifiers setObject:[NSNumber numberWithInteger:i] forKey:columnIdentifier];
            }
        }
    }
    @catch (NSException *exception) {
        NSLog(@"%s %@",[[exception reason] UTF8String], [exception callStackSymbols]);
        exit(1);
    }
    
    //NSLog(@"Table size [%lf, %lf]", tableView.frame.size.width, tableView.frame.size.height);
}

-(NSUInteger)getColumnIndexByIdentifier:(NSString*)identifier {
    return [[self.m_tableColumnIdentifiers objectForKey:identifier] intValue];
}

@end

@implementation AppAdapterImpl
@synthesize m_model;
@synthesize m_view;

-(id)init {
    if (self = [super init]) {
        self.m_tableColumnIdentifiers = [NSMutableDictionary dictionary];
    }
    return self;
}

-(void)registModelForView:(AppModel*)model forView:(NSView*)view {
    assert([view isKindOfClass:[NSTableView class]]);
    [self setM_model:model];
    [self setM_view:view];
    [self initViewFromModel];
}
-(void)initViewFromModel {
    
    NSTableView* tableView = (NSTableView*)self.m_view;
    
    //Initialize table view ?
    tableView = [tableView init];
    [tableView setDelegate:self];
    [tableView setDataSource:self];
    [tableView setRowHeight:ROW_HEIGTH];
    
    [self loadColumnsForTableView];
}

-(NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {
    NSInteger count = [[[self m_model] m_data] count];
    return count;
}

-(NSView*) tableView:(NSTableView *)tableView
                viewForTableColumn:(NSTableColumn *)tableColumn
                row:(NSInteger)rowIndex {
    
    NSString* identifier = [tableColumn identifier];
    NSUInteger columnIndex = [self getColumnIndexByIdentifier:identifier];
    
    NSTextField* result = [tableView makeViewWithIdentifier:identifier owner:self];
    if (result == nil) {
        result = [[NSTextField alloc] init];
        [result setEditable:false];
        result.identifier = identifier;
    }
  
    NSString* cellStr = [self.m_model getTextDataAtCellAtRow:rowIndex column:columnIndex];
    result.stringValue = cellStr;
    return result;
}

-(void)notifyView {
    [self loadColumnsForTableView];
     NSTableView* tableView = (NSTableView*)self.m_view;
    [tableView reloadData];
}

@end
