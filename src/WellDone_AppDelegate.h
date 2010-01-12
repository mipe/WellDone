//
//  WellDone_AppDelegate.h
//  WellDone
//
//  Created by Alex Leutgöb on 27.10.09.
//  Copyright alexleutgoeb.com 2009 . All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SidebarTaskController.h"
#import "SimpleListController.h"
#import "GTDListController.h"
#import "SidebarFolderController.h"
#import "TestDataGeneratorController.h"
#import "FolderManagementController.h"
#import "TagManagementController.h"
#import "ContextManagementController.h"
#import "PrioritySplitViewDelegate.h"
#import "ContextViewController.h"
#import "SS_PrefsController.h"
#import "HUDTaskEditorController.h"
#import "SyncController.h"
#import <netinet/in.h>
#import <SystemConfiguration/SystemConfiguration.h>

#define kReachabilityChangedNotification @"kNetworkReachabilityChangedNotification"

@interface WellDone_AppDelegate : NSObject<SyncControllerDelegate> {
    IBOutlet NSWindow *window;
	IBOutlet NSSplitView *splitView;
	PrioritySplitViewDelegate *splitViewDelegate;
 	IBOutlet NSView* sidebarTaskPlaceholderView;
	IBOutlet NSView* simpleListPlaceholderView;
	IBOutlet NSView* sidebarFolderPlaceholderView;
	IBOutlet NSView* contextPlaceholderView;
	
	IBOutlet NSProgressIndicator *syncProgress;
	IBOutlet NSButton *syncButton;
	NSMenuItem *syncMenuItem;
	
	IBOutlet NSTextField* quickAddTask;
	
	//is necessary for setting the first responder (focus) to the current view, e.g. after inserting new task:
	NSView* currentListView;
	
	IBOutlet NSPanel* foldermanagement;
    
	SidebarTaskController* sidebarTaskController;
	SimpleListController* simpleListController;
	SidebarFolderController* sidebarFolderController;
	GTDListController* gtdListController;
	FolderManagementController* foldermanagementController;
	TagManagementController* tagmanagementController;
	ContextManagementController* contextmanagementController;
	ContextViewController* contextViewController;
	HUDTaskEditorController* hudTaskEditorController;
	
    NSPersistentStoreCoordinator *persistentStoreCoordinator;
    NSManagedObjectModel *managedObjectModel;
    NSManagedObjectContext *managedObjectContext;
	
	BOOL showGTDView; 
	
@private
	SyncController *syncController;
	SS_PrefsController *preferencesController;
	
	NSStatusItem *menuBarItem;
	
	BOOL isOnline;
	SCNetworkReachabilityRef reachRef;
}

@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain, readonly) SimpleListController *simpleListController;
@property (nonatomic, retain, readonly) NSURL *coreDataDBLocationURL;
@property (nonatomic, retain, readonly) NSURL *backupDBLocationURL;
@property (nonatomic, assign) BOOL isOnline;

- (SyncController *)sharedSyncController;

- (IBAction)newTaskAction:(id)sender;
- (IBAction)newFolderAction:(id)sender;
- (IBAction)changeViewController:(id)sender;
- (IBAction)showPreferencesWindow:(id)sender;
- (void)showTestdatagenerator:(id)sender;
- (void)showFolderManagement:(id)sender;
- (void)showTagManagement:(id)sender;
- (void)showContextManagement:(id)sender;
- (void)addNewTask:(id)sender;
- (IBAction)filterTaskListByTitle:(id)sender;
- (void) registerValueTransformers;

- (IBAction) toggleInspector:(id) sender;

/**
 Starts the sync.
 */
- (IBAction)startSync:(id)sender;


@end

void networkStatusDidChange(SCNetworkReachabilityRef name, SCNetworkConnectionFlags flags, void * info);
