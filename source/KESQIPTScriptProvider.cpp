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

#include "VCPlugInHeaders.h"

// Interface includes:
#include "IApplication.h"
#include "IControlView.h"
#include "IPanelControlData.h"
#include "IPanelMgr.h"
#include "IScript.h"
#include "IScriptRequestData.h"
#include "ITextControlData.h"
#include "IWorkspace.h"

// General includes:
#include "CAlert.h"
#include "CScriptProvider.h"
#include "InfoPanelID.h" // for kInfoPanelBoss etc
#include "LinksUIID.h" // for kLinksUIPanelTreeWidgetBoss etc

// Project includes:
#include "KESQIPTScriptingDefs.h"
#include "KESQIPTID.h"
class KESQIPTScriptProvider : public CScriptProvider
{
public:
	// Constructor.
	// @param boss interface ptr from boss object on which this interface is aggregated.
	KESQIPTScriptProvider(IPMUnknown* boss) : CScriptProvider(boss) {};

	// Destructor. Does nothing.
	~KESQIPTScriptProvider() {}

	// This method is called if a provider can handle an method.
	// 
	// @param scriptID_method identifies the ID of the method to handle.
	// scriptID_methodは、処理対象となるメソッドのIDを特定します。
	// 
	// @param iScriptRequestData identifies an interface pointer used to extract data.
	// iScriptRequestDataは、データを抽出するために使用されるインターフェースポインタを識別します。
	// 
	// @param iScript_parent identifies an interface pointer on the script object representing the parent of the application object.
	// iScript_parentは、アプリケーションオブジェクトの親を表すスクリプトオブジェクト上のインターフェースポインタを識別します。
	virtual ErrorCode HandleMethod(ScriptID scriptID_method, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

private:
	// Query info panel text
	ErrorCode QueryInfoPanelText(ScriptID scriptID_method, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);
};

// CREATE_PMINTERFACE
// Binds the C++ implementation class onto its ImplementationID making the C++ code callable by the application.
CREATE_PMINTERFACE(KESQIPTScriptProvider, kKESQIPTScriptProviderImpl)

// HandleMethod
ErrorCode KESQIPTScriptProvider::HandleMethod(ScriptID scriptID_method, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	switch (scriptID_method.Get())
	{
	case KESQIPTScriptEvents::e_KESQIPTQueryInfoPanelText:
		status = this->QueryInfoPanelText(scriptID_method, iScriptRequestData, iScript_parent);
		break;

	default:
		status = CScriptProvider::HandleMethod(scriptID_method, iScriptRequestData, iScript_parent);
	}

    return status;
}

// Query panel text.
ErrorCode KESQIPTScriptProvider::QueryInfoPanelText(ScriptID scriptID_method, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	do {
		ScriptData scriptData;

		// ---------------------------------------------------------------------------------------
		// Argument
		PMString pMString_prefix; // Prefix
		status = iScriptRequestData->ExtractRequestData(KESQIPTScriptProperties::p_KESQIPTPrefix, scriptData);
		if (status != kSuccess) break;

		status = scriptData.GetPMString(pMString_prefix);
		if (status != kSuccess) break;

		int32 int32_widgetIndex; // Widget index
		status = iScriptRequestData->ExtractRequestData(KESQIPTScriptProperties::p_KESQIPTWidgetIndex, scriptData);
		if (status != kSuccess) break;

		status = scriptData.GetInt32(&int32_widgetIndex);
		if (status != kSuccess) break;

		// ---------------------------------------------------------------------------------------
		// Query ID.
		WidgetID widgetID_text;
		std::string stdStr_prefix = pMString_prefix.GetUTF8String();
		int32 int32_prefix = std::stoul(stdStr_prefix, nullptr, 16);
		widgetID_text = RezLong(int32_prefix) + int32_widgetIndex;

		// ---------------------------------------------------------------------------------------
		// Query panel.
		InterfacePtr<IApplication> iApplication(GetExecutionContextSession()->QueryApplication());
		InterfacePtr<IPanelMgr> iPanelMgr(iApplication->QueryPanelManager());

		// If the panel is not displayed.
		if (iPanelMgr->IsPanelWithMenuIDShown(kInfoPanelActionID) == kFalse)
		{
			iPanelMgr->ShowPanelByWidgetID(kInfoPanelParentWidgetID);
		}

		IControlView* iControlView_panel = iPanelMgr->GetPanelFromWidgetID(kInfoPanelParentWidgetID);
		if (iControlView_panel == nil) break;

		InterfacePtr<IPanelControlData> IPanelControlData_panel(iControlView_panel, ::UseDefaultIID());
		if (IPanelControlData_panel == nil) break;

		// ---------------------------------------------------------------------------------------
		// Query widget text.
		IControlView* iControlView_widget = IPanelControlData_panel->FindWidget(widgetID_text);
		if (iControlView_widget == nil)  break;

		InterfacePtr<ITextControlData> iTextControlData_widget(iControlView_widget, ::UseDefaultIID());
		if (iTextControlData_widget == nil) break;

		// ---------------------------------------------------------------------------------------
		// Append return data
		ScriptData scriptData_return;
		scriptData_return.SetPMString(iTextControlData_widget->GetString());

		iScriptRequestData->AppendReturnData(iScript_parent, scriptID_method, scriptData_return);

		status = kSuccess;
	} while (kFalse);

	return status;
}