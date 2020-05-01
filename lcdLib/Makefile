all: libLcd.a lcddemo.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h 
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib 
#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o 
	$(AR) crs $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h
led.o: led.c led.h 
song.s: song.h song.c
buzzer.o: buzzer.c buzzer.h
toyMain.o: buzzer.h lcddraw.c lcddraw.h lcdutils.h
wdInterruptHandler.o: stateMachines.h
stateMachines.o: led.h  stateMachines.h song.h 
shapes.o: shapes.c shapes.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f libLcd.a *.o *.elf

lcddemo.elf: lcddemo.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

lcdx.elf: lcdx.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer
lcdshape.elf: lcdshape.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer
lcdtoy.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o song.s led.o switches.o buzzer.o wdInterruptHandler.o stateMachines.o toyMain.o shapes.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer

load: lcddemo.elfx
	msp430loader.sh $^
loadx: lcdx.elf
	msp430loader.sh $^
loadshape: lcdshape.elf
	msp430loader.sh $^
loadtoy: lcdtoy.elf
	msp430loader.sh $^
