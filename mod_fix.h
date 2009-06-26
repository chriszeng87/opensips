/*
 *$Id$
 *
 * Copyright (C) 2001-2003 FhG Fokus
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*!
 * \file
 * \brief Generic fixup functions for module function parameter.
 */

#ifndef _mod_fix_h_
#define _mod_fix_h_

#include "pvar.h"

#define GPARAM_TYPE_INT		0
#define GPARAM_TYPE_STR		1
#define GPARAM_TYPE_PVS		2
#define GPARAM_TYPE_PVE		3

/*!
 * generic parameter that holds a string, an int or a pseudo-variable
 */
typedef struct _gparam
{
	int type;
	union {
		int ival;
		str sval;
		pv_spec_t *pvs;
		pv_elem_t *pve;
	} v;
} gparam_t, *gparam_p;

int fixup_str_null(void** param, int param_no);
int fixup_str_str(void** param, int param_no);

int fixup_free_str_null(void** param, int param_no);
int fixup_free_str_str(void** param, int param_no);

int fixup_uint_null(void** param, int param_no);
int fixup_uint_uint(void** param, int param_no);

#if 0
int fixup_sint_null(void** param, int param_no);
int fixup_sint_sint(void** param, int param_no);
int fixup_sint_uint(void** param, int param_no);
int fixup_uint_sint(void** param, int param_no);
#endif

int fixup_regexp_null(void** param, int param_no);
int fixup_regexpNL_null(void** param, int param_no);
int fixup_free_regexp_null(void** param, int param_no);
int fixup_regexp_none(void** param, int param_no);
int fixup_regexpNL_none(void** param, int param_no);
int fixup_free_regexp_none(void** param, int param_no);

int fixup_pvar_null(void **param, int param_no);
int fixup_free_pvar_null(void** param, int param_no);

int fixup_pvar_pvar(void **param, int param_no);
int fixup_free_pvar_pvar(void** param, int param_no);

int fixup_pvar_str(void** param, int param_no);
int fixup_free_pvar_str(void** param, int param_no);

int fixup_pvar_str_str(void** param, int param_no);
int fixup_free_pvar_str_str(void** param, int param_no);

int fixup_igp_igp(void** param, int param_no);
int fixup_igp_null(void** param, int param_no);
int fixup_get_ivalue(struct sip_msg* msg, gparam_p gp, int *val);

int fixup_igp_pvar_pvar(void** param, int param_no);
int fixup_free_igp_pvar_pvar(void** param, int param_no);

int fixup_spve_spve(void** param, int param_no);
int fixup_spve_null(void** param, int param_no);
int fixup_spve_uint(void** param, int param_no);
int fixup_get_svalue(struct sip_msg* msg, gparam_p gp, str *val);


int fixup_spve(void** param);
int fixup_pvar(void **param);
int fixup_str(void **param);
int fixup_uint(void** param);

#endif
