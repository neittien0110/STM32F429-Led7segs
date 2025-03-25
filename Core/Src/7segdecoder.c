#include "7segdecoder.h"

/**
 * @brief Chuyển đổi số nguyên thành giá trị gán cho led 7-seg
 * @note  Hàm áp dụng cho led 7-seg chung chân Cathode.
 * @param[in]	so 		Số nguyên cần chuyển dổi, trong phạm vi từ [0,9]
 * @param[out]  a		Giá trị thanh led a cua led 7-seg, trong đó 1 là sáng, 0 là tắt.
 * @param[out]  b		Giá trị thanh led b
 * @param[out]  c		Giá trị thanh led c
 * @param[out]  d		Giá trị thanh led d
 * @param[out]  e		Giá trị thanh led e
 * @param[out]  f		Giá trị thanh led f
 * @param[out]  g		Giá trị thanh led g
 * @retval None
 */
void NumberTo7seg(unsigned char so, bool * a, bool * b, bool * c, bool * d, bool * e, bool * f, bool * g) {
    switch (so) {
        case 0: *a = 1; *b = 1; *c = 1; *d = 1; *e = 1; *f = 1; *g = 0; break;
        case 1: *a = 0; *b = 1; *c = 1; *d = 0; *e = 0; *f = 0; *g = 0; break;
        case 2: *a = 1; *b = 1; *c = 0; *d = 1; *e = 1; *f = 0; *g = 1; break;
        case 3: *a = 1; *b = 1; *c = 1; *d = 1; *e = 0; *f = 0; *g = 1; break;
        case 4: *a = 0; *b = 1; *c = 1; *d = 0; *e = 0; *f = 1; *g = 1; break;
        case 5: *a = 1; *b = 0; *c = 1; *d = 1; *e = 0; *f = 1; *g = 1; break;
        case 6: *a = 1; *b = 0; *c = 1; *d = 1; *e = 1; *f = 1; *g = 1; break;
        case 7: *a = 1; *b = 1; *c = 1; *d = 0; *e = 0; *f = 0; *g = 0; break;
        case 8: *a = 1; *b = 1; *c = 1; *d = 1; *e = 1; *f = 1; *g = 1; break;
        case 9: *a = 1; *b = 1; *c = 1; *d = 1; *e = 0; *f = 1; *g = 1; break;
        default: *a = 0; *b = 0; *c = 0; *d = 0; *e = 0; *f = 0; *g = 0; // Mặc định tắt nếu số không hợp lệ
    }
}



