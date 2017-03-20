#include "htu21d.h"

/**
 * @brief 
 *
 * This function start a temperature reading from the humidity sensor with no hold master mode, meaning that
 * the data lines can be used by other devices while the measurement is conducted. 
 * To read the temperature after the measurement is done the function fetch_temperature_no_hold_master(int *temperature) need to be called
 * @return 
 */
 ret_code_t htu21d_start_temperature_no_hold_master(nrf_drv_twi_t* m_twi_master) {
    ret_code_t ret_code;
    uint8_t command_address = HTU21D_TEMPERATURE_NO_HOLD_MASTER_ADDRESS; //Address to humidity reading with no hold of twi lines
    ret_code = nrf_drv_twi_tx(m_twi_master, HTU21D_ADDRESS, &command_address, 1, false);
    return ret_code;
}

ret_code_t htu21d_fetch_temperature_no_hold_master(nrf_drv_twi_t* m_twi_master, int *temperature){
    ret_code_t ret_code;
    uint8_t returned_over_I2C[3]; //Array to hold returned data
    ret_code = nrf_drv_twi_rx(m_twi_master, HTU21D_ADDRESS, returned_over_I2C, 3); //Get raw humidity data
		//Calculate humidity: from page 15 in datasheet
		uint16_t rawTemperature = ((unsigned int) returned_over_I2C[0] << 8) | (unsigned int) returned_over_I2C[1];
		float tempTemperature =  (float)rawTemperature / (float)65536; //2^16 = 65536
		float rh = (float)-46.85 + ((float)175.72 *(float)tempTemperature); //From page 14 in datasheet
		*temperature = (int)(rh*10); // this could be change to (int)(rh*10), then one decimal of the humidity data will be kept ( 34.5  = 345 ) 
    return ret_code;
}

/**
 * @brief 
 *
 * This function start a humidity reading from the humidity sensor with no hold master mode, meaning that
 * the data lines can be used by other devices while the sensor is doing measurements. 
 * To read the humidity after measurements are done the function fetch_humidity_no_hold_master(int *humidity) need to be called
 * @return NRF_SUCCESS or the reason of failure
 */

ret_code_t htu21d_start_humidity_no_hold_master(nrf_drv_twi_t* m_twi_master) {
    ret_code_t ret_code;
    uint8_t command_address = HTU21D_HUMIDITY_NO_HOLD_MASTER_ADDRESS; //Address to humidity reading with no hold of twi lines
    ret_code = nrf_drv_twi_tx(m_twi_master, HTU21D_ADDRESS, &command_address, 1, false);
    return ret_code;
}

/**
 * @brief 
 * This function returns the humidity read by the sensor
 * @return The humidity is returned as an integer, which need to be devided by 10 to get the real humidity
 */
ret_code_t htu21d_fetch_humidity_no_hold_master(nrf_drv_twi_t* m_twi_master, int *humidity){
    ret_code_t ret_code;
    uint8_t returned_over_I2C[3]; //Array to hold returned data
    ret_code = nrf_drv_twi_rx(m_twi_master, HTU21D_ADDRESS, returned_over_I2C, 3); //Get raw humidity data   
		// nrf_delay_ms(1);
		//Calculate humidity: from page 15 in datasheet
		uint16_t rawHumidity = ((unsigned int) returned_over_I2C[0] << 8) | (unsigned int) returned_over_I2C[1];
		float tempRH = rawHumidity / (float)65536; //2^16 = 65536
		float rh = -6 + (125 * tempRH); //From page 14 in datasheet
		*humidity = (int)(rh*10); // this could be change to (int)(rh*10), then one decimal of the humidity data will be kept ( 34.5  = 345 ) 
		return ret_code;
}

ret_code_t htu21d_reset(nrf_drv_twi_t* m_twi_master) {
    ret_code_t ret_code;
    uint8_t command_address = HTU21D_SOFT_RESET; 
    ret_code = nrf_drv_twi_tx(m_twi_master, HTU21D_ADDRESS, &command_address, 1, false);
    return ret_code;
}
