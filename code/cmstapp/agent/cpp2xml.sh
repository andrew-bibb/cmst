#!/bin/bash
#
#	script to convert the header file to cpp
#
#	-M	all public slots
#	-P	all properties
qdbuscpp2xml -M -P agent.h -o org.monkey_business_enterprises.agent.xml
