/*
 * PCA9626.cpp
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#include "PCA9626.h"


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
