#ifndef RTC_H
#define RTC_H

#include "I2CPort.h"

// rtc module slave address definition
#define RTC_I2C_ADDRESS 0xA2

// register address definitions

#define RTC_REG_CONTROL1			0x00
#define RTC_REG_CONTROL2			0x01
#define RTC_REG_SECONDS				0x02
#define RTC_REG_MINUTES				0x03
#define RTC_REG_HOURS				0x04
#define RTC_REG_DAYS				0x05
#define RTC_REG_WEEKDAYS			0x06
#define RTC_REG_MONTHS_CENTURY		0x07
#define RTC_REG_YEARS				0x08
#define RTC_REG_MINUTE_ALARM		0x09
#define RTC_REG_HOUR_ALARM			0x0A
#define RTC_REG_DAY_ALARM			0x0B
#define RTC_REG_WEEKDAY_ALARM		0x0C
#define RTC_REG_CLKOUT_FREQUENCY	0x0D
#define RTC_REG_TIMER_CONTROL		0x0E
#define RTC_REG_TIMER				0x0F

// register bit definitions

#define RTC_STOP_BIT		0x20
#define RTC_TITP_BIT		0x10
#define RTC_AF_BIT			0x08
#define RTC_TF_BIT			0x04
#define RTC_AIE_BIT			0x02
#define RTC_TIE_BIT			0x01
#define RTC_VL_BIT			0x80
#define RTC_C_BIT			0x80
#define RTC_AE_BIT			0x80
#define RTC_FE_BIT			0x80
#define RTC_FD1_BIT			0x02
#define RTC_FD0_BIT			0x01
#define RTC_TE_BIT			0x80
#define RTC_TD1_BIT			0x02
#define RTC_TD0_BIT			0x01

class RTC
{
public:
    RTC();
    ~RTC();

    uint8_t bin2bcd(uint8_t bin);
    uint8_t bcd2bin(uint8_t bcd);

    void init();

    void setSeconds(uint8_t sec);
    uint8_t getSeconds();

    void setMinutes(uint8_t min);
    INT8U getMinutes();

    void setHours(uint8_t hrs);
    uint8_t getHours();

    void setDays(uint8_t days);
    uint8_t getDays();

    void setWeekdays(uint8_t week);
    uint8_t getWeekdays();

    void setMonths(uint8_t mnt);
    uint8_t getMonths();

    void setYears(uint8_t yrs);
    uint8_t getYears();

private:
    I2CPort *i2c;
};

#endif // RTC_H
