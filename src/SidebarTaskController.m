//
//  SidebarTaskController.m
//  WellDone
//
//  Created by Dominik Hofer on 16/11/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "SidebarTaskController.h"


@implementation SidebarTaskController

- (id) init
{
	self = [super initWithNibName:@"SidebarTask" bundle:nil];
	if (self != nil)
	{		
		note.delegate = self;
	}
	return self;
}

- (BOOL)control:(NSControl *)control textShouldBeginEditing:(NSText *)fieldEditor
{
	NSLog(@"wtf");
}

@end
