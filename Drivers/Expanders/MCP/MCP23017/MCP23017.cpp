/*
 * MCP23017.cpp
 *
 *  Created on: Dec 20, 2018
 *      Author: MCT E560 Marc
 */

#include "MCP23017.h"

MCP23017::MCP23017() {
	// TODO Auto-generated constructor stub
	ports = 2;
}

MCP23017::~MCP23017() {
	// TODO Auto-generated destructor stub
}

void MCP23017::begin(){
		write_register(MCP230XX_IODIRA, 0xFF);
		write_register(MCP230XX_IODIRB, 0xFF);

		write_register(MCP230XX_IPOLA, 0xFF);
		write_register(MCP230XX_IPOLB, 0xFF);

		write_register(MCP230XX_GPINTENA, 0xFF);
		write_register(MCP230XX_GPINTENB, 0xFF);

		write_register(MCP230XX_DEFVALA, 0xFF);
		write_register(MCP230XX_DEFVALB, 0xFF);

		write_register(MCP230XX_INTCONA, 0x00);
		write_register(MCP230XX_INTCONB, 0x00);

		write_register(MCP230XX_GPPUA, 0xFF);
		write_register(MCP230XX_GPPUB, 0xFF);
}
