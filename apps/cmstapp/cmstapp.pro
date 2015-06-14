#  We need the qt libraries, we want compiler warnings on, and this is a release version of the program  
CONFIG += qt
CONFIG += warn_on
CONFIG += release
CONFIG += nostrip 

#  Widgets needed for QT5, 
QT += widgets
QT += dbus
QT += network
QT += core

# cmst variables
include(../../cmst.pri)

TEMPLATE = app
TARGET = cmst
target.path = /usr/bin
INSTALLS += target

documentation.path = $$CMST_DOC_PATH/man1
documentation.files = ../../misc/manpage/cmst.1.gz
documentation.CONFIG = no_check_exist
documentation.extra = gzip --force ../../misc/manpage/cmst.1
INSTALLS += documentation

desktop.path = /usr/share/applications
desktop.files = ../../misc/desktop/cmst.desktop
INSTALLS += desktop

autostart.path = /usr/share/cmst/autostart
autostart.files = ../../misc/desktop/cmst-autostart.desktop
INSTALLS += autostart

icon.path = /usr/share/icons/hicolor/24x24/apps
icon.files = ../../images/application/cmst.png
INSTALLS += icon

# dbus
DBUS_ADAPTORS 	+= ./code/agent/org.monkey_business_enterprises.agent.xml
DBUS_INTERFACES	+= ./code/agent/org.monkey_business_enterprises.agent.xml
DBUS_ADAPTORS 	+= ./code/counter/org.monkey_business_enterprises.counter.xml
DBUS_INTERFACES	+= ./code/counter/org.monkey_business_enterprises.counter.xml

#	header files
HEADERS		+= ../resource.h
HEADERS 	+= ./code/control_box/controlbox.h
HEADERS		+= ./code/agent/agent.h
HEADERS		+= ./code/agent/agent_dialog.h
HEADERS		+= ./code/counter/counter.h
HEADERS		+= ./code/scrollbox/scrollbox.h
HEADERS		+= ./code/notify/notify.h
HEADERS		+= ./code/peditor/peditor.h
HEADERS   += ./code/provisioning/prov_ed.h
HEADERS		+= ./code/trstring/tr_strings.h
HEADERS		+= ./code/iconman/iconman.h

#	forms
FORMS		+= ./code/control_box/ui/controlbox.ui
FORMS		+= ./code/agent/ui/agent.ui
FORMS		+= ./code/scrollbox/ui/scrollbox.ui
FORMS		+= ./code/peditor/ui/peditor.ui
FORMS		+= ./code/provisioning/ui/provisioning_editor.ui

#	sources
SOURCES	+= ./code/main.cpp
SOURCES	+= ./code/control_box/controlbox.cpp
SOURCES += ./code/agent/agent.cpp
SOURCES += ./code/agent/agent_dialog.cpp
SOURCES += ./code/counter/counter.cpp
SOURCES += ./code/scrollbox/scrollbox.cpp
SOURCES += ./code/notify/notify.cpp
SOURCES	+= ./code/peditor/peditor.cpp
SOURCES += ./code/provisioning/prov_ed.cpp
SOURCES	+= ./code/trstring/tr_strings.cpp
SOURCES	+= ./code/iconman/iconman.cpp

#	resource files
RESOURCES 	+= ../../cmst.qrc

##  Place all object files in their own directory and moc files in their own directory
##  This is not necessary but keeps things cleaner.
OBJECTS_DIR = ./object_files
MOC_DIR = ./moc_files

sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
