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


#ifndef __KESQIPTScriptingDefs_h__
#define __KESQIPTScriptingDefs_h__

#define kCPrefs_CLSID { 0x8d448fe0, 0x8194, 0x11d3, { 0xa6, 0x53, 0x0, 0xe0, 0x98, 0x71, 0xa, 0x6f } }
DECLARE_GUID(CPrefs_CLSID, kCPrefs_CLSID);

// Note: 4-char IDs below must be unique.
// See ScriptingDefs.h for further information.

// Method IDs
enum KESQIPTScriptEvents
{
	e_KESQIPTQueryInfoPanelText = 'KQPT',
};

// Property IDs
enum KESQIPTScriptProperties
{
	p_KESQIPTPrefix = 'KPfx',
	p_KESQIPTWidgetIndex = 'KWIx',
};

#endif // __KESQIPTScriptingDefs_h__