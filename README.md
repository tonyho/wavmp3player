wavmp3player
============

MP3 player and wav player based on libmad, for yocto

##Intructions:
1. Place the manumal.bb and manumal directory to the meta-XXX/recipe-YYY
2. In yocto `build` diretory, source the environment `source poky/oe-XXXXX`
3. Using the hob to edit the image configration, add the `libmad` for the mp3player 
4. bitbake the bb file to build the manumaltest: `bitbake -b <path to the>manualtest.bb -v`
5. If mp3player/wavplayer does not exist in rootfs, copy them form the `{BUILD_OUT}/usr/bin/` to `rootfs/bin`

The source code comes from [Source code](http://blog.chinaunix.net/uid/27106528.html)
