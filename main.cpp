
#include <iostream>
using namespace std;
void BGRAtoYUV422(unsigned char* pBGRA, unsigned char* pYUV, int width, int height)
{
    int i, j;
    int r, g, b, a;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i += 2) {
            int A1, A2, Y1, U1, V1, U2, V2, Y2, U, V; //stored as u y1 v y2
            b = pBGRA[(i + j * width) * 4];
            g = pBGRA[(i + j * width) * 4 + 1];
            r = pBGRA[(i + j * width) * 4 + 2];
            
            Y1 = 0.299 * r + 0.587 * g + 0.114 * b;
            U1 = -0.169 * r - 0.331 * g + 0.500 * b + 128;
            V1 = 0.500 * r - 0.419 * g - 0.081 * b + 128;
           
            if (Y1 < 0) { Y1 = 0; }
            else if (Y1 > 255) { Y1 = 255; }
            if (U1 < 0) { U1 = 0; }
            else if (U1 > 255) { U1 = 255; }
            if (V1 < 0) { V1 = 0; }
            else if (V1 > 255) { V1 = 255; }
            
            b = pBGRA[(i + 1 + j * width) *4 ];
            g = pBGRA[(i + 1 + j * width) *4  + 1];
            r = pBGRA[(i + 1 + j * width) *4 + 2];
           
            Y2 = 0.299 * r + 0.587 * g + 0.114 * b;
            U2 = -0.169 * r - 0.331 * g + 0.500 * b + 128;
            V2 = 0.500 * r - 0.419 * g - 0.081 * b + 128;
           
            if (Y2 < 0) { Y2 = 0; }
            else if (Y2 > 255) { Y2 = 255; }
            if (U2 < 0) { U2 = 0; }
            else if (U2 > 255) { U2 = 255; }
            if (V2 < 0) { V2 = 0; }
            else if (V2 > 255) { V2 = 255; }
           
            //u y1 v y2
            U = (U1 + U2) / 2;
            V = (V1 + V2) / 2;

            pYUV[(i + j * width) * 2 + 0] = U;
            pYUV[(i + j * width) * 2 + 1] = Y1;
            pYUV[(i + j * width) * 2 + 2] = V;
            pYUV[(i + j * width) * 2 + 3] = Y2;

            pYUV[(i + j * width) + 0] = Y1;
            pYUV[(i + j * width) + 1] = Y2;
            pYUV[width * height + (i / 2 + j * width / 2)] = U;
            pYUV[3 * width * height / 2 + (i / 2 + j * width / 2)] = V;
        }
    }
}

void BGRAtoYUVA22(unsigned char* pBGRA, unsigned char* pYUV, int height, int width)
{
    int i, j;
    int r, g, b, a;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i += 2) {
            int A1, A2, Y1, U1, V1, U2, V2, Y2, U, V; //stored as u y1 v y2
            b = pBGRA[(i + j * width) * 4];
            g = pBGRA[(i + j * width) * 4 + 1];
            r = pBGRA[(i + j * width) * 4 + 2];
            a = pBGRA[(i + j * width) * 4 + 3];

            Y1 = 0.299 * r + 0.587 * g + 0.114 * b;
            U1 = -0.169 * r - 0.331 * g + 0.500 * b + 128;
            V1 = 0.500 * r - 0.419 * g - 0.081 * b + 128;
            A1 = a;
            if (Y1 < 0) { Y1 = 0; }
            else if (Y1 > 255) { Y1 = 255; }
            if (U1 < 0) { U1 = 0; }
            else if (U1 > 255) { U1 = 255; }
            if (V1 < 0) { V1 = 0; }
            else if (V1 > 255) { V1 = 255; }
            if (A1 < 0) { A1 = 0; }
            else if (A1 > 255) { A1 = 255; }

            b = pBGRA[(i + 1 + j * width) * 4];
            g = pBGRA[(i + 1 + j * width) * 4 + 1];
            r = pBGRA[(i + 1 + j * width) * 4 + 2];
            a = pBGRA[(i + 1 + j * width) * 4 + 3];

            Y2 = 0.299 * r + 0.587 * g + 0.114 * b;
            U2 = -0.169 * r - 0.331 * g + 0.500 * b + 128;
            V2 = 0.500 * r - 0.419 * g - 0.081 * b + 128;
            A2 = a;
            if (Y2 < 0) { Y2 = 0; }
            else if (Y2 > 255) { Y2 = 255; }
            if (U2 < 0) { U2 = 0; }
            else if (U2 > 255) { U2 = 255; }
            if (V2 < 0) { V2 = 0; }
            else if (V2 > 255) { V2 = 255; }
            if (A2 < 0) { A2 = 0; }
            else if (A2 > 255) { A2 = 255; }

            //u y1 v y2
            U = (U1 + U2) / 2;
            V = (V1 + V2) / 2;

            pYUV[(i + j * width) + 0] = Y1;
            pYUV[(i + j * width) + 1] = Y2;
            pYUV[width * height + (i / 2 + j * width / 2)] = U;
            pYUV[3 * width * height / 2 + (i / 2 + j * width / 2)] = V;
            pYUV[width * height * 2 + (i + j * width) + 0] = A1;
            pYUV[width * height * 2 + (i + j * width) + 1] = A2;
        }
    }
}


void BGRAtoYUV444Dump(unsigned char* pBGRA, unsigned char* pYUV, int width, int height)
{
    int i, j;
    int r, g, b, a;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i += 1) {
            int A1, A2, Y1, U1, V1, U2, V2, Y2, U, V; //stored as u y1 v y2
            b = pBGRA[(i + j * width) * 4];
            g = pBGRA[(i + j * width) * 4 + 1];
            r = pBGRA[(i + j * width) * 4 + 2];

            Y1 = 0.299 * r + 0.587 * g + 0.114 * b;
            U1 = -0.169 * r - 0.331 * g + 0.500 * b + 128;
            V1 = 0.500 * r - 0.419 * g - 0.081 * b + 128;
            
            if (Y1 < 0) { Y1 = 0; }
            else if (Y1 > 255) { Y1 = 255; }
            if (U1 < 0) { U1 = 0; }
            else if (U1 > 255) { U1 = 255; }
            if (V1 < 0) { V1 = 0; }
            else if (V1 > 255) { V1 = 255; }

            pYUV[(i + j * width)] = Y1;
            pYUV[(width * height) + (i + j * width)] = U1;
            pYUV[((width * height) * 2) + (i + j * width)] = V1;
        }
    }
}

void BGRAtoYUVA444Dump(unsigned char* pBGRA, unsigned char* pYUV, int width, int height)
{
    int i, j;
    int r, g, b, a;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i += 1) {
            int A1, A2, Y1, U1, V1, U2, V2, Y2, U, V; //stored as u y1 v y2
            b = pBGRA[(i + j * width) * 4];
            g = pBGRA[(i + j * width) * 4 + 1];
            r = pBGRA[(i + j * width) * 4 + 2];
            a = pBGRA[(i + j * width) * 4 + 3];

            Y1 = 0.299 * r + 0.587 * g + 0.114 * b;
            U1 = -0.169 * r - 0.331 * g + 0.500 * b + 128;
            V1 = 0.500 * r - 0.419 * g - 0.081 * b + 128;
            A1 = a;

            if (Y1 < 0) { Y1 = 0; }
            else if (Y1 > 255) { Y1 = 255; }
            if (U1 < 0) { U1 = 0; }
            else if (U1 > 255) { U1 = 255; }
            if (V1 < 0) { V1 = 0; }
            else if (V1 > 255) { V1 = 255; }
            if (A1 < 0) { A1 = 0; }
            else if (A1 > 255) { A1 = 255; }

            int size = width * height;
            pYUV[(i + j * width)] = Y1;
            pYUV[size + (i + j * width)] = U1;
            pYUV[(size * 2) + (i + j * width)] = V1;
            pYUV[(size * 3) + (i + j * width)] = A1;
        }
    }
}

void YUV444TOYUV420(unsigned char* inbuf, unsigned char* outbuf, int w, int h) {
    unsigned char* srcY = NULL, * srcU = NULL, * srcV = NULL;
    unsigned char* desY = NULL, * desU = NULL, * desV = NULL;
    srcY = inbuf;//Y
    srcU = srcY + w * h;//U
    srcV = srcU + w * h;//V

    desY = outbuf;
    desU = desY + w * h;
    desV = desU + w * h / 4;

    int half_width = w / 2;
    int half_height = h / 2;
    memcpy(desY, srcY, w * h * sizeof(unsigned char));//Y Copy the components directly 
     //UV
    for (int i = 0; i < half_height; i++) {
        for (int j = 0; j < half_width; j++) {
            *desU = *srcU;
            *desV = *srcV;
            desU++;
            desV++;
            srcU += 2;
            srcV += 2;
        }
        srcU = srcU + w;
        srcV = srcV + w;
    }
}

void YUV444TOYUV422(unsigned char* inbuf, unsigned char* outbuf, int w, int h) {
    unsigned char* srcY = NULL, * srcU = NULL, * srcV = NULL;
    unsigned char* desY = NULL, * desU = NULL, * desV = NULL;
    srcY = inbuf;//Y
    srcU = srcY + w * h;//U
    srcV = srcU + w * h;//V

    desY = outbuf;
    desU = desY + w * h;
    desV = desU + w * h / 2;

    int half_width = w / 2;
    int half_height = h / 2;
    memcpy(desY, srcY, w * h * sizeof(unsigned char));//Y Copy the components directly 
     //UV
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < half_width; j++) {
            *desU = *srcU;
            desU++;

            *desV = *srcV;
            desV++;
            
            srcU +=2;
            srcV +=2;
        }
    }
}


void ReadYUV444nConvertYUV420() {
    int height{ 1080 };
    int width{ 1920 };
    FILE* fp;
    fopen_s(&fp, "yuv444_1920x1080.yuv", "rb");
    int size = height * width * 4;
    unsigned char* pBGRA = new unsigned char[size];
    fread(pBGRA, 1, size, fp);
    fclose(fp);

    unsigned char* pYUV = new unsigned char[(width * height * 3) / 2];
    YUV444TOYUV420(pBGRA, pYUV, width, height);
    fopen_s(&fp, "yuv420_1920x1080.yuv", "wb");
    fwrite(pYUV, 1, (width * height * 3) / 2, fp);
    fclose(fp);
}

void ReadYUV444nConvertYUV422() {
    int height{ 1080 };
    int width{ 1920 };
    FILE* fp;
    fopen_s(&fp, "yuv444_1920x1080.yuv", "rb");
    int size = height * width * 4;
    unsigned char* pBGRA = new unsigned char[size];
    fread(pBGRA, 1, size, fp);
    fclose(fp);

    int ysize = (width * height);
    int usize = ysize / 2;
    int vsize = usize;
    unsigned char* pYUV = new unsigned char[ysize + usize + vsize];
    YUV444TOYUV422(pBGRA, pYUV, width, height);
    fopen_s(&fp, "yuv422_1920x1080.yuv", "wb");
    fwrite(pYUV, 1, (ysize + usize + vsize), fp);
    fclose(fp);
}

void ReadBGRAnConvertYUV422() {
    int height{ 1080 };
    int width{ 1920 };
    FILE* fp;
    fopen_s(&fp, "1920x1080.rgb", "rb");
    int size = height * width * 4;
    unsigned char* pBGRA = new unsigned char[size];
    fread(pBGRA, 1, size, fp);
    fclose(fp);

    int ysize = (width * height);
    int usize = ysize / 2;
    int vsize = usize;
    unsigned char* pYUV = new unsigned char[ysize + usize + vsize];
    BGRAtoYUV422(pBGRA, pYUV, width, height);
    fopen_s(&fp, "yuv422_1920x1080.yuv", "wb");
    fwrite(pYUV, 1, (ysize + usize + vsize), fp);
    fclose(fp);
}

void ReadBGRAnConvertYUVA422() {
    int height{ 1080 };
    int width{ 1920 };
    FILE* fp;
    fopen_s(&fp, "1920x1080.rgb", "rb");
    int size = height * width * 4;
    unsigned char* pBGRA = new unsigned char[size];
    fread(pBGRA, 1, size, fp);
    fclose(fp);

    int ysize = (width * height);
    int usize = ysize / 2;
    int vsize = usize;
    int asize = ysize;

    unsigned char* pYUV = new unsigned char[ysize + usize + vsize + asize];
    BGRAtoYUVA22(pBGRA, pYUV, width, height);
    fopen_s(&fp, "yuv422a_1920x1080.yuv", "wb");
    fwrite(pYUV, 1, (ysize + usize + vsize + asize), fp);
    fclose(fp);
}

void ReadBGRAnDumpInYUV444() {
    int height{ 1080 };
    int width{ 1920 };

    FILE* fp;
    fopen_s(&fp, "1920x1080.rgb", "rb");
    int size = height * width * 4;
    unsigned char* pBGRA = new unsigned char[size];
    fread(pBGRA, 1, size, fp);
    fclose(fp);


    int yuvsize = (width * height) * 3;
    unsigned char* pYUV = new unsigned char[yuvsize];
    BGRAtoYUV444Dump(pBGRA, pYUV, width, height);
    fopen_s(&fp, "yuv444_1920x1080.yuv", "wb");
    fwrite(pYUV, 1, yuvsize, fp);
    fclose(fp);
}

void ReadBGRAnDumpInYUVA444() {
    int height{ 1080 };
    int width{ 1920 };

    FILE* fp;
    fopen_s(&fp, "1920x1080.rgb", "rb");
    int size = height * width * 4;
    unsigned char* pBGRA = new unsigned char[size];
    fread(pBGRA, 1, size, fp);
    fclose(fp);


    int yuvsize = (width * height) * 4;
    unsigned char* pYUV = new unsigned char[yuvsize];
    BGRAtoYUV444Dump(pBGRA, pYUV, width, height);
    fopen_s(&fp, "yuv444a_1920x1080.yuv", "wb");
    fwrite(pYUV, 1, yuvsize, fp);
    fclose(fp);
}

int main() {
    ReadBGRAnDumpInYUV444();
    //exit(0);
    ReadBGRAnDumpInYUVA444();
    //exit(0);
    ReadBGRAnConvertYUV422();   
    //exit(0);
    ReadBGRAnConvertYUVA422();
    //exit(0);
    ReadYUV444nConvertYUV422(); 
    //exit(0);
    ReadYUV444nConvertYUV420(); 
}