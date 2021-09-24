CROSS_COMPILE?=/root/armv7l-tizen/bin/armv7l-tizen-linux-gnueabi-

.PHONY: dvbcam
dvbcam:
	$(CROSS_COMPILE)c++ -std=c++11 -s capmt.cpp dvbcam.cpp -D'SVN_REV="9"' `pkg-config --cflags --libs glib-2.0` -L../tizen_libs_T -Wl,--unresolved-symbols=ignore-in-shared-libs -ltvs-api -lgst-ext-lib -lpvr-service-api -o dvbcam