/*
 * MCP23008.cpp
 *
 *  Created on: Dec 20, 2018
 *      Author: MCT E560 Marc
 */

#include "MCP23008.h"

MCP23008::MCP23008() {
	// TODO Auto-generated constructor stub
	ports = 1;
}

MCP23008::~MCP23008() {
	// TODO Auto-generated destructor stub
}

void MCP23008::begin(bool output){
	if(output){
		write_register(MCP230XX_IODIRA, 0x00);
		write_register(MCP230XX_IPOLA, 0x00);
		write_register(MCP230XX_GPINTENA, 0x00);
		write_register(MCP230XX_DEFVALA, 0x00);
		write_register(MCP230XX_INTCONA, 0xFF);
		write_register(MCP230XX_GPPUA, 0x00);
	}else{
		write_register(MCP230XX_IODIRA, 0xFF);
		write_register(MCP230XX_IPOLA, 0xFF);
		write_register(MCP230XX_GPINTENA, 0xFF);
		write_register(MCP230XX_DEFVALA, 0xFF);
		write_register(MCP230XX_INTCONA, 0x00);
		write_register(MCP230XX_GPPUA, 0xFF);
	}
}
