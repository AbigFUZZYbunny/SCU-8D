/*
 * MCP23008.h
 *
 *  Created on: Dec 20, 2018
 *      Author: MCT E560 Marc
 */

#ifndef EXPANDERS_MCP_MCP23008_MCP23008_H_
#define EXPANDERS_MCP_MCP23008_MCP23008_H_

#include "../MCP230XX.h"

class MCP23008 : public MCP230XX {
public:
	MCP23008();
	virtual ~MCP23008();
	void begin(bool output);
	void begin();
};

#endif /* IO_EXPANDER_MCP230XX_MCP23008_MCP23008_H_ */
