/********************************************************************
 *   File   : builtins.c
 *   Author : Neng-Fa ZHOU Copyright (C) 1994-2019
 *   Purpose: Inline built-ins

 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 ********************************************************************/
#include <string.h>
#include "basic.h"
#include "term.h"
#include "bapi.h"
#define MAXBS 317

Builtins builtins[MAXBS];

void init_builtins(void){
    INITIALIZE_BUILTIN3(1,b_ACCESS_ccf);
    INITIALIZE_BUILTIN2(2,b_ASPN2_cc);
    INITIALIZE_BUILTIN3(3,b_ASPN3_ccc);
    INITIALIZE_BUILTIN4(4,b_ASPN4_cccc);
    INITIALIZE_BUILTIN1(5,b_ASPN_c);
    INITIALIZE_BUILTIN1(6,b_ASSERTABLE_c);
    INITIALIZE_BUILTIN1(7,b_INC_PRED_REF_COUNT_c);
    INITIALIZE_BUILTIN1(8,b_DEC_PRED_REF_COUNT_c);
    INITIALIZE_BUILTIN1(9,b_INC_PRED_RETR_COUNT_c);
    INITIALIZE_BUILTIN1(10,b_DEC_PRED_RETR_COUNT_c);
    INITIALIZE_BUILTIN2(11,b_BLDATOM_fc);
    INITIALIZE_BUILTIN1(12,b_CLOSE_c);
    INITIALIZE_BUILTIN3(13,b_COMPARE_fcc);
    INITIALIZE_BUILTIN2(14,b_FLOAT_ASIN_cf);
    INITIALIZE_BUILTIN2(15,b_FLOAT_ACOS_cf);
    INITIALIZE_BUILTIN3(16,b_REM_ccf);
    INITIALIZE_BUILTIN1(17,b_CPUTIME_f);
    INITIALIZE_BUILTIN1(18,b_CURRENT_INPUT_f);
    INITIALIZE_BUILTIN1(19,b_CURRENT_OUTPUT_f);
    INITIALIZE_BUILTIN3(20,b_DESTRUCTIVE_SET_ARG_ccc);
    INITIALIZE_BUILTIN2(21,b_DM_COUNT_cf);
    INITIALIZE_BUILTIN3(22,b_DM_MIN_MAX_cff);
    INITIALIZE_BUILTIN3(23,b_RAND_MAX_f);
    INITIALIZE_BUILTIN3(24,b_DM_PREV_ccf);
    INITIALIZE_BUILTIN3(25,b_DM_NEXT_ccf);
    INITIALIZE_BUILTIN2(26,b_DM_TRUE_cc);
    INITIALIZE_BUILTIN2(27,b_EVAL_ARITH_cf);
    INITIALIZE_BUILTIN2(28,b_FLOAT_ABS_cf);
    INITIALIZE_BUILTIN2(29,b_FLOAT_ATAN_cf);
    INITIALIZE_BUILTIN2(30,b_FLOAT_CEILING_cf);
    INITIALIZE_BUILTIN2(31,b_FLOAT_COS_cf);
    INITIALIZE_BUILTIN2(32,b_FLOAT_EXP_cf);
    INITIALIZE_BUILTIN2(33,b_FLOAT_FLOAT_cf);
    INITIALIZE_BUILTIN2(34,b_FLOAT_FLOOR_cf);
    INITIALIZE_BUILTIN2(35,b_FLOAT_LOG_cf);
    INITIALIZE_BUILTIN2(36,b_FLOAT_MINUS_cf);
    INITIALIZE_BUILTIN3(37,b_FLOAT_POW_ccf);
    INITIALIZE_BUILTIN2(38,b_FLOAT_ROUND_cf);
    INITIALIZE_BUILTIN2(39,b_FLOAT_SIN_cf);
    INITIALIZE_BUILTIN2(40,b_FLOAT_SQRT_cf);
    INITIALIZE_BUILTIN2(41,b_FLOAT_TAN_cf);
    INITIALIZE_BUILTIN2(42,b_FLOAT_TRUNCATE_cf);
    INITIALIZE_BUILTIN1(43,b_FLOAT_WRITE_c);
    INITIALIZE_BUILTIN0(44,b_FLUSH_OUTPUT);
    INITIALIZE_BUILTIN1(45,b_GET0_f);
    INITIALIZE_BUILTIN2(46,b_GET_CLAUSES_cfff);
    INITIALIZE_BUILTIN3(47,b_ASSERTA_cc);
    INITIALIZE_BUILTIN2(48,b_GET_LENGTH_cf);
    INITIALIZE_BUILTIN3(49,b_GET_SYM_TYPE_ccf);
    INITIALIZE_BUILTIN1(50,b_GET_f);
    INITIALIZE_BUILTIN2(51,b_DYN_PRED_CLAUSE_COUNT_cf);
    INITIALIZE_BUILTIN2(52,b_GET_UTF8_NCHARS_cf);
    INITIALIZE_BUILTIN2(53,b_GLOBAL_DEL_cc);
    INITIALIZE_BUILTIN3(54,b_GLOBAL_GET_ccf);
    INITIALIZE_BUILTIN4(55,b_GLOBAL_INSERT_HEAD_cccc);
    INITIALIZE_BUILTIN3(56,b_GLOBAL_INSERT_TAIL_ccc);
    INITIALIZE_BUILTIN3(57,b_DM_PREV0_ccf);
    INITIALIZE_BUILTIN3(58,b_GLOBAL_SET_ccc);
    INITIALIZE_BUILTIN4(59,b_GLOBAL_SET_cccc);
    INITIALIZE_BUILTIN2(60,b_HASHVAL1_cf);
    INITIALIZE_BUILTIN2(61,b_HASHVAL_cf);
    INITIALIZE_BUILTIN1(62,nondvar);
    INITIALIZE_BUILTIN2(63,b_ISGLOBAL_cc);
    INITIALIZE_BUILTIN1(64,b_IS_CONSULTED_c);
    INITIALIZE_BUILTIN2(65,b_IS_DYNAMIC_cc);
    INITIALIZE_BUILTIN2(66,b_IS_ORDINARY_cc);
    INITIALIZE_BUILTIN3(67,b_LOAD_cfc);
    INITIALIZE_BUILTIN2(68,b_NAME0_cf);
    INITIALIZE_BUILTIN2(69,b_NEXT_TOKEN_ff);
    INITIALIZE_BUILTIN0(70,b_NL);
    INITIALIZE_BUILTIN1(71,b_NORMAL_ATOM_c);
    INITIALIZE_BUILTIN3(72,b_OPEN_ccf);
    INITIALIZE_BUILTIN1(73,b_PUT_c);
    INITIALIZE_BUILTIN1(74,b_RETRACTABLE_c);
    INITIALIZE_BUILTIN1(75,b_SEEING_f);
    INITIALIZE_BUILTIN0(76,b_SEEN);
    INITIALIZE_BUILTIN1(77,b_SEE_c);
    INITIALIZE_BUILTIN3(78,b_PICAT_TABLE_MAP_PUT_ccc);
    INITIALIZE_BUILTIN3(79,b_ASSERTZ_cc);
    INITIALIZE_BUILTIN2(80,b_SET_INPUT_cc);
    INITIALIZE_BUILTIN2(81,b_SET_OUTPUT_cc);
    INITIALIZE_BUILTIN2(82,b_SYSTEM0_cf);
    INITIALIZE_BUILTIN1(83,b_TAB_c);
    INITIALIZE_BUILTIN1(84,b_TELLING_f);
    INITIALIZE_BUILTIN2(85,b_TELL_cc);
    INITIALIZE_BUILTIN0(86,b_TOLD);
    INITIALIZE_BUILTIN2(87,b_ATOM_MODE_cf);
    INITIALIZE_BUILTIN3(88,b_PICAT_TABLE_MAP_GET_ccf);
    INITIALIZE_BUILTIN1(89,b_WRITENAME_c);
    INITIALIZE_BUILTIN1(90,b_WRITEQNAME_c);
    INITIALIZE_BUILTIN1(91,b_WRITEQ_QUICK_c);
    INITIALIZE_BUILTIN1(92,b_WRITE_IMAGE_c);
    INITIALIZE_BUILTIN1(93,b_WRITE_QUICK_c);
    INITIALIZE_BUILTIN3(94,b_XOR_ccf);
    INITIALIZE_BUILTIN2(95,b_FLOAT_SIGN_cf);
    INITIALIZE_BUILTIN1(96,dvar_or_int);
    INITIALIZE_BUILTIN2(97,b_CONSTRAINTS_NUMBER_cf);
    INITIALIZE_BUILTIN1(98,b_IS_PLANNER_STATE_c);
    INITIALIZE_BUILTIN2(99,b_select_ff);
    INITIALIZE_BUILTIN2(101,b_DM_MIN_cf);
    INITIALIZE_BUILTIN2(102,b_DM_MAX_cf);
    INITIALIZE_BUILTIN1(103,dvar_bv);
    INITIALIZE_BUILTIN1(104,dvar_excludable_or_int);
    /**/
    INITIALIZE_BUILTIN1(105,b_FLOAT_PI_f);
    INITIALIZE_BUILTIN1(106,b_RANDOM_f);
    INITIALIZE_BUILTIN2(107,b_RANDOM_cf);
    INITIALIZE_BUILTIN3(108,b_MAX_ccf);
    INITIALIZE_BUILTIN3(109,b_MIN_ccf);
    INITIALIZE_BUILTIN1(110,b_REMOVE_CLAUSE_c);
    INITIALIZE_BUILTIN2(111,b_PLANNER_CURR_RPC_fff);
    INITIALIZE_BUILTIN3(112,b_NTH_ELM_ccf);
    INITIALIZE_BUILTIN1(113,var_or_atomic);
    INITIALIZE_BUILTIN2(114,b_SUSP_ATTACH_TERM_cc);
    INITIALIZE_BUILTIN2(115,b_SUSP_ATTACHED_TERM_cf);
    INITIALIZE_BUILTIN1(116,b_SUSP_VAR_c);
    INITIALIZE_BUILTIN1(117,b_PEEK_BYTE_f);
    INITIALIZE_BUILTIN1(118,b_GET_ARCH_f);
    INITIALIZE_BUILTIN3(119,b_GCD_ccf);
    INITIALIZE_BUILTIN3(120,b_HASHTABLE_GET_ccf);
    INITIALIZE_BUILTIN2(121,b_DM_INNER_TRUE_cc);
    INITIALIZE_BUILTIN1(122,b_CLPSET_CARD_BOUND_c);
    INITIALIZE_BUILTIN1(123,b_CLPSET_LOW_UPDATED_c);
    INITIALIZE_BUILTIN1(124,b_CLPSET_UP_UPDATED_c);
    INITIALIZE_BUILTIN2(125,b_DM_FALSE_cc);
    INITIALIZE_BUILTIN2(126,b_DM_FALSE_cc);
    INITIALIZE_BUILTIN3(127,b_INSERT_ORDERED_NO_DUP_ccf);
    INITIALIZE_BUILTIN3(128,b_INSERT_ORDERED_DOWN_NO_DUP_ccf);
    /* for threads */
    /*
      INITIALIZE_BUILTIN1(127,b_IS_LATEST_CHOICE_POINT_c);
      INITIALIZE_BUILTIN0(128,b_THREAD_DISABLE_INTERRUPT);
      INITIALIZE_BUILTIN0(129,b_THREAD_ENABLE_INTERRUPT);
      INITIALIZE_BUILTIN1(130,b_THREAD_GET_CENTRAL_TIMER_f);
      INITIALIZE_BUILTIN2(131,b_THREAD_GET_TIMER_cf);
      INITIALIZE_BUILTIN1(132,b_THREAD_REGISTER_NEW_c);
      INITIALIZE_BUILTIN0(133,b_THREAD_RESCHEDULE);
      INITIALIZE_BUILTIN2(134,b_THREAD_SET_CALL_cc);
      INITIALIZE_BUILTIN1(135,b_THREAD_SET_CENTRAL_TIMER_c);
      INITIALIZE_BUILTIN2(136,b_THREAD_SET_STATUS_cc);
      INITIALIZE_BUILTIN2(137,b_THREAD_SET_TIMER_cc);
    */
    /**/
    INITIALIZE_BUILTIN2(138,b_GET_LINE_NO_cf);
    INITIALIZE_BUILTIN2(139,b_GET_LINE_POS_cf);
    INITIALIZE_BUILTIN3(140,b_GET_PRED_PTR_cff);
    /**/
    INITIALIZE_BUILTIN2(141,b_FINDALL_INSERT_cc);
    INITIALIZE_BUILTIN1(142,b_EXCLUDABLE_LIST_c);
    /**/
    INITIALIZE_BUILTIN0(143,b_IS_DEBUG_MODE);
    INITIALIZE_BUILTIN2(144,b_ABOLISH_cc);
    /**/
    INITIALIZE_BUILTIN3(145,b_REIFY_EQ_CONSTR_ACTION);
    INITIALIZE_BUILTIN3(146,b_REIFY_GE_CONSTR_ACTION);
    INITIALIZE_BUILTIN3(147,b_REIFY_NEQ_CONSTR_ACTION);
    /**/
    INITIALIZE_BUILTIN3(148,b_DM_CREATE_DVAR);
    INITIALIZE_BUILTIN2(149,b_VAR_IN_D_cc);
    INITIALIZE_BUILTIN3(150,b_EXCLUDE_NOGOOD_INTERVAL_ccc);
    INITIALIZE_BUILTIN2(151,b_DM_INCLUDE);
    INITIALIZE_BUILTIN2(152,b_FD_ABS_X_TO_Y);
    INITIALIZE_BUILTIN3(153,b_DM_INTERSECT2);
    INITIALIZE_BUILTIN2(154,b_DM_DISJOINT_cc);
    INITIALIZE_BUILTIN3(155,b_EXCLUDE_ELM_DVARS);
    INITIALIZE_BUILTIN2(156,b_EXCLUDE_ELM_VCS);
    INITIALIZE_BUILTIN0(157,b_ENABLE_GC);
    INITIALIZE_BUILTIN0(158,b_DISABLE_GC);
    INITIALIZE_BUILTIN1(159,b_GLOBAL_HEAP_VTABLE_REF_f);
    INITIALIZE_BUILTIN2(160,b_GLOBAL_HEAP_GET_cf);
    INITIALIZE_BUILTIN3(161,b_POST_EVENT_ccc);
    INITIALIZE_BUILTIN3(162,b_GET_ATTACHED_AGENTS_ccf);
    INITIALIZE_BUILTIN2(163,b_AGENT_OCCUR_IN_CONJUNCTIVE_CHANNELS_cc);
    INITIALIZE_BUILTIN2(164,b_AGENT_OCCUR_IN_DISJUNCTIVE_CHANNELS_cc);
    INITIALIZE_BUILTIN3(165,b_GET_ATTR_ccf);
    INITIALIZE_BUILTIN3(166,b_CLPFD_MULTIPLY_INT_ccc);
    INITIALIZE_BUILTIN2(167,b_VAR_NOTIN_D_cc);
    INITIALIZE_BUILTIN0(168,b_PATH_FROM_TO_REACHABLE);
    INITIALIZE_BUILTIN2(169,b_BLDNUM_fc);

    INITIALIZE_BUILTIN1(170,b_STREAM_IS_OPEN_c);
    INITIALIZE_BUILTIN2(171,b_STREAM_SET_TYPE_cc);
    INITIALIZE_BUILTIN2(172,b_STREAM_SET_EOF_ACTION_cc);
    INITIALIZE_BUILTIN2(173,b_STREAM_ADD_ALIAS_cc);
    INITIALIZE_BUILTIN0(174,b_STREAM_UPDATE_EOS);
    INITIALIZE_BUILTIN2(175,b_STREAM_GET_FILE_NAME_cf);
    INITIALIZE_BUILTIN2(176,b_STREAM_GET_MODE_cf);
    INITIALIZE_BUILTIN2(177,b_STREAM_GET_ALIASES_cf);
    INITIALIZE_BUILTIN2(178,b_STREAM_GET_EOS_cf);
    INITIALIZE_BUILTIN2(179,b_STREAM_GET_EOF_ACTION_cf);
    INITIALIZE_BUILTIN2(180,b_STREAM_GET_TYPE_cf);
    INITIALIZE_BUILTIN2(181,b_ABS_CON_cc);
    INITIALIZE_BUILTIN3(182,b_MOD_CON_ccc);
    INITIALIZE_BUILTIN3(183,b_VV_EQ_C_CON_ccc);
    INITIALIZE_BUILTIN3(184,b_V_EQ_VC_CON_ccc);
    INITIALIZE_BUILTIN1(185,b_PEEK_CODE_f);
    INITIALIZE_BUILTIN1(186,b_PUT_BYTE_c);
    INITIALIZE_BUILTIN1(187,b_PUT_CODE_c);
    INITIALIZE_BUILTIN2(188,b_CHAR_CODE_cf);
    INITIALIZE_BUILTIN2(189,b_CHAR_CODE_fc);
    INITIALIZE_BUILTIN1(190,b_GET_BYTE_f);
    INITIALIZE_BUILTIN1(191,b_GET_CODE_f);
    INITIALIZE_BUILTIN1(192,b_GET_FLAG_DOUBLE_QUOTES_f);
    INITIALIZE_BUILTIN1(193,b_SET_FLAG_DOUBLE_QUOTES_c);
    INITIALIZE_BUILTIN2(194,b_SET_BINARY_INPUT_cc);
    INITIALIZE_BUILTIN2(195,b_SET_TEXT_INPUT_cc);
    INITIALIZE_BUILTIN2(196,b_SET_BINARY_OUTPUT_cc);
    INITIALIZE_BUILTIN2(197,b_SET_TEXT_OUTPUT_cc);
    INITIALIZE_BUILTIN0(198,b_STREAM_CHECK_CURRENT_TEXT_INPUT);
    INITIALIZE_BUILTIN0(199,b_STREAM_CHECK_CURRENT_TEXT_OUTPUT);
    INITIALIZE_BUILTIN1(200,b_ASPN_i);
    INITIALIZE_BUILTIN4(201,b_ALLDISTINCT_CHECK_HALL_VAR_cccc);
    INITIALIZE_BUILTIN2(202,b_SELECT_MIN_cf);
    INITIALIZE_BUILTIN2(203,b_SELECT_MAX_cf);
    INITIALIZE_BUILTIN2(204,b_SELECT_FF_MIN_cf);
    INITIALIZE_BUILTIN2(205,b_SELECT_FF_MAX_cf);
    INITIALIZE_BUILTIN2(206,b_UNIV_cc);
    INITIALIZE_BUILTIN3(207,b_LIST_LENGTH_cff);
    INITIALIZE_BUILTIN2(208,b_sort_int_list);
    INITIALIZE_BUILTIN3(209,b_FLOAT_LOG2_ccf);
    INITIALIZE_BUILTIN1(210,b_FLOAT_E_f);
    INITIALIZE_BUILTIN3(211,b_CFD_BUILD_TRIES_IN);
    INITIALIZE_BUILTIN3(212,b_CFD_BUILD_TRIES_NOTIN);
    INITIALIZE_BUILTIN4(213,b_CFD_COMPUTE_MINS_MAXS);
    INITIALIZE_BUILTIN3(214,b_CFD_DOM);
    INITIALIZE_BUILTIN2(215,b_CFD_INS);
    INITIALIZE_BUILTIN2(216,b_CFD_REMOVE_AC_UNSUPPORTED);
    INITIALIZE_BUILTIN2(217,b_DM_INTERSECT);
    INITIALIZE_BUILTIN3(218,b_TASKS_EXCLUDE_NOGOOD_INTERVAL_ccc);
    INITIALIZE_BUILTIN1(219,b_DISJUNCTIVE_TASKS_AC);
    INITIALIZE_BUILTIN1(220,b_DISJUNCTIVE_TASKS_EF);
	INITIALIZE_BUILTIN1(221,b_IS_ALPHA_DIGIT_c);
    //    INITIALIZE_BUILTIN0(222,b_COMP_PROP_FAPP2);
    INITIALIZE_BUILTIN3(223,b_ABS_DIFF_CON_ccc);
    INITIALIZE_BUILTIN1(224,b_ABS_DIFF_X_TO_Y);
    INITIALIZE_BUILTIN0(225,b_ABS_ABS_DIFF_NEQ);
    INITIALIZE_BUILTIN2(226,b_FLOAT_FRACT_PART_cf);
    INITIALIZE_BUILTIN2(227,b_FLOAT_INT_PART_cf);
    INITIALIZE_BUILTIN2(228,b_MAX_cf);
    INITIALIZE_BUILTIN2(229,b_MIN_cf);
    INITIALIZE_BUILTIN2(230,b_SUM_cf);
    INITIALIZE_BUILTIN3(234,b_IDIV_CON_ccc);
    INITIALIZE_BUILTIN1(237,b_IS_BOOLEAN_VAR_CONSTR);
    INITIALIZE_BUILTIN1(238,b_CONSTR_COES_TYPE);
    INITIALIZE_BUILTIN3(239,b_CFD_TRANSFORM_TUPLES);
    INITIALIZE_BUILTIN3(240,b_INSERT_ORDERED_ccf);
    INITIALIZE_BUILTIN2(241,b_CFD_IN_FORWARD_CHECKING);
    INITIALIZE_BUILTIN1(242,b_IS_BIGINT_c);
    INITIALIZE_BUILTIN2(243,b_CFD_DIFF_TUPLE);
    INITIALIZE_BUILTIN2(244,b_CFD_NOTIN_FORWARD_CHECKING);
    INITIALIZE_BUILTIN2(245,b_PROD_cf);
    INITIALIZE_BUILTIN2(246,b_READ_CHAR_CODE_cf);
    INITIALIZE_BUILTIN3(247,b_READ_CHAR_CODE_ccf);
    INITIALIZE_BUILTIN2(248,b_PEEK_CHAR_CODE_cf);
    INITIALIZE_BUILTIN2(249,b_WRITE_CHAR_cc);
    INITIALIZE_BUILTIN2(250,b_WRITE_CHAR_CODE_cc);
    INITIALIZE_BUILTIN2(251,b_READ_FILE_CODES_cf);
    INITIALIZE_BUILTIN1(252,b_BOOL_OR_c);
    INITIALIZE_BUILTIN3(253,b_GEN_ARG_ccf);
    INITIALIZE_BUILTIN1(254,b_BOOL_AND_c);
    INITIALIZE_BUILTIN0(255,b_FINDALL_COPY_ARGS);
#ifdef SAT
    INITIALIZE_BUILTIN1(256,b_SAT_ADD_CL_c);
#endif
    INITIALIZE_BUILTIN1(257,b_IS_STRUCT_c);
    INITIALIZE_BUILTIN1(258,b_IS_COMPOUND_c);
    INITIALIZE_BUILTIN1(259,b_IS_GROUND_c);
    INITIALIZE_BUILTIN1(260,b_IS_STRING_c);
    INITIALIZE_BUILTIN1(261,b_IS_MAP_c);
    INITIALIZE_BUILTIN1(262,b_IS_ARRAY_c);
    INITIALIZE_BUILTIN1(263,b_IS_CHAR_c);
    INITIALIZE_BUILTIN1(264,b_IS_LIST_c);
    INITIALIZE_BUILTIN3(265,b_PICAT_COMPARE_fcc);
    INITIALIZE_BUILTIN2(266,b_STRUCT_ARITY_cf);
    INITIALIZE_BUILTIN2(267,b_STRUCT_NAME_cf);
    INITIALIZE_BUILTIN3(268,b_TO_STRING_cff);
    INITIALIZE_BUILTIN3(269,b_TO_CODES_cff);
    INITIALIZE_BUILTIN3(270,b_NEW_STRUCT_ccf);
    INITIALIZE_BUILTIN1(271,b_IS_DIGIT_c);
    INITIALIZE_BUILTIN1(272,b_ATOM_CONCAT_ccf);
    INITIALIZE_BUILTIN3(273,b_PICAT_ARG_ccf);
    INITIALIZE_BUILTIN3(274,b_PICAT_SETARG_ccc);
    INITIALIZE_BUILTIN2(275,b_VARIANT_cc);
    INITIALIZE_BUILTIN1(276,b_IS_LOWERCASE_c);
    INITIALIZE_BUILTIN1(277,b_IS_UPPERCASE_c);
    INITIALIZE_BUILTIN3(278,b_GET_NEXT_PICAT_TOKEN_cff);
    INITIALIZE_BUILTIN2(279,b_READ_BYTE_cf);
    INITIALIZE_BUILTIN2(280,b_PEEK_BYTE_cf);
    INITIALIZE_BUILTIN3(281,b_READ_BYTE_ccf);
    INITIALIZE_BUILTIN2(282,b_READ_CHAR_cf);
    INITIALIZE_BUILTIN2(283,b_PEEK_CHAR_cf);
    INITIALIZE_BUILTIN3(284,b_READ_CHAR_ccf);
    INITIALIZE_BUILTIN2(285,b_READ_FILE_BYTES_cf);
    INITIALIZE_BUILTIN2(286,b_READ_FILE_CHARS_cf);
    INITIALIZE_BUILTIN2(287,b_READ_LINE_cf);
    INITIALIZE_BUILTIN2(288,b_WRITE_BYTE_cc);
    INITIALIZE_BUILTIN2(289,b_PICAT_PRINT_STRING_cc);
    INITIALIZE_BUILTIN1(290,b_SET_STRING_TO_PARSE_c);
    INITIALIZE_BUILTIN3(291,b_TO_QUOTED_STRING_cff);
    INITIALIZE_BUILTIN1(292,b_PROP_MAX_c);
    INITIALIZE_BUILTIN1(293,b_PROP_MIN_c);
    INITIALIZE_BUILTIN1(294,b_BOOL_DVAR_c);
    INITIALIZE_BUILTIN3(295,b_INSERT_ORDERED_DOWN_ccf);
    INITIALIZE_BUILTIN3(296,b_PICAT_LENGTH_cf);
	INITIALIZE_BUILTIN1(297,b_IS_ALPHA_c);
    INITIALIZE_BUILTIN3(298,b_INSERT_STATE_LIST_ccf);
    INITIALIZE_BUILTIN3(299,b_BUILD_56B_INT_ccf);
    INITIALIZE_BUILTIN2(300,b_GET_PICAT_TABLE_MAP_cf);
    INITIALIZE_BUILTIN2(301,b_GET_PICAT_GLOBAL_MAP_cf);
    INITIALIZE_BUILTIN3(302,b_PICAT_GLOBAL_MAP_PUT_ccc);
    INITIALIZE_BUILTIN3(303,b_PICAT_GLOBAL_MAP_GET_ccf);
    INITIALIZE_BUILTIN2(304,b_PICAT_TABLE_MAP_SIZE_cf);
    INITIALIZE_BUILTIN1(305,b_PICAT_TABLE_MAP_CLEAR_c);
    INITIALIZE_BUILTIN2(306,b_PICAT_GLOBAL_MAP_SIZE_cf);
    INITIALIZE_BUILTIN1(307,b_PICAT_GLOBAL_MAP_CLEAR_c);
    INITIALIZE_BUILTIN2(308,b_PICAT_TABLE_MAP_KEYS_cf);
    INITIALIZE_BUILTIN2(309,b_PICAT_TABLE_MAP_VALS_cf);
    INITIALIZE_BUILTIN2(310,b_PICAT_TABLE_MAP_LIST_cf);
    INITIALIZE_BUILTIN2(311,b_PICAT_GLOBAL_MAP_KEYS_cf);
    INITIALIZE_BUILTIN2(312,b_PICAT_GLOBAL_MAP_VALS_cf);
    INITIALIZE_BUILTIN2(313,b_PICAT_GLOBAL_MAP_LIST_cf);
    INITIALIZE_BUILTIN1(314,b_PLANNER_UPDATE_EXPLORED_DEPTH_c);
    INITIALIZE_BUILTIN3(315,b_SAT_RETRIEVE_BNUM_cff);
    INITIALIZE_BUILTIN1(316,b_SAT_GET_INC_VAR_NUM_f);
}

/*
  builtin_reached[MAXBS];

  initialize_builtin_reached(){
  int i;
  for (i=0;i<MAXBS;i++){
  builtin_reached[i] = 0;
  }
  }

  profile_builtin(i)
  int i;
  {
  if (builtin_reached[i]==1) return;
  builtin_reached[i] = 1;
  printf(" %d  ",i);
  }
********/

#ifdef WIN32
static char *arch_string = "windows";
#endif
#ifdef DARWIN
static char *arch_string = "darwin";
#endif
#ifdef unix
static char *arch_string = "unix";
#endif

//branch b_GET_ARCH_f(arch)
int b_GET_ARCH_f(arch)
    BPLONG arch;
{
    SYM_REC_PTR sym_ptr;

    sym_ptr = BP_NEW_SYM(arch_string,0);
    ASSIGN_f_atom(arch,ADDTAG(sym_ptr,ATM));
    return 1;
}

