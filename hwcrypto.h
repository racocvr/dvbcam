#ifndef __HW_CRYPTO_H__
#define __HW_CRYPTO_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void *crypthw_create(const void *pctx, const void *a2, unsigned int alg_type, int mode, int keytype, unsigned int padding_type);
void crypthw_destroy(const void *pctx);
int crypthw_enc(void *pctx, uint8_t *inbuf, uint8_t *outbuf, unsigned int len, int *outlen, int bPadding);
int crypthw_dec(void *pctx, uint8_t *inbuf, uint8_t *outbuf, unsigned int len, int *outlen, int bPadding);

#ifdef __cplusplus
}
#endif

#endif /* __HW_CRYPTO_H__ */
