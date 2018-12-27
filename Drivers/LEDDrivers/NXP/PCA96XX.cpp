/*
 * PCA96XX.cpp
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#include "PCA96XX.h"
#include <bitset>

PCA96XX::PCA96XX() {
	// TODO Auto-generated constructor stub

}

PCA96XX::~PCA96XX() {
	// TODO Auto-generated destructor stub
}

void PCA96XX::init(int _bus, uint8_t _add){
	i2cAddress = _add;
	i2cBus = _bus;

	write_register(PCA96XX_MODE1, 0x81);
	write_register(PCA96XX_MODE2, 0x05);
}

void PCA96XX::write_register(uint8_t register_pointer, uint8_t register_value){
	uint8_t data[2];

	data[0] = register_pointer;
	data[1] = register_value;

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 2, 20);
	   	break;
	case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 2, 20);
	   	break;
	}
}

void PCA96XX::set_output(){
	switch(ports){
	case 1:
		uint8_t data1[3];

		data1[0] = PCA9624_LEDOUT0;
		data1[1] = portList[0];
		data1[2] = portList[1];

		switch(i2cBus){
		case 1:
			HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data1, 3, 250);
			break;
		case 2:
			HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data1, 3, 250);
			break;
		}
		break;
	case 2:
		uint8_t data2[5];

		data2[0] = PCA9622_LEDOUT0;
		data2[1] = portList[0];
		data2[2] = portList[1];
		data2[3] = portList[2];
		data2[4] = portList[3];

		switch(i2cBus){
		case 1:
			HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data2, 5, 250);
			break;
		case 2:
			HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data2, 5, 250);
			break;
		}
		break;
	case 3:
		uint8_t data3[7];

		data3[0] = PCA9626_LEDOUT0;
		data3[1] = portList[0];
		data3[2] = portList[1];
		data3[3] = portList[2];
		data3[4] = portList[3];
		data3[5] = portList[4];
		data3[6] = portList[5];

		switch(i2cBus){
		case 1:
			HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data3, 7, 250);
			break;
		case 2:
			HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data3, 7, 250);
			break;
		}
		break;
	}
}

void PCA96XX::adjust_output(uint8_t _out[3]){

	std::bitset<8> _bits1(0x00);
	std::bitset<8> _bits2(0x00);

	for(int i = 0; i < ports; i++){
		for(int y = 0, x = 0; y < 8; y++){
			if(y < 4){
				if((_out[i] >> y)  & 0x01){
					_bits1.set(y * 2);
					_bits1.set((y * 2) + 1);
				}else{
					_bits1.reset(x);
					_bits1.reset(x + 1);
				}
			}else{
				if((_out[i] >> y)  & 0x01){
					_bits2.set(x);
					_bits2.set(x + 1);
				}else{
					_bits2.reset(x);
					_bits2.reset(x + 1);
				}

				x += 2;
			}
		}

		portList[i * 2] = (uint8_t)_bits1.to_ulong();
		portList[(i * 2) + 1] = (uint8_t)_bits2.to_ulong();
	}

	set_output();
}
