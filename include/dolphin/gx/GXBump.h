#ifndef _DOLPHIN_GXBUMP
#define _DOLPHIN_GXBUMP

#include <dolphin/gx/GXEnum.h>

#ifdef __cplusplus
extern "C" {
#endif

void GXSetTevDirect(GXTevStageID tev_stage);
void GXSetNumIndStages(u8 nIndStages);
void GXSetIndTexMtx(GXIndTexMtxID mtx_sel, const f32 offset[2][3], s8 scale_exp);
void GXSetIndTexOrder(GXIndTexStageID ind_stage, GXTexCoordID tex_coord, GXTexMapID tex_map);
void GXSetTevIndirect(GXTevStageID tev_stage, GXIndTexStageID ind_stage, GXIndTexFormat format,
                      GXIndTexBiasSel bias_sel, GXIndTexMtxID matrix_sel, GXIndTexWrap wrap_s,
                      GXIndTexWrap wrap_t, GXBool add_prev, GXBool ind_lod,
                      GXIndTexAlphaSel alpha_sel);
void GXSetTevIndWarp(GXTevStageID tev_stage, GXIndTexStageID ind_stage, GXBool signed_offsets,
                     GXBool replace_mode, GXIndTexMtxID matrix_sel);
void GXSetIndTexCoordScale(GXIndTexStageID ind_state, GXIndTexScale scale_s, GXIndTexScale scale_t);

#ifdef __cplusplus
}
#endif

#endif // _DOLPHIN_GXBUMP
