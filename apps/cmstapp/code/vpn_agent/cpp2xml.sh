#!/bin/bash
#
#	script to convert the header file to cpp
#
#	-M	all public slots
#	-P	all properties
qdbuscpp2xml -M -P vpnagent.h -o org.monkey_business_enterprises.vpnagent.xml
qdbusxml2cpp org.monkey_business_enterprises.vpnagent.xml -a vpnagent_adaptor
qdbusxml2cpp org.monkey_business_enterprises.vpnagent.xml -p vpnagent_interface
sed -i 's/AgentAdaptor/VPNAgentAdaptor/g' vpnagent_adaptor.h
sed -i 's/AgentAdaptor/VPNAgentAdaptor/g' vpnagent_adaptor.cpp
