# InDesign Plug-In

**I'll add various things to ExtendScript.**
<br>**Let's learn the InDesign SDK together.**

We cannot be held responsible for any issues arising from your use of this service.<br>
Please use it at your own risk.<br>

On Mac, you cannot use downloaded plug-ins directly.<br>
https://helpx.adobe.com/jp/indesign/kb/indesign-and-macos-catalina.html<br>
Refer to the above and use Terminal to<br>
sudo xattr -r -d com.apple.quarantine /Applications/Adobe\ Indesign\ 2025/Plug-ins/KohakuExtendScript.InDesignPlugin<br>
Please execute.

## extendScript for JavaScript
```
// Retrieve the text displayed on the information panel.

// TypeToolPanelCursorXLocationLabel
value = app.queryInfoPanelText("0x17D00", 83);
alert(value);

// TypeToolPanelCursorYLocationLabel
value = app.queryInfoPanelText("0x17D00", 85);
alert(value);

// Save the list to the desktop.
var text = "";
for(i = 1; i <= 255; i++){
	value = app.queryInfoPanelText("0x15C00", i);
	text += "0x15C00 " + i + " : " + value + "\n";
}
for(i = 1; i <= 255; i++){
	value = app.queryInfoPanelText("0x17D00", i);
	text += "0x17D00 " + i + " : " + value + "\n";
}
var f0 = File("~/desktop/InfoPanelText.txt");
f0.open("w");
f0.write(text);
f0.close();
```

## Build Method
**Mac Edition**

**1. Download the SDK**<br>
https://developer.adobe.com/indesign/

**2. Downloading the programming software, Xcode**<br>
SDK/docs/html/index.html<br>
Download the Xcode version compatible with your InDesign version as a reference.<br>
https://developer.apple.com/download/all/?q=xcode

**3. Create a PlugIn template**<br>
Search for and install Java to use dolly.jar<br>
SDK/devtools/dolly/dolly.jar<br>
use<br>
![DollyXs1](https://github.com/user-attachments/assets/51c2d74e-a4fd-4f59-a0a3-be12664886b3)<br>
![DollyXs2](https://github.com/user-attachments/assets/f3217a76-ae24-4900-91de-70192542722d)<br>
![DollyXs3](https://github.com/user-attachments/assets/c1529862-f564-44c9-a7ff-ed72d327351a)<br>
![DollyXs4](https://github.com/user-attachments/assets/7b38b6ef-65c6-4e59-ad6f-f8037bfc5478)<br>
The project directory is located at<br>
SDK/build/mac/prj<br>
Set up and create as follows.

**4. Download the source from Git**<br>
![Git](https://github.com/user-attachments/assets/5157f513-096f-4e2e-b471-af644948e97c)<br>
Place the source files in the<br>
SDK/source/sdksamples/KohakuExtendScript<br>
folder.

**5. Build in Xcode**<br>
Load KohakuExtendScript project in Xcode.<br>
Add source to the plugin.<br>
KESScriptProvider.cpp file is already present in Source.<br>
KES.fr file is already present in Resources.<br>
KESID.h file is already present in Plugin, so I don't think it needs to be added to the project.<br>
KESScriptingDefs.h is also not displayed, but it should be included in the project, so I don't think it needs to be added.<br>
![add](https://github.com/user-attachments/assets/b59fa0ad-5317-4d33-a50c-fb83f53aa459)&nbsp;  
Set the build configuration to Release.<br>
![add](https://github.com/user-attachments/assets/f8f82811-aa80-45e3-a15b-3938aa53e278)<br>
Product > Build

**6. Load PlugIn**<br>
SDK/build/mac/release_cocoa64/KohakuExtendScript.InDesignPlugin<br>
Place the PlugIn in the PlugIn folder in InDesign.<br>
If the message “As the correct plugin” appears.<br>
Product > Clean Build Folder...<br>
After performing the above, please try building.
