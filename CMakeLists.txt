cmake_minimum_required(VERSION 3.1)

project(MeshCraft)

find_package(OpenGL REQUIRED)

add_executable(MeshCraft
    resource/resource.rc
    source/CApplication.cpp
    source/CBaseConfig.cpp
    source/CBaseDialog.cpp
    source/CBaseObject.cpp
    source/CBasePlugin.cpp
    source/CBaseTool.cpp
    source/CBaseView.cpp
    source/CCamera.cpp
    source/CConfigManager.cpp
    source/CDialogAbout.cpp
    source/CDialogManager.cpp
    source/CDialogPlugins.cpp
    source/CLight.cpp
    source/CPluginManager.cpp
    source/CScene.cpp
    source/CTextureManager.cpp
    source/CToolCamera.cpp
    source/CToolManager.cpp
    source/CView3D.cpp
    source/CViewManager.cpp
    source/CWin.cpp
    source/mathlib.cpp
    source/simple_format.cpp
    source/WinMain.cpp
    shared/stb.cpp
    shared/wiskunde.cpp
    )

target_compile_features(MeshCraft
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_include_directories(MeshCraft
    PRIVATE resource
    PRIVATE shared
    )

target_link_libraries(MeshCraft
    ${OPENGL_LIBRARIES}
    )

#add_library(MeshFile SHARED
#    Plugins/MeshFile/CMeshFile.cpp
#    )

#target_include_directories(MeshFile
#    PRIVATE resource
#    PRIVATE shared
#    )

#add_library(SMDFile SHARED
#    Plugins/SMDFile/CSMDFile.cpp
#    )

#target_include_directories(SMDFile
#    PRIVATE resource
#    PRIVATE shared
#    )
