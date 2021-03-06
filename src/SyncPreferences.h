//
//  SyncPreferences.h
//  WellDone
//
//  Created by Alex Leutgöb on 11.12.09.
//  Copyright 2009 alexleutgoeb.com. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "GtdApi.h"
#import "SS_PreferencePaneProtocol.h"
#import "SyncController.h"


@interface SyncPreferences : NSViewController <SS_PreferencePaneProtocol> {
@private
    IBOutlet NSScrollView *scrollView_accountList;
    IBOutlet NSTableView *tableView_accountList;
	IBOutlet NSTextField *textField_overview;
	
	BOOL editable;
}

@property (nonatomic, assign) BOOL editable;

- (void)editServiceSheetDidEndForService:(NSString *)serviceId withSuccess:(BOOL)success;

@end
