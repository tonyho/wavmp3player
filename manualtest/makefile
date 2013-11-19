TARGET=wavplayer mp3player cardnames

#CFLAGS=-D_REENTRANT  -I$(PKG_CONFIG_SYSROOT_DIR)/usr/include/alsa-lib
LDFLAGS= -lasound

#CFLAGS1=-D_REENTRANT  -I$(PKG_CONFIG_SYSROOT_DIR)/usr/include/libmad
LDFLAGS1= -lasound -lmad

all: $(TARGET)

wavplayer: wavplayer.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

mp3player: mp3player.o
	$(CC) $(CFLAGS1) -o $@ $^ $(LDFLAGS1)

cardnames: cardnames.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	rm -f $(OBJS) $(TARGET)
