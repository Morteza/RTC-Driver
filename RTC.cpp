#include "RTC.h"

RTC::RTC()
{
    i2c = new I2CPort();
    i2c->init();
}

RTC::~RTC()
{
    delete i2c;
}

uint8_t RTC::bin2bcd(uint8_t bin)
{
    uint8_t result = (bin/10)*16 + (bin%10);
    return result;
}

uint8_t RTC::bcd2bin(uint8_t bcd)
{
    uint8_t result = (bcd/16)*10 + (bcd%16);
    return result;
}

void RTC::init()
{
    uint8_t temp= 0;
    i2c->write(&temp,RTC_REG_CONTROL1,RTC_REG_CONTROL1,1);
    i2c->write(&temp,RTC_REG_CONTROL2,RTC_I2C_ADDRESS,1);
}

void RTC::setSeconds(uint8_t sec)
{
    uint8_t temp= bin2bcd(sec);
    I2CWrite(&temp, RTC_REG_SECONDS, RTC_I2C_ADDRESS,1);
}

uint8_t RTC::getSeconds()
{
    uint8_t temp;
    I2CRead(&temp,RTC_REG_SECONDS, RTC_I2C_ADDRESS,1);
    return bcd2bin(0xFF & temp);
}

void RTC::setMinutes(uint8_t min)
{
    uint8_t temp= bin2bcd(min);
    I2CWrite(&temp, RTC_REG_MINUTES, RTC_I2C_ADDRESS,1);
}

INT8U RTC::getMinutes()
{
    uint8_t temp;
    I2CRead(&temp,RTC_REG_MINUTES, RTC_I2C_ADDRESS,1);
    return bcd2bin(0xFF & temp);
}

void RTC::setHours(uint8_t hrs)
{
    uint8_t temp= bin2bcd(hrs);
    I2CWrite(&temp, RTC_REG_HOURS, RTC_I2C_ADDRESS,1);
}

uint8_t RTC::getHours()
{
    uint8_t temp;
    I2CRead(&temp,RTC_REG_HOURS, RTC_I2C_ADDRESS,1);
    return bcd2bin(0xFF & temp);
}

void RTC::setDays(uint8_t days)
{
    uint8_t temp= bin2bcd(days);
    I2CWrite(&temp, RTC_REG_DAYS, RTC_I2C_ADDRESS,1);
}

uint8_t getDays()
{
    uint8_t temp;
    I2CRead(&temp,RTC_REG_DAYS, RTC_I2C_ADDRESS,1);
    return bcd2bin(0xFF & temp);
}

void RTC::setWeekdays(uint8_t week)
{
    uint8_t temp= bin2bcd(week);
    I2CWrite(&temp, RTC_REG_WEEKDAYS, RTC_I2C_ADDRESS,1);
}

uint8_t getWeekdays()
{
    uint8_t temp;
    I2CRead(&temp,RTC_REG_WEEKDAYS, RTC_I2C_ADDRESS,1);
    return bcd2bin(0xFF & temp);
}

void RTC::setMonths(uint8_t mnt)
{
    uint8_t temp= bin2bcd(mnt);
    I2CWrite(&temp, RTC_REG_MONTHS_CENTURY, RTC_I2C_ADDRESS,1);
}

uint8_t RTC::getMonths()
{
    uint8_t temp;
    I2CRead(&temp,RTC_REG_MONTHS_CENTURY, RTC_I2C_ADDRESS,1);
    return bcd2bin(0xFF & temp);
}

void RTC::setYears(uint8_t yrs)
{
    uint8_t temp= bin2bcd(sec);
    I2CWrite(&temp, RTC_REG_YEARS, RTC_I2C_ADDRESS,1);
}

uint8_t RTC::getYears()
{
    uint8_t temp;
    I2CRead(&temp,RTC_REG_YEARS, RTC_I2C_ADDRESS,1);
    return bcd2bin(0xFF & temp);
}
