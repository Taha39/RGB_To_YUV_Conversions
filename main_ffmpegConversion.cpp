
extern "C"
{
#include "libavutil/imgutils.h"
#include "libavutil/parseutils.h"
#include "libswscale/swscale.h"
}


void convert_file(uint8_t* src_buff, enum AVPixelFormat src_pix_fmt, uint8_t* dest_buff, enum AVPixelFormat dst_pix_fmt, int width, int height) {
    uint8_t* src_data[4], * dst_data[4];
    int src_linesize[4], dst_linesize[4];
    int src_w = width, src_h = height, dst_w = width, dst_h = height;

    const char* dst_size = NULL;
    int dst_bufsize;
    struct SwsContext* sws_ctx;
    int i, ret;


    sws_ctx = sws_getContext(src_w, src_h, src_pix_fmt,
        dst_w, dst_h, dst_pix_fmt,
        SWS_BILINEAR, NULL, NULL, NULL);
    if (!sws_ctx) {
        fprintf(stderr,
            "Impossible to create scale context for the conversion "
            "fmt:%s s:%dx%d -> fmt:%s s:%dx%d\n",
            av_get_pix_fmt_name(src_pix_fmt), src_w, src_h,
            av_get_pix_fmt_name(dst_pix_fmt), dst_w, dst_h);
        ret = AVERROR(EINVAL);
    }

    if ((ret = av_image_alloc(src_data, src_linesize,
        src_w, src_h, src_pix_fmt, 16)) < 0) {
        fprintf(stderr, "Could not allocate source image\n");
    } 

    if ((ret = av_image_alloc(dst_data, dst_linesize,
        dst_w, dst_h, dst_pix_fmt, 1)) < 0) {
        fprintf(stderr, "Could not allocate destination image\n");
    }
    dst_bufsize = ret;    
    src_data[0] = src_buff;

    sws_scale(sws_ctx, (const uint8_t* const*)src_data,
        src_linesize, 0, src_h, dst_data, dst_linesize);

    memcpy(dest_buff, dst_data[0], dst_bufsize);
}

int main() {
    int height{ 1080 };
    int width{ 1920 };
    FILE* fp;
    fopen_s(&fp, "1920x1080.rgb", "rb");
    int size = height * width * 4;
    unsigned char* pBGRA = new unsigned char[size];
    fread(pBGRA, 1, size, fp);
    fclose(fp);

    unsigned char* dest_buff = new unsigned char[(width * height * 3) / 2 + (width * height)];
    convert_file(pBGRA, AV_PIX_FMT_RGBA, dest_buff, AV_PIX_FMT_YUVA420P, width, height);
    fopen_s(&fp, "1920x1080_.yuv", "wb");
    fwrite(dest_buff, 1, (width * height * 3) / 2 + (1920 * height), fp);
    fclose(fp);
}
