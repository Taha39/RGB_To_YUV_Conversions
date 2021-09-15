This small project includes One main.cpp file which will perform all the conversion and some raw files like: BGRA, YUVA444, YUV422, YUV420 etc.

Conversion funciton used in main.cpp are:
1- ReadBGRAnDumpInYUV444():  This function reads data from rgba file and perform yuv444 conversion and dump result in a yuv444 file.

2- ReadBGRAnDumpInYUVA444(): This function reads data from rgba file and perform yuva444 conversion and dump result in a yuva444 file.
    
3- ReadBGRAnConvertYUV422(): This function reads data from rgba file and perform yuv422 conversion and dump result in a yuv422 file.   
    
4- ReadBGRAnConvertYUVA422(): This function reads data from rgba file and perform yuva422 conversion and dump result in a yuva422 file.
    
5- ReadYUV444nConvertYUV422(): This function reads data from yuv444 file and perform yuv422 conversion and dump result in a yuv422 file.
    
6- ReadYUV444nConvertYUV420(): This function reads data from yuv444 file and perform yuv420 conversion and dump result in a yuv420 file.