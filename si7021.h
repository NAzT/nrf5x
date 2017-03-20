#ifndef SI7021_H
#define SI7021_H

#include "nrf_drv_twi.h"

#define SI7021_ADDRESS         					 0x40

#define SI7021_MEASRH_HOLD_CMD           0xE5
#define SI7021_MEASRH_NOHOLD_CMD         0xF5
#define SI7021_MEASTEMP_HOLD_CMD         0xE3
#define SI7021_MEASTEMP_NOHOLD_CMD       0xF3
#define SI7021_READPREVTEMP_CMD          0xE0 // cuando se mid RH siempre se mide Temp, con este comando se lee la temp previamente medida en el comandp de RH
#define SI7021_RESET_CMD                 0xFE
#define SI7021_WRITERHT_REG_CMD          0xE6
#define SI7021_READRHT_REG_CMD           0xE7
#define SI7021_WRITEHEATER_REG_CMD       0x51
#define SI7021_READHEATER_REG_CMD        0x11
#define SI7021_ID1_CMD                   0xFA0F
#define SI7021_ID2_CMD                   0xFCC9
#define SI7021_FIRMVERS_CMD              0x84B8

ret_code_t si7021_start_temperature_no_hold_master(nrf_drv_twi_t* m_twi_master);
ret_code_t si7021_fetch_temperature_no_hold_master(nrf_drv_twi_t* m_twi_master, float *temperature);
ret_code_t si7021_start_humidity_no_hold_master(nrf_drv_twi_t* m_twi_master);
ret_code_t si7021_fetch_humidity_no_hold_master(nrf_drv_twi_t* m_twi_master, int *humidity);
ret_code_t si7021_reset(nrf_drv_twi_t* m_twi_master) ;

#endif
