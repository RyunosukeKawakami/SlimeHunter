#-------------------------------------------------------
# BCC Developer 1.2.21
# Copyright (C) 2003 jun_miura@hi-ho.ne.jp
#-------------------------------------------------------
.autodepend
CC=bcc32
RC=brc32
CFLAG=-W  -3 -O2 -w -AT -pc -H -k -b- -v -y  -DDEBUG
OUTDIR=-nDebug
CINCS=
TARGET=Debug\AAAAA.exe
SRC1=C:\Users\kawao\Desktop\honki\Project1\main.cpp
OBJ1=Debug\main.obj
SRC2=C:\Users\kawao\Desktop\honki\Project1\State_UI.cpp
OBJ2=Debug\State_UI.obj
SRC3=C:\Users\kawao\Desktop\honki\Project1\Score.cpp
OBJ3=Debug\Score.obj
SRC4=C:\Users\kawao\Desktop\honki\Project1\Player.cpp
OBJ4=Debug\Player.obj
SRC5=C:\Users\kawao\Desktop\honki\Project1\Life.cpp
OBJ5=Debug\Life.obj
SRC6=C:\Users\kawao\Desktop\honki\Project1\Hitpoint.cpp
OBJ6=Debug\Hitpoint.obj
SRC7=C:\Users\kawao\Desktop\honki\Project1\Debug.cpp
OBJ7=Debug\Debug.obj
SRC8=C:\Users\kawao\Desktop\honki\Project1\Char.cpp
OBJ8=Debug\Char.obj
SRC9=C:\Users\kawao\Desktop\honki\Project1\Box.cpp
OBJ9=Debug\Box.obj
SRC10=C:\Users\kawao\Desktop\honki\Project1\World.cpp
OBJ10=Debug\World.obj

TARGET: $(TARGET)

$(TARGET): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10)
    $(CC) $(CFLAG) -e$(TARGET) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10)

$(OBJ1): $(SRC1)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC1)

$(OBJ2): $(SRC2)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC2)

$(OBJ3): $(SRC3)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC3)

$(OBJ4): $(SRC4)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC4)

$(OBJ5): $(SRC5)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC5)

$(OBJ6): $(SRC6)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC6)

$(OBJ7): $(SRC7)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC7)

$(OBJ8): $(SRC8)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC8)

$(OBJ9): $(SRC9)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC9)

$(OBJ10): $(SRC10)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC10)
