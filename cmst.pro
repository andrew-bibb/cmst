#  We need the qt libraries, we want compiler warnings off, and this is a release version of the program  
CONFIG += qt warn_off release 

#  Widgets needed for QT5, 
QT += widgets
QT += dbus

TARGET = cmst
TEMPLATE = app
target.path = /usr/bin/
INSTALLS += target

# dbus
DBUS_ADAPTORS 	+= ./code/agent/org.monkey_business_enterprises.agent.xml
DBUS_INTERFACES	+= ./code/agent/org.monkey_business_enterprises.agent.xml
DBUS_ADAPTORS 	+= ./code/counter/org.monkey_business_enterprises.counter.xml
DBUS_INTERFACES	+= ./code/counter/org.monkey_business_enterprises.counter.xml

#	header files
HEADERS		+= ./code/resource.h
HEADERS 	+= ./code/control_box/controlbox.h
HEADERS		+= ./code/agent/agent.h
HEADERS		+= ./code/agent/agent_dialog.h
HEADERS		+= ./code/counter/counter.h

#	forms
FORMS		+= ./code/control_box/ui/controlbox.ui
FORMS		+= ./code/agent/ui/agent.ui

#	sources
SOURCES	+= ./code/main.cpp
SOURCES	+= ./code/control_box/controlbox.cpp
SOURCES += ./code/agent/agent.cpp
SOURCES += ./code/agent/agent_dialog.cpp
SOURCES += ./code/counter/counter.cpp

#	resource files
RESOURCES 	+= cmst.qrc


##  Place all object files in their own directory and moc files in their own directory
##  This is not necessary but keeps things cleaner.
OBJECTS_DIR = ./object_files
MOC_DIR = ./moc_files


sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro

