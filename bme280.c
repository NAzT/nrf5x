#include "bme280.h"

bme280_calibration_t bme280_calibration;

ret_code_t bme280_begin(nrf_drv_twi_t* m_twi_master) {
    ret_code_t ret_code;
		
		bme280_calibration.dig_T1 = ((uint16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_T1_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_T1_LSB_REG)));
		bme280_calibration.dig_T2 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_T2_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_T2_LSB_REG)));
		bme280_calibration.dig_T3 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_T3_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_T3_LSB_REG)));

		bme280_calibration.dig_P1 = ((uint16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_P1_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_P1_LSB_REG)));
		bme280_calibration.dig_P2 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_P2_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_P2_LSB_REG)));
		bme280_calibration.dig_P3 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_P3_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_P3_LSB_REG)));
		bme280_calibration.dig_P4 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_P4_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_P4_LSB_REG)));
		bme280_calibration.dig_P5 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_P5_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_P5_LSB_REG)));
		bme280_calibration.dig_P6 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_P6_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_P6_LSB_REG)));
		bme280_calibration.dig_P7 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_P7_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_P7_LSB_REG)));
		bme280_calibration.dig_P8 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_P8_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_P8_LSB_REG)));
		bme280_calibration.dig_P9 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_P9_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_P9_LSB_REG)));

		bme280_calibration.dig_H1 = ((uint8_t)(bme280_read_blocking_register(m_twi_master,BME280_DIG_H1_REG)));
		bme280_calibration.dig_H2 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_H2_MSB_REG) << 8) + bme280_read_blocking_register(m_twi_master,BME280_DIG_H2_LSB_REG)));
		bme280_calibration.dig_H3 = ((uint8_t)(bme280_read_blocking_register(m_twi_master,BME280_DIG_H3_REG)));
		bme280_calibration.dig_H4 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_H4_MSB_REG) << 4) + (bme280_read_blocking_register(m_twi_master,BME280_DIG_H4_LSB_REG) & 0x0F)));
		bme280_calibration.dig_H5 = ((int16_t)((bme280_read_blocking_register(m_twi_master,BME280_DIG_H5_MSB_REG) << 4) + ((bme280_read_blocking_register(m_twi_master,BME280_DIG_H4_LSB_REG) >> 4) & 0x0F)));
		bme280_calibration.dig_H6 = ((uint8_t)bme280_read_blocking_register(m_twi_master,BME280_DIG_H6_REG));
		
//		//Set the oversampling control words.
//	//config will only be writeable in sleep mode, so first insure that.
  	writeRegister(BME280_CTRL_MEAS_REG, 0x00);
//	
//	//Set the config word
//	dataToWrite = (settings.tStandby << 0x5) & 0xE0;
//	dataToWrite |= (settings.filter << 0x02) & 0x1C;
//	writeRegister(BME280_CONFIG_REG, dataToWrite);
//	
//	//Set ctrl_hum first, then ctrl_meas to activate ctrl_hum
//	dataToWrite = settings.humidOverSample & 0x07; //all other bits can be ignored
//	writeRegister(BME280_CTRL_HUMIDITY_REG, dataToWrite);
//	
//	//set ctrl_meas
//	//First, set temp oversampling
//	dataToWrite = (settings.tempOverSample << 0x5) & 0xE0;
//	//Next, pressure oversampling
//	dataToWrite |= (settings.pressOverSample << 0x02) & 0x1C;
//	//Last, set mode
//	dataToWrite |= (settings.runMode) & 0x03;
//	//Load the byte
//	writeRegister(BME280_CTRL_MEAS_REG, dataToWrite);
    return ret_code;
}


ret_code_t bme280_write_register(nrf_drv_twi_t* m_twi_master, uint8_t cmd_addr, uint8_t value) {
    ret_code_t ret_code;
    ret_code = nrf_drv_twi_tx(m_twi_master, BME280_ADDRES, &cmd_addr, 1, true);
		ret_code = nrf_drv_twi_tx(m_twi_master, BME280_ADDRES, &cmd_addr, 1, true);
    return ret_code;
}


uint8_t bme280_read_blocking_register(nrf_drv_twi_t* m_twi_master, uint8_t cmd_addr) {
    ret_code_t ret_code;
		uint8_t returned_over_I2C[1];
	
    ret_code = nrf_drv_twi_tx(m_twi_master, BME280_ADDRES, &cmd_addr, 1, false);
		while (NRF_DRV_TWI_EVT_DONE)
       {
           //break;
       }
		ret_code = nrf_drv_twi_rx(m_twi_master, BME280_ADDRES, returned_over_I2C, 1);	 
    return returned_over_I2C[0];
}

ret_code_t bme280_start_humidity(nrf_drv_twi_t* m_twi_master, uint8_t cmd_addr) {

	ret_code_t ret_code;
	//uint8_t command_address = SI7021_MEASRH_NOHOLD_CMD; //Address to humidity reading with no hold of twi lines
	ret_code = nrf_drv_twi_tx(m_twi_master, BME280_ADDRES, &command_address, 1, false);
	return ret_code;

}

ret_code_t bme280_fetch_humidity(nrf_drv_twi_t* m_twi_master, uint8_t cmd_addr) {

	
	// Returns humidity in %RH as unsigned 32 bit integer in Q22. 10 format (22 integer and 10 fractional bits).
	// Output value of “47445” represents 47445/1024 = 46. 333 %RH
	int32_t adc_H = ((uint32_t)readRegister(BME280_HUMIDITY_MSB_REG) << 8) | ((uint32_t)readRegister(BME280_HUMIDITY_LSB_REG));
	
	int32_t var1;
	var1 = (t_fine - ((int32_t)76800));
	var1 = (((((adc_H << 14) - (((int32_t)calibration.dig_H4) << 20) - (((int32_t)calibration.dig_H5) * var1)) +
	((int32_t)16384)) >> 15) * (((((((var1 * ((int32_t)calibration.dig_H6)) >> 10) * (((var1 * ((int32_t)calibration.dig_H3)) >> 11) + ((int32_t)32768))) >> 10) + ((int32_t)2097152)) *
	((int32_t)calibration.dig_H2) + 8192) >> 14));
	var1 = (var1 - (((((var1 >> 15) * (var1 >> 15)) >> 7) * ((int32_t)calibration.dig_H1)) >> 4));
	var1 = (var1 < 0 ? 0 : var1);
	var1 = (var1 > 419430400 ? 419430400 : var1);

	return (float)(var1>>12) / 1024.0;

}
