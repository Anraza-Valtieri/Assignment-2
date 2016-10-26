##############################################################################
#
# ICT1002 Assignment 2, 2016-17 Trimester 1.
#
# You can use this file to build the BLogo interpreter using nmake (on Windows)
# or make (on Unix and MacOS X).
#
# Use the top settings for Windows and the lower settings for Unix and MacOS X.
# Use the # character to comment out whichever settings you don't want.
#
###############################################################################

#
# Windows settings
#
CC       = cl
CFLAGS   = /nologo /c /Fo:
LD       = link
LDFLAGS  = /nologo /out:
LDLIBS   = user32.lib
RM       = del
O        = .obj
X        = .exe

#
# Unix/MacOS settings.
#
#CC       = gcc
#CFLAGS   = -c -o
#LD       = gcc
#LDFLAGS  = -o 
#LDLIBS   =
#RM       = rm -f
#O        = .o
#X        =


###############################################################################
#
# Do not change anything below this line
#
###############################################################################

blogo$(X): canvas$(O) commands$(O) main$(O) program$(O) turtle$(O)
	$(LD) $(LDFLAGS)blogo$(X) canvas$(O) commands$(O) main$(O) program$(O) turtle$(O) $(LDLIBS)

canvas$(O): canvas.c blogo.h
	$(CC) $(CFLAGS) canvas$(O) canvas.c

commands$(O): commands.c blogo.h
	$(CC) $(CFLAGS) commands$(O) commands.c
	
main$(O): main.c blogo.h
	$(CC) $(CFLAGS) main$(O) main.c

program$(O): program.c blogo.h
	$(CC) $(CFLAGS) program$(O) program.c

turtle$(O): turtle.c blogo.h
	$(CC) $(CFLAGS) turtle$(O) turtle.c
	
clean:
	$(RM) *$(O)
