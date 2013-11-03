showimage : showimage.c
	    gcc showimage.c -o showimage `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
splitRGB  : splitRGB.c
	    gcc splitRGB.c -o splitRGB `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
changeimagedata  : changeimagedata.c
	    g++ changeimagedata.c -o changeimagedata `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
hsvImage : hsvimage.c
		g++ hsvimage.c -o hsvImage `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
subImage : subImage.c
		gcc subImage.c -o subImage `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
addimage : addimage.c
	g++ addimage.c -o addimage `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
gamma : gamma.c
	gcc gamma.c -o gamma `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
equalizeImageLib : equalizeImageLib.c
	gcc -std=c99 equalizeImageLib.c -o equalizeImageLib `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
equalizeImage : equalizeImage.c
	g++ equalizeImage.c -o equalizeImage `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
equalizeColor : equalizeColor.c
	g++ equalizeColor.c -o equalizeColor `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
avgfilter : avgfilter.c
	g++ avgfilter.c -o avgfilter `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
mediumFilter : mediumFilter.c
	g++ mediumFilter.c -o mediumFilter `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
avgColor : avgColor.c
	g++ avgColor.c -o avgColor `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
mediumColor : mediumColor.c
	g++ mediumColor.c -o mediumColor `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
gaussianFilter : gaussianFilter.c
	g++ gaussianFilter.c -o gaussianFilter `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6
splitFinger : splitFinger.c
	g++ splitFinger.c -o splitFinger `pkg-config --cflags --libs opencv` /usr/lib/libm.so.6