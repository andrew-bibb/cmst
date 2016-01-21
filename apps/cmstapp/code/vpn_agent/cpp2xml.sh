#!/bin/bash
#
#	script to convert the header file to cpp
#
#	-M	all public slots
#	-P	all properties
#
# Adaptor and interface code is generated here because the QT autogenerator
# creates an adaptor class based on the last part of the interface name.
# So net.connman.Agent and net.connman.vpn.Agent both create an adaptor
# named AgentAdaptor.  This compiles fine, but Mr. Linker does not like it.
# Generate the vpn adaptors and interfaces here and then change all instances of
# AgentAdaptor to VPNAgentAdaptor. 
# 
qdbuscpp2xml -M -P vpnagent.h -o org.monkey_business_enterprises.vpnagent.xml
qdbusxml2cpp org.monkey_business_enterprises.vpnagent.xml -a vpnagent_adaptor
qdbusxml2cpp org.monkey_business_enterprises.vpnagent.xml -p vpnagent_interface
sed -i 's/AgentAdaptor/VPNAgentAdaptor/g' vpnagent_adaptor.h
sed -i 's/AgentAdaptor/VPNAgentAdaptor/g' vpnagent_adaptor.cpp
