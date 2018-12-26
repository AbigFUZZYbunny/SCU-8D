/*
 * MCP230XX.h
 *
 *  Created on: Dec 20, 2018
 *      Author: MCT E560 Marc
 */

#ifndef IO_EXPANDER_MCP230XX_MCP230XX_H_
#define IO_EXPANDER_MCP230XX_MCP230XX_H_

#include <stdint.h>
#include "i2c.h"

class MCP230XX {
public:
	uint8_t i2cAddress;
	int i2cBus;

	MCP230XX();
	void init(int _bus, uint8_t _add);
	virtual ~MCP230XX();

	int ports;
	uint8_t ** read_state(uint8_t * receive_buffer[2]);
	uint8_t set_output(uint8_t _out);
	void write_register(uint8_t register_pointer, uint8_t register_value);
	uint8_t curState[2];

private:

};

// registers for both 16 bit and 8 bit
#define MCP230XX_IODIRA 0x00
#define MCP230XX_IPOLA 0x01
#define MCP230XX_GPINTENA 0x02
#define MCP230XX_DEFVALA 0x03
#define MCP230XX_INTCONA 0x04
#define MCP230XX_IOCONA 0x05
#define MCP230XX_GPPUA 0x06
#define MCP230XX_INTFA 0x07
#define MCP230XX_INTCAPA 0x08
#define MCP230XX_GPIOA 0x09
#define MCP230XX_OLATA 0x0A

//second set of registers for 16 bit
#define MCP230XX_IODIRB 0x10
#define MCP230XX_IPOLB 0x11
#define MCP230XX_GPINTENB 0x12
#define MCP230XX_DEFVALB 0x13
#define MCP230XX_INTCONB 0x14
#define MCP230XX_IOCONB 0x15
#define MCP230XX_GPPUB 0x16
#define MCP230XX_INTFB 0x17
#define MCP230XX_INTCAPB 0x18
#define MCP230XX_GPIOB 0x19
#define MCP230XX_OLATB 0x1A

#define MCP230XX_INT_ERR 255

#endif /* IO_EXPANDER_MCP230XX_MCP230XX_H_ */
