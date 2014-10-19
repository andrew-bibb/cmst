#  We need the qt libraries, we want compiler warnings off, and this is a release version of the program  
CONFIG += qt
CONFIG +=warn_off
CONFIG +=release
CONFIG +=nostrip 

#  Widgets needed for QT5, 
QT += widgets
QT += dbus
QT += network

TEMPLATE = app
TARGET = cmst
target.path = /usr/bin/
INSTALLS += target

documentation.path = /usr/share/man/man1
documentation.files = ./misc/manpage/cmst.1.gz
documentation.CONFIG = no_check_exist
documentation.extra = gzip --keep --force ./misc/manpage/cmst.1
INSTALLS += documentation

desktop.path = /usr/share/applications
desktop.files = ./misc/desktop/cmst.desktop
INSTALLS += desktop

icon.path = /usr/share/icons/hicolor/24x24/apps
icon.files = ./misc/desktop/cmst.png
INSTALLS += icon

# dbus
DBUS_ADAPTORS 	+= ./agent/org.monkey_business_enterprises.agent.xml
DBUS_INTERFACES	+= ./agent/org.monkey_business_enterprises.agent.xml
DBUS_ADAPTORS 	+= ./counter/org.monkey_business_enterprises.counter.xml
DBUS_INTERFACES	+= ./counter/org.monkey_business_enterprises.counter.xml

#	header files
HEADERS		+= ../resource.h
HEADERS 	+= ./control_box/controlbox.h
HEADERS		+= ./agent/agent.h
HEADERS		+= ./agent/agent_dialog.h
HEADERS		+= ./counter/counter.h
HEADERS		+= ./scrollbox/scrollbox.h
HEADERS		+= ./notify/notify.h
HEADERS		+= ./peditor/peditor.h
HEADERS   += ./provisioning/prov_ed.h

#	forms
FORMS		+= ./control_box/ui/controlbox.ui
FORMS		+= ./agent/ui/agent.ui
FORMS		+= ./scrollbox/ui/scrollbox.ui
FORMS		+= ./peditor/ui/peditor.ui
FORMS		+= ./provisioning/ui/provisioning_editor.ui

#	sources
SOURCES	+= ./main.cpp
SOURCES	+= ./control_box/controlbox.cpp
SOURCES += ./agent/agent.cpp
SOURCES += ./agent/agent_dialog.cpp
SOURCES += ./counter/counter.cpp
SOURCES += ./scrollbox/scrollbox.cpp
SOURCES += ./notify/notify.cpp
SOURCES	+= ./peditor/peditor.cpp
SOURCES += ./provisioning/prov_ed.cpp

#	resource files
RESOURCES 	+= ../../cmst.qrc

##  Place all object files in their own directory and moc files in their own directory
##  This is not necessary but keeps things cleaner.
OBJECTS_DIR = ./object_files
MOC_DIR = ./moc_files

sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
