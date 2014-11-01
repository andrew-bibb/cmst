#!/bin/bash
#
#	script to convert the header file to cpp
#
#	-M	all public slots
#	-P	all properties
# -S  all signals
qdbuscpp2xml -M -P roothelper.h -o org.monkey_business_enterprises.roothelper.xml
