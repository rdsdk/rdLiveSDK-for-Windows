copy ..\debug\AudioCA.dll SDK\Debug
copy ..\debug\AudioCB.dll SDK\Debug
copy ..\debug\AudioRec.dll SDK\Debug
copy ..\debug\fraps32.dll SDK\Debug
copy ..\debug\fraps64.dll SDK\Debug
copy ..\debug\glew32d.dll SDK\Debug
copy ..\debug\GlRender.dll SDK\Debug
copy ..\debug\GlRender.ini SDK\Debug
copy ..\debug\GEncoder.dll SDK\Debug
copy ..\debug\libgcc_s_dw2-1.dll SDK\Debug
copy ..\debug\libx264-148.dll SDK\Debug
copy ..\debug\nvcuvenc.dll SDK\Debug
copy ..\debug\Option.xml SDK\Debug
copy ..\debug\RDLiveSDK.dll SDK\Debug
copy ..\debug\GameAgent.exe SDK\Debug
copy ..\debug\RtmpPlayer.swf SDK\Debug


copy ..\release\AudioCA.dll SDK\release
copy ..\release\AudioCB.dll SDK\release
copy ..\release\AudioRec.dll SDK\release
copy ..\release\fraps32.dll SDK\release
copy ..\release\fraps64.dll SDK\release
copy ..\release\glew32.dll SDK\release
copy ..\release\GlRender.dll SDK\release
copy ..\release\GlRender.ini SDK\release
copy ..\release\GEncoder.dll SDK\release
copy ..\release\libgcc_s_dw2-1.dll SDK\release
copy ..\release\libx264-148.dll SDK\release
copy ..\release\nvcuvenc.dll SDK\release
copy ..\release\Option.xml SDK\release
copy ..\release\RDLiveSDK.dll SDK\release
copy ..\release\GameAgent.exe SDK\release
copy ..\debug\RtmpPlayer.swf SDK\release

copy ..\lib\RDLiveSDK.lib SDK\Lib
copy ..\include\GEncoderParams.h SDK\Include
copy ..\include\IGlRenderDefine.h SDK\Include
copy ..\include\RDLiveSDK.h SDK\Include

copy ..\debug\DemoFull_VC2008(MFC).exe Demo\Debug
copy ..\debug\DemoFull_VC2008(Qt4).exe Demo\Debug
copy ..\debug\DemoSimple_VC2008(Win32).exe Demo\Debug
copy ..\debug\QtXmld4.dll Demo\Debug
copy ..\debug\QtGuid4.dll Demo\Debug
copy ..\debug\QtCored4.dll Demo\Debug

copy ..\release\DemoFull_VC2008(MFC).exe Demo\release
copy ..\release\DemoFull_VC2008(Qt4).exe Demo\release
copy ..\release\DemoSimple_VC2008(Win32).exe Demo\release
copy ..\release\QtXml4.dll Demo\release
copy ..\release\QtGui4.dll Demo\release
copy ..\release\QtCore4.dll Demo\release

copy "..\GliveHelp\RDLive_output\HTML Help\help.chm" SDK\help.chm
copy "..\GliveHelp\RDLive_output\HTML Help\help.chm" Demo\help.chm
copy "..\GliveHelp\RDLive_output\HTML Help\help.chm" help.chm
copy "..\GliveHelp\RDLive_output\PDF\a.pdf" SDK\help.pdf
copy "..\GliveHelp\RDLive_output\PDF\a.pdf" Demo\help.pdf
copy "..\GliveHelp\RDLive_output\PDF\a.pdf" help.pdf


copy SDK\Include\*.* Demo\Include
copy SDK\Lib\*.* Demo\Lib
copy SDK\Debug\*.* Demo\Debug
copy SDK\Release\*.* Demo\Release


pause