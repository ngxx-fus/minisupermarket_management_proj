cmake_minimum_required(VERSION 3.5)

project(MiniSupermarKetmanagement VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        minisupermarketmanagement.cpp
        minisupermarketmanagement.h
        minisupermarketmanagement.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MiniSupermarKetmanagement
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        template_class.h templateclass.cpp
        commodities.h commodities.cpp
        managerproduct.h managerproduct.cpp managerproduct.ui
        managerproduct.ui minisupermarketmanagement.ui
        managerproduct.ui minisupermarketmanagement.ui
        invoice.h invoice.cpp
        InvoiceManagement.cpp InvoiceManagement.h InvoiceManagement.ui
        my_customer.h my_customer.cpp my_customer.ui
        _time.h





        _customers.h _customers.cpp




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MiniSupermarKetmanagement APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MiniSupermarKetmanagement SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MiniSupermarKetmanagement
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MiniSupermarKetmanagement PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MiniSupermarKetmanagement)
endif()
set_target_properties(MiniSupermarKetmanagement PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MiniSupermarKetmanagement
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MiniSupermarKetmanagement)
endif()
