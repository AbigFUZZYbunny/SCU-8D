/*
 * MCP230XX.cpp
 *
 *  Created on: Dec 20, 2018
 *      Author: MCT E560 Marc
 */

#include <stdint.h>
#include "MCP230XX.h"

MCP230XX::MCP230XX() {

}

MCP230XX::~MCP230XX() {
	// TODO Auto-generated destructor stub

}

void MCP230XX::init(int _bus, uint8_t _add){
	i2cAddress = _add; //might need to divide by 2 to create a 7 bit address that will have the R/W bit added by the HAL (_add / 2);
	i2cBus = _bus;
	//reset();

	write_register(0x05,0xE2);
}

void MCP230XX::write_register(uint8_t register_pointer, uint8_t register_value)
{
    uint8_t data[2];

    data[0] = register_pointer;
    data[1] = register_value;

    switch(i2cBus){
    case 1:
    	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 2, 20);
    	break;
    /*case 2:
    	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 2, 20);
    	break;*/
    }
}

uint8_t ** MCP230XX::read_state(uint8_t ** receive_buffer){ //receive_buffer will be curState passed to this argument
	uint8_t _GPIOA = (uint8_t)MCP230XX_GPIOA;
	uint8_t _GPIOB = (uint8_t)MCP230XX_GPIOB;
	switch(i2cBus){
		case 1:
			HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, &_GPIOA, 1, 10);
			HAL_I2C_Master_Receive(&hi2c1, i2cAddress<<1, receive_buffer[0], 1, 10);
			break;
		/*case 2:
			HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, &_GPIOA, 1, 10);
			HAL_I2C_Master_Receive(&hi2c2, i2cAddress<<1, receive_buffer[0], 1, 10);
			break;*/
	}

	if(ports > 1){
		switch(i2cBus){
			case 1:
			  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, &_GPIOB, 1, 10);
			  	HAL_I2C_Master_Receive(&hi2c1, i2cAddress<<1, receive_buffer[1], 1, 10);
			   	break;
			/*case 2:
			   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, &_GPIOB, 1, 10);
			   	HAL_I2C_Master_Receive(&hi2c2, i2cAddress<<1, receive_buffer[1], 1, 10);
			   	break;*/
			}

		return receive_buffer;
	}else{

		return receive_buffer;
	}
}

uint8_t MCP230XX::set_output(uint8_t _out){

	uint8_t data[2];

	data[0] = MCP230XX_GPIOA;
	data[1] = _out;

	switch(i2cBus){
		case 1:
			HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 2, 20);
			break;
		/*case 2:
			HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 2, 20);
			break;*/
	}

	return _out;
}
