gcc `pkg-config --cflags gtk4` $1.c `pkg-config --libs gtk4` -o $1
./$1
