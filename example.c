#include "svpng.inc"

void test_rgb(void) {
    unsigned char rgb[256 * 256 * 3], *p = rgb;
    unsigned x, y;
    FILE *fp = fopen("rgb.png", "wb");
    for (y = 0; y < 256; y++)
        for (x = 0; x < 256; x++) {
            *p++ = (unsigned char)x;    /* R */
            *p++ = (unsigned char)y;    /* G */
            *p++ = 128;                 /* B */
        }
    svpng(fp, 256, 256, rgb, 0);
    fclose(fp);
}

void test_rgba(void) {
    unsigned char rgba[256 * 256 * 4], *p = rgba;
    unsigned x, y;
    FILE* fp = fopen("rgba.png", "wb");
    for (y = 0; y < 256; y++)
        for (x = 0; x < 256; x++) {
            *p++ = (unsigned char)x;                /* R */
            *p++ = (unsigned char)y;                /* G */
            *p++ = 128;                             /* B */
            *p++ = (unsigned char)((x + y) / 2);    /* A */
        }
    svpng(fp, 256, 256, rgba, 1);
    fclose(fp);
}

int main(void) {
    test_rgb();
    test_rgba();
    return 0;
}
