#ifndef HTU21D_H
#define HTU21D_H

/*
 En ppio las librerias van a ser escritas en modo bloqueante. Si no se define 
 un event handler en la inicializacion del TWI driver las funciones de tx y rx son bloqueantes
*/
#include "nrf_drv_twi.h"

#define HTU21D_ADDRESS 0x40
#define HTU21D_HUMIDITY_NO_HOLD_MASTER_ADDRESS 0xF5
#define HTU21D_TEMPERATURE_NO_HOLD_MASTER_ADDRESS 0xF3
#define HTU21D_WRITE_USER_REGISTER 0xE6
#define HTU21D_READ_USER_REGISTER 0xE7
#define HTU21D_SOFT_RESET 0xFE


ret_code_t htu21d_fetch_temperature_no_hold_master(nrf_drv_twi_t* m_twi_master, int *temperature);
ret_code_t htu21d_start_temperature_no_hold_master(nrf_drv_twi_t* m_twi_master);
ret_code_t htu21d_start_humidity_no_hold_master(nrf_drv_twi_t* m_twi_master) ;
ret_code_t htu21d_fetch_humidity_no_hold_master(nrf_drv_twi_t* m_twi_master, int *humidity);
ret_code_t htu21d_reset(nrf_drv_twi_t* m_twi_master);


#endif
 
