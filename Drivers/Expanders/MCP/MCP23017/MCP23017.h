/*
 * MCP23017.h
 *
 *  Created on: Dec 20, 2018
 *      Author: MCT E560 Marc
 */

#ifndef IO_EXPANDER_MCP230XX_MCP23017_MCP23017_H_
#define IO_EXPANDER_MCP230XX_MCP23017_MCP23017_H_

#include "../MCP230XX.h"

class MCP23017 : public MCP230XX {
public:
	MCP23017();
	virtual ~MCP23017();
	void begin();
};

#endif /* IO_EXPANDER_MCP230XX_MCP23017_MCP23017_H_ */
