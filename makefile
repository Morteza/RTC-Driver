#
# make for TI TMS570 RTC Driver Library
#

RTCDriver: RTC.o
	cxx -o RTCDriver RTC.o -lm

RTC.o: RTC.cpp
	cxx -c RTC.cpp

RTC.o: RTC.h

# end of makefile