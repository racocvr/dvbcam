#ifndef __GST_EXT_LIB_H__
#define __GST_EXT_LIB_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void* pvr_drm_client_context_create();
void pvr_drm_client_context_destroy(void *ptr);
int pvr_drm_client_jackpack_convert_key(void* ctx, const void *in_buf, uint32_t in_len, uint32_t version, void *out_buf, uint32_t *out_len);
int pvr_drm_client_player_start_decrypt(void* ctx, int adapterid, int dmxid, void *key, uint32_t key_len, int bOrsay);
int pvr_drm_client_player_stop_decrypt(void *ctx);

#ifdef __cplusplus
}
#endif

#endif /* __GST_EXT_LIB_H__ */
