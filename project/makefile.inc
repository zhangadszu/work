
PATH_PROJ_ROOT=$(shell dirname $(WORK_TEST_BASE)/$(shell basename $(WORK_TEST_BASE)))

INC_OPENCV = -I$(PATH_PROJ_ROOT)/public/opencv/include
LIB_OPENCV_3RDPARTY = -L$(PATH_PROJ_ROOT)/public/opencv/lib -ljpeg -lIlmImf -llibjasper -lpng -llibtiff 
LIB_OPENCV = -lopencv_highgui -lopencv_objdetect -lopencv_imgproc -lopencv_core $(LIB_OPENCV_3RDPARTY)

