// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
 * Copyright (C) 2021 XiaoMi, Inc.
 * Copyright (C) 2020 XiaoMi, Inc.
 */

#define pr_fmt(fmt) "mi_sde_crtc:[%s:%d] " fmt, __func__, __LINE__

#include "mi_sde_crtc.h"

void mi_sde_crtc_update_layer_state(struct sde_crtc_state *cstate)
{
	int i = 0;
	uint32_t fod_sync_info;

	if (!cstate)
		return;

	fod_sync_info = sde_crtc_get_property(cstate, CRCT_PROP_MI_FOD_SYNC_INFO);

	for (i = 0; i < cstate->num_connectors; i++)
		mi_sde_connector_update_layer_state(cstate->connectors[i], fod_sync_info);
}

void mi_sde_crtc_install_properties(struct msm_property_info *property_info)
{
	msm_property_install_range(property_info, "mi_fod_sync_info",
		0x0, 0, U32_MAX, 0, CRCT_PROP_MI_FOD_SYNC_INFO);
}
