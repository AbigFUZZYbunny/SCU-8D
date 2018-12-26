/*
 * PCA9626.cpp
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#include "PCA9626.h"
#include <bitset>

PCA9626::PCA9626() {
	// TODO Auto-generated constructor stub

}

PCA9626::~PCA9626() {
	// TODO Auto-generated destructor stub
}

void PCA9626::begin(uint8_t _pwm[24]){
	//this can set individual brightness control from pc software setup
	//The LED PWM addresses should be set with autoincrement which allows the following Transmit
	ports = 3;
	uint8_t data[25];
	data[0] = PCA9626_PWM0;

	for(int i = 1; i <= 24; i++){
		int x = (i - 1);
		data[i] = _pwm[x];
	}

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 25, 250);
	   	break;
	case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 25, 250);
	   	break;
	}

	dim(0xFF);
}

void PCA9626::begin(){
	ports = 3;
	uint8_t data[25];
	data[0] = PCA9626_PWM0;

	for(int i = 1; i <= 24; i++){
		data[i] = 0xFF;
	}

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 25, 250);
	   	break;
	case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 25, 250);
	   	break;
	}

	dim(0xFF);
}

void PCA9626::dim(uint8_t _grppwm){
	//this can dim all leds based on a light sensor input
	write_register(PCA9626_GRPPWM, _grppwm);
}

void PCA9626::set_output(){

	uint8_t data[7];

	data[0] = PCA9626_LEDOUT0;
	data[1] = portList[0];
	data[2] = portList[1];
	data[3] = portList[2];
	data[4] = portList[3];
	data[5] = portList[4];
	data[6] = portList[5];

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 7, 250);
	   	break;
	case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 7, 250);
	   	break;
	}
}

void PCA9626::adjust_output(uint8_t _out, int _port){

	switch(_port){
	case 1:
		_port = 0;
		break;
	case 3:
		_port = 2;
		break;
	case 5:
		_port = 4;
		break;
	}

	std::bitset<8> _bits1(0x00);
	std::bitset<8> _bits2(0x00);

	for(int i = 0, x = 0; i < 8; i++, x += 2){
		if(i < 4){
			if((_out >> i)  & 0x01){
				_bits1.set(i);
				_bits1.set(i + 1);
			}else{
				_bits1.reset(i);
				_bits1.reset(i + 1);
			}
		}else{
			if((_out >> i)  & 0x01){
				_bits2.set(i);
				_bits2.set(i + 1);
			}else{
				_bits2.reset(i);
				_bits2.reset(i + 1);
			}
		}

		x += 2;
	}

	portList[_port] = (uint8_t)_bits1.to_ulong();
	portList[_port + 1] = (uint8_t)_bits2.to_ulong();
}
