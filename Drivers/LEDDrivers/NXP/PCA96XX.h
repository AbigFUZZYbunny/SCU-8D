/*
 * PCA96XX.h
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#ifndef LEDDRIVERS_TI_PCA96XX_H_
#define LEDDRIVERS_TI_PCA96XX_H_

#include <stdint.h>
#include "i2c.h"

class PCA96XX {
public:
	uint8_t i2cAddress;
	int i2cBus;

	PCA96XX();
	void init(int _bus, uint8_t _add);
	virtual ~PCA96XX();

	int ports; //9626 = 3; 9624 = 2; 9622 = 1;
	void write_register(uint8_t register_pointer, uint8_t register_value);

	// Define 8 separate bit flags (these can represent whatever you want)
	const unsigned char option0 = 1 << 0; // 0000 0001
	const unsigned char option1 = 1 << 1; // 0000 0010
	const unsigned char option2 = 1 << 2; // 0000 0100
	const unsigned char option3 = 1 << 3; // 0000 1000
	const unsigned char option4 = 1 << 4; // 0001 0000
	const unsigned char option5 = 1 << 5; // 0010 0000
	const unsigned char option6 = 1 << 6; // 0100 0000
	const unsigned char option7 = 1 << 7; // 1000 0000

	unsigned char port0 = 0;
	unsigned char port1 = 0;
	unsigned char port2 = 0;
	unsigned char port3 = 0;
	unsigned char port4 = 0;
	unsigned char port5 = 0;
};

#define PCA96XX_MODE1	0x00
#define PCA96XX_MODE2	0x01

#endif /* LEDDRIVERS_TI_PCA96XX_H_ */
