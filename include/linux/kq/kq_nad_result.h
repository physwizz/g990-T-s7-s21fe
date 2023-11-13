/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __KQ_NAD_RESULT_H__
#define __KQ_NAD_RESULT_H__

#define KQ_NAD_RESULT_FORMAT_MAX_LEN	64

/* NAD Result Related Vars */
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_V2)
enum {
	KQ_NAD_PHASE_DRAM = 0,
	KQ_NAD_PHASE_SMD_FIRST,
	KQ_NAD_PHASE_SMD_SECOND,
	KQ_NAD_PHASE_EXTEND_FIRST,
	KQ_NAD_PHASE_EXTEND_SECOND,
	KQ_NAD_PHASE_ACAT_FIRST,
	KQ_NAD_PHASE_ACAT_SECOND,
	KQ_NAD_PHASE_NADX_SHORT_FIRST,
	KQ_NAD_PHASE_NADX_SHORT_SECOND,
	KQ_NAD_PHASE_CUSTOM_FIRST,
	KQ_NAD_PHASE_CUSTOM_SECOND,

	KQ_NAD_PHASE_END,
	KQ_NAD_PHASE_NONE = KQ_NAD_PHASE_END,
};

enum {
	KQ_NAD_ECC0,
	KQ_NAD_ECC1 = 4,
	KQ_NAD_ECC2 = 8,
	KQ_NAD_ECC3 = 12,
	KQ_NAD_ECC4 = 16,
	KQ_NAD_ECC5 = 20,
	KQ_NAD_ECC6 = 24,
	KQ_NAD_ECC7 = 28,
};
#else
enum {
	KQ_NAD_PHASE_SMD_FIRST = 0,
	KQ_NAD_PHASE_SMD_SECOND,
	KQ_NAD_PHASE_ACAT_FIRST,
	KQ_NAD_PHASE_ACAT_SECOND,
	KQ_NAD_PHASE_DRAM,
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_X)
	KQ_NAD_PHASE_EXTEND_FIRST,
	KQ_NAD_PHASE_EXTEND_SECOND,
#endif
	KQ_NAD_PHASE_CUSTOM_FIRST,
	KQ_NAD_PHASE_CUSTOM_SECOND,

	KQ_NAD_PHASE_END,
	KQ_NAD_PHASE_NONE = KQ_NAD_PHASE_END,
};
#endif

enum {
	KQ_NAD_RESULT_INFO_NAD_PASS = 0,
	KQ_NAD_RESULT_INFO_NAD_FAIL,

	KQ_NAD_RESULT_INFO_ACAT_PASS,
	KQ_NAD_RESULT_INFO_ACAT_FAIL,

	KQ_NAD_RESULT_INFO_NADX_PASS,
	KQ_NAD_RESULT_INFO_NADX_FAIL,

	KQ_NAD_RESULT_INFO_NADC_PASS,
	KQ_NAD_RESULT_INFO_NADC_FAIL,

	KQ_NAD_RESULT_INFO_NAD_INFORM1,
	KQ_NAD_RESULT_INFO_NAD_INFORM2,
	KQ_NAD_RESULT_INFO_NAD_INFORM3,
	KQ_NAD_RESULT_INFO_NAD_INFORM4,
	KQ_NAD_RESULT_INFO_NAD_INFORM5,

	KQ_NAD_RESULT_INFO_SNAD_INFORM1,
	KQ_NAD_RESULT_INFO_SNAD_INFORM2,
	KQ_NAD_RESULT_INFO_SNAD_INFORM3,
	KQ_NAD_RESULT_INFO_SNAD_INFORM4,
	KQ_NAD_RESULT_INFO_SNAD_INFORM5,

	KQ_NAD_RESULT_INFO_FNS,
	KQ_NAD_RESULT_INFO_FN,

	KQ_NAD_RESULT_INFO_IT,
	KQ_NAD_RESULT_INFO_MT,
	KQ_NAD_RESULT_INFO_TN,
	KQ_NAD_RESULT_INFO_VER,
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_55) || IS_ENABLED(CONFIG_SEC_KQ_NAD_V2)
	KQ_NAD_RESULT_INFO_REWORK,
	KQ_NAD_RESULT_INFO_REWORK_RESULT,
	KQ_NAD_RESULT_INFO_ECC0,
	KQ_NAD_RESULT_INFO_ECC1,
	KQ_NAD_RESULT_INFO_ECC2,
	KQ_NAD_RESULT_INFO_ECC3,
	KQ_NAD_RESULT_INFO_ECC4,
	KQ_NAD_RESULT_INFO_ECC5,
	KQ_NAD_RESULT_INFO_ECC6,
	KQ_NAD_RESULT_INFO_ECC7,
	KQ_NAD_RESULT_INFO_POWERMETER,
	KQ_NAD_RESULT_INFO_RAWPOWERMETER,
	KQ_NAD_RESULT_INFO_POWERMETER_NPU,
	KQ_NAD_RESULT_INFO_POWERMETER_LEAKAGE,
	KQ_NAD_RESULT_INFO_GT,
	KQ_NAD_RESULT_INFO_NAD_ASV,
	KQ_NAD_RESULT_INFO_NAD_XP,
	KQ_NAD_RESULT_INFO_NAD_EY,
	KQ_NAD_RESULT_INFO_LSI_GRADE,
#endif

	KQ_NAD_RESULT_INFO_NADC_SHUTDOWN,
	KQ_NAD_RESULT_INFO_NADC_DETAIL,

#if IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
	KQ_NAD_RESULT_INFO_VDD_CAL0,
	KQ_NAD_RESULT_INFO_VDD_CAL1,
	KQ_NAD_RESULT_INFO_VDD_CAL2,
#endif //IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)

#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	KQ_NAD_RESULT_INFO_CORRELATION_CL0,
	KQ_NAD_RESULT_INFO_CORRELATION_CL1,
	KQ_NAD_RESULT_INFO_CORRELATION_CL2,
	KQ_NAD_RESULT_INFO_CORRELATION_MIF,
	KQ_NAD_RESULT_INFO_CORRELATION_DSU,
	KQ_NAD_RESULT_INFO_CORRELATION_CP,
	KQ_NAD_RESULT_INFO_CORRELATION_G3D,
	KQ_NAD_RESULT_INFO_CORRELATION_SCI,
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)

	KQ_NAD_RESULT_INFO_END,
};

struct kq_nad_result {
	char format[KQ_NAD_RESULT_FORMAT_MAX_LEN];
	int phase;
	int type;
};

#if IS_ENABLED(CONFIG_SEC_KQ_NAD_V2)
static struct kq_nad_result kq_nad_result_nad_skip[] ={
	{ KQ_NAD_STR_NAD_SKIP, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_PASS },
};
#endif

static struct kq_nad_result kq_nad_result_nad_pass[] = {
	{ KQ_NAD_STR_NAD_PASS, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_PASS },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "NAD4(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM4 },
	{ "NAD5(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM5 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "SNAD4(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM4 },
	{ "SNAD5(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM5 },
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_55) || IS_ENABLED(CONFIG_SEC_KQ_NAD_V2)
	{ "LRW(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_REWORK_RESULT },
	{ "ECC0(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC0 },
	{ "ECC1(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC1 },
	{ "ECC2(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC2 },
	{ "ECC3(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC3 },
	{ "ECC4(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC4 },
	{ "ECC5(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC5 },
	{ "ECC6(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC6 },
	{ "ECC7(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC7 },
	{ "PDATA(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_POWERMETER },
	{ "PRDATA(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_RAWPOWERMETER },
	{ "PNPU(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_POWERMETER_NPU },
	{ "PLEAKAGE(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_POWERMETER_LEAKAGE },
	{ "GT(%d)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_GT },
	{ "NAD_ASV(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_ASV },
	{ "NAD_XP(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_XP },
	{ "NAD_EY(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_EY },
	{ "LSI_GRADE(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_LSI_GRADE },
#endif
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
	{ "VDD0(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL0 },
	{ "VDD1(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL1 },
	{ "VDD2(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL2 },
#endif //IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

static struct kq_nad_result kq_nad_result_nad_fail[] = {
	{ KQ_NAD_STR_NAD_FAIL, KQ_NAD_RESULT_INFO_NAD_FAIL },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "NAD4(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM4 },
	{ "NAD5(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM5 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "SNAD4(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM4 },
	{ "SNAD5(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM5 },
	{ "FNS(%s_%s_%d_%s)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_FNS },
	{ "FN(%s_%s_%d_%s)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_FN },
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_55) || IS_ENABLED(CONFIG_SEC_KQ_NAD_V2)
	{ "LRW(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_REWORK_RESULT },
	{ "ECC0(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC0 },
	{ "ECC1(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC1 },
	{ "ECC2(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC2 },
	{ "ECC3(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC3 },
	{ "ECC4(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC4 },
	{ "ECC5(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC5 },
	{ "ECC6(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC6 },
	{ "ECC7(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ECC7 },
	{ "PDATA(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_POWERMETER },
	{ "PRDATA(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_RAWPOWERMETER },
	{ "PNPU(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_POWERMETER_NPU },
	{ "PLEAKAGE(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_POWERMETER_LEAKAGE },
	{ "GT(%d)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_GT },
	{ "NAD_ASV(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_ASV },
	{ "NAD_XP(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_XP },
	{ "NAD_EY(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_EY },
	{ "LSI_GRADE(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_LSI_GRADE },
#endif
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
	{ "VDD0(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL0 },
	{ "VDD1(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL1 },
	{ "VDD2(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL2 },
#endif //IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

static struct kq_nad_result kq_nad_result_acat_pass[] = {
	{ KQ_NAD_STR_ACAT_PASS, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ACAT_PASS },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "NAD4(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM4 },
	{ "NAD5(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM5 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "SNAD4(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM4 },
	{ "SNAD5(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM5 },
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

static struct kq_nad_result kq_nad_result_acat_fail[] = {
	{ KQ_NAD_STR_ACAT_FAIL, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ACAT_FAIL },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "NAD4(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM4 },
	{ "NAD5(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM5 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "SNAD4(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM4 },
	{ "SNAD5(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM5 },
	{ "FNS(%s_%s_%d_%s)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_FNS },
	{ "FN(%s_%s_%d_%s)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_FN },
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

#if IS_ENABLED(CONFIG_SEC_KQ_NAD_55) || IS_ENABLED(CONFIG_SEC_KQ_NAD_V2)
static struct kq_nad_result kq_nad_result_nad_rework[] = {
	{ KQ_NAD_STR_NAD_REWORK, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_PASS },
	{ "RW(%d)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_REWORK },
	{ "IT(%d)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_IT },
	{ "MT(%d)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_MT },
	{ "TN(%d)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_TN },
};
#endif

#if IS_ENABLED(CONFIG_SEC_KQ_NAD_X) || IS_ENABLED(CONFIG_SEC_KQ_NAD_V2)
static struct kq_nad_result kq_nad_result_nadx_pass[] = {
	{ KQ_NAD_STR_NADX_PASS, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NADX_PASS },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "NAD4(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM4 },
	{ "NAD5(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM5 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "SNAD4(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM4 },
	{ "SNAD5(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM5 },
	{ "IT(%d)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_IT },
	{ "MT(%d)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_MT },
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

static struct kq_nad_result kq_nad_result_nadx_fail[] = {
	{ KQ_NAD_STR_NADX_FAIL, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NADX_FAIL },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "NAD4(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM4 },
	{ "NAD5(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM5 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "SNAD4(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM4 },
	{ "SNAD5(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM5 },
	{ "FNS(%s_%s_%d_%s)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_FNS },
	{ "FN(%s_%s_%d_%s)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_FN },
	{ "IT(%d)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_IT },
	{ "MT(%d)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_MT },
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};
#endif //IS_ENABLED(CONFIG_SEC_KQ_NAD_X) || IS_ENABLED(CONFIG_SEC_KQ_NAD_V2)

static struct kq_nad_result kq_nad_result_nadc_fail[] = {
	{ "NG_5.0_L%sCASE(NULL)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NADC_SHUTDOWN },
	{ "DETAIL(%s)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NADC_DETAIL },
	{ "FN(%s_%s_%d_%s)", KQ_NAD_PHASE_CUSTOM_FIRST, KQ_NAD_RESULT_INFO_FN },
	{ "FNS(%s_%s_%d_%s)", KQ_NAD_PHASE_CUSTOM_SECOND, KQ_NAD_RESULT_INFO_FNS },
};

#endif	//__KQ_NAD_RESULT_H__
