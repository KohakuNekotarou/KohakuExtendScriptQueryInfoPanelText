//========================================================================================
//  
//  $File: $
//  
//  Owner: 
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================


#ifndef __KESQIPTID_h__
#define __KESQIPTID_h__

#include "SDKDef.h"

// Company:
#define kKESQIPTCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kKESQIPTCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kKESQIPTPluginName	"KohakuExtendScriptQueryPanelText"			// Name of this plug-in.
#define kKESQIPTPrefixNumber	0xe204450 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kKESQIPTVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kKESQIPTAuthor		""					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kKESQIPTPrefixNumber above to modify the prefix.)
#define kKESQIPTPrefix		RezLong(kKESQIPTPrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kKESQIPTStringPrefix	SDK_DEF_STRINGIZE(kKESQIPTPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kKESQIPTMissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kKESQIPTMissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kKESQIPTPluginID, kKESQIPTPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kKESQIPTScriptProviderBoss, kKESQIPTPrefix + 0)

// InterfaceIDs:
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESQIPTINTERFACE, kKESQIPTPrefix + 0)

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kKESQIPTScriptProviderImpl, kKESQIPTPrefix + 0 )

// ActionIDs:
DECLARE_PMID(kActionIDSpace, kKESQIPTAboutActionID, kKESQIPTPrefix + 0)

// WidgetIDs:
//DECLARE_PMID(kWidgetIDSpace, kKESQIPTWidgetID, kKESQIPTPrefix + 2)

//Script Element IDs
DECLARE_PMID(kScriptInfoIDSpace, kKESQIPTQueryPanelTextMethodScriptElement, kKESQIPTPrefix + 0)

// "About Plug-ins" sub-menu:
#define kKESQIPTAboutMenuKey			kKESQIPTStringPrefix "kKESQIPTAboutMenuKey"
#define kKESQIPTAboutMenuPath		kSDKDefStandardAboutMenuPath kKESQIPTCompanyKey

// "Plug-ins" sub-menu:
#define kKESQIPTPluginsMenuKey 		kKESQIPTStringPrefix "kKESQIPTPluginsMenuKey"
#define kKESQIPTPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kKESQIPTCompanyKey kSDKDefDelimitMenuPath kKESQIPTPluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kKESQIPTAboutBoxStringKey	kKESQIPTStringPrefix "kKESQIPTAboutBoxStringKey"
#define kKESQIPTTargetMenuPath kKESQIPTPluginsMenuPath

// Menu item positions:

// Initial data format version numbers
#define kKESQIPTFirstMajorFormatNumber  RezLong(1)
#define kKESQIPTFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kKESQIPTCurrentMajorFormatNumber kKESQIPTFirstMajorFormatNumber
#define kKESQIPTCurrentMinorFormatNumber kKESQIPTFirstMinorFormatNumber

#endif // __KESQIPTID_h__
