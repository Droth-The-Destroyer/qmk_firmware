#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_FROG1
#define LV_ATTRIBUTE_IMG_FROG1
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_FROG1 uint8_t frog1_map[] = {
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 
    0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x66, 0x08, 0x02, 
    0x00, 0x00, 0x00, 0x91, 0x13, 0xf2, 0xdd, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 
    0x47, 0x42, 0x00, 0xae, 0xce, 0x1c, 0xe9, 0x00, 0x00, 0x01, 0xad, 0x49, 0x44, 
    0x41, 0x54, 0x78, 0x9c, 0xed, 0xda, 0xd1, 0x92, 0x83, 0x20, 0x0c, 0x85, 0x61, 
    0xd8, 0xd9, 0xf7, 0x7f, 0x65, 0x7a, 0xb1, 0x33, 0x4e, 0x0a, 0xc2, 0x02, 0x12, 
    0x12, 0xf5, 0xff, 0xae, 0x3a, 0x1d, 0x1b, 0xf4, 0x34, 0x45, 0xc5, 0x86, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x65, 0xa2, 0xf5, 0x0e, 0x84, 0x94, 0xd2, 0xf1, 
    0x3a, 0xc6, 0x35, 0xfb, 0xa3, 0x51, 0xf3, 0x96, 0x52, 0x4a, 0x32, 0x8b, 0xd3, 
    0x77, 0x3c, 0xd4, 0xbc, 0xc8, 0xec, 0x1b, 0x4e, 0x29, 0xd5, 0xfa, 0x2b, 0x4b, 
    0xa4, 0xdd, 0x86, 0x9d, 0x1b, 0x37, 0x86, 0xd3, 0xf6, 0x6b, 0x32, 0xea, 0xbf, 
    0x64, 0x1c, 0x7f, 0x21, 0x96, 0x01, 0x95, 0xef, 0xdb, 0x76, 0x6b, 0x8d, 0xcd, 
    0x17, 0x2b, 0x7b, 0xea, 0xc8, 0x25, 0x0b, 0x2b, 0xcb, 0xb4, 0x8c, 0xaf, 0xdc, 
    0xe0, 0x34, 0x6e, 0x39, 0x90, 0x49, 0x23, 0x1b, 0x77, 0xb1, 0x0c, 0xae, 0x1d, 
    0xc1, 0x50, 0x3a, 0xfd, 0x65, 0x37, 0xf8, 0x31, 0x1c, 0xfb, 0x25, 0x88, 0x58, 
    0x9d, 0x71, 0xc4, 0xf2, 0x27, 0xbc, 0xf0, 0xe7, 0xac, 0x54, 0xf6, 0x66, 0x1a, 
    0x67, 0xff, 0xe9, 0x0b, 0x03, 0x8d, 0x9a, 0xd7, 0x31, 0x51, 0xa8, 0xb3, 0xfc, 
    0x11, 0xd5, 0x2e, 0x6c, 0x7b, 0x6e, 0x49, 0xda, 0xdb, 0xf4, 0xd7, 0xdc, 0xc0, 
    0x7e, 0x9e, 0xd2, 0x08, 0x8e, 0x35, 0x8a, 0x2f, 0xaa, 0xb3, 0xa4, 0x87, 0xfb, 
    0x3d, 0xe6, 0x62, 0x75, 0xbe, 0x22, 0xd6, 0x58, 0x69, 0x33, 0xe7, 0x65, 0x19, 
    0x48, 0xce, 0xad, 0xa3, 0x33, 0x69, 0xb9, 0xbd, 0xf9, 0x29, 0x4e, 0xf2, 0x12, 
    0x71, 0x10, 0x89, 0x8c, 0x2e, 0x9e, 0x95, 0x51, 0xc6, 0x18, 0xbd, 0xf5, 0xb2, 
    0x99, 0x6c, 0xbd, 0xc6, 0x79, 0xd9, 0xfb, 0x29, 0x1f, 0x4f, 0xf8, 0xaf, 0x7c, 
    0x27, 0xa7, 0x87, 0xdd, 0xce, 0x22, 0x09, 0x6b, 0x2b, 0x3f, 0x4d, 0x23, 0xa3, 
    0x25, 0x41, 0x34, 0x8a, 0xbf, 0x22, 0xe8, 0x89, 0x06, 0x74, 0x38, 0x84, 0x5f, 
    0x3d, 0x87, 0x77, 0xfd, 0xba, 0x58, 0x7b, 0x08, 0xbf, 0xca, 0x03, 0xd3, 0x98, 
    0x34, 0x3b, 0x6b, 0x3e, 0x30, 0xe5, 0xa1, 0x34, 0x97, 0xaf, 0x17, 0xdb, 0x9e, 
    0x00, 0x7d, 0xdd, 0x40, 0x3f, 0x12, 0x11, 0xab, 0xf3, 0x18, 0xf1, 0xdc, 0xed, 
    0xaf, 0xf9, 0xc3, 0xfc, 0x1a, 0xe3, 0x88, 0x1f, 0x78, 0xda, 0x29, 0x6c, 0x5a, 
    0x06, 0x3a, 0x1a, 0x73, 0x7f, 0xa3, 0xd5, 0x2e, 0x27, 0xb6, 0xed, 0xc9, 0x8e, 
    0x61, 0x6a, 0xff, 0xec, 0x3b, 0x3d, 0xd4, 0xb9, 0x67, 0x42, 0x8d, 0x4f, 0x65, 
    0xa3, 0x0c, 0xfd, 0x27, 0x71, 0x09, 0xdd, 0x2e, 0x9e, 0xe8, 0x97, 0x5a, 0x16, 
    0xfd, 0x1f, 0x1c, 0xda, 0x6c, 0x43, 0x47, 0x7b, 0x3c, 0xdd, 0x1d, 0x3a, 0x53, 
    0x76, 0x3e, 0xa1, 0xbb, 0x8e, 0x38, 0x74, 0xc4, 0xe7, 0x3c, 0xdf, 0x60, 0x32, 
    0x17, 0xbb, 0xe2, 0xf3, 0x3a, 0x0f, 0x00, 0x80, 0xbb, 0xf9, 0x00, 0xe8, 0xc7, 
    0x58, 0x99, 0xf9, 0x3d, 0x0e, 0x03, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 
    0x44, 0xae, 0x42, 0x60, 0x82
};

const lv_img_dsc_t frog1 = {
  .header.cf = LV_IMG_CF_RAW_CHROMA_KEYED,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 118,
  .header.h = 102,
  .data_size = 499,
  .data = frog1_map,
};
