DESCRIPTION = "Manual add test files"
DEPENDS = "alsa-lib libmad"
SECTION = "libs"
LICENSE = "MIT"
PV = "3"
PR = "r0"

SRC_URI = " \
          file://wavplayer.c \
          file://mp3player.c \
          file://cardnames.c \
          file://makefile \
          "

LIC_FILES_CHKSUM = "file://wavplayer.c;beginline=4;endline=19;md5=0db63253e786edee7cb21085d350132a"
#LIC_FILES_CHKSUM = "file://mp3player.c;beginline=4;endline=19;md5=0db63253e786edee7cb21085d350132a"

S = "${WORKDIR}"
#CFLAGS+="-I/usr/include/alsa-lib"
do_compile () {
	make
}

do_install () {
	install -d ${D}${bindir}/
	install -m 0755 ${S}/wavplayer ${D}${bindir}/
	install -m 0755 ${S}/mp3player ${D}${bindir}/
	install -m 0755 ${S}/cardnames ${D}${bindir}/
}

FILES_${PN} = "${bindir}/wavplayer \
                ${bindir}/mp3player \
                ${bindir}/cardnames"
