/**
 * Copyright (c) 2018 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_TUTORIAL_LASER_HPP_
#define _HEAVY_CONTEXT_TUTORIAL_LASER_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlRandom.h"
#include "HvSignalLine.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvControlDelay.h"
#include "HvControlIf.h"
#include "HvSignalBiquad.h"
#include "HvMath.h"
#include "HvControlUnop.h"
#include "HvControlCast.h"

class Heavy_tutorial_laser : public HeavyContext {

 public:
  Heavy_tutorial_laser(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_tutorial_laser();

  const char *getName() override { return "tutorial_laser"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        BASE_FREQUENCY = 0xBA292486, // base_frequency
        FILTER_RES = 0xE9397404, // filter_res
        RANDOM_AMOUNT = 0xAD78F8FA, // random_amount
        TRIGGER = 0xEAD0B378, // trigger
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cBinop_VDiYHdiU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2kXlPf1i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_awoyNSED_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_D7ywxIff_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_skW7XlaV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VIGOmzYE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M9nRj7Og_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5t8TCAWc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZGYyLYTO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yETxP7aP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_muBpYVV5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_vECKB5M4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_f4kIBQCc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_A7o3WhkC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DoMEYk70_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zCIekfRk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3q2Wxj5h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rOdPrOiH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wzaIyzZW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1cWSqmO7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tsQNLYzJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9k5aa6JV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_61DknFda_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HnVGaPjX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EpetZqVk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6UAhfC5N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MkRHqBbn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6pu9J4Qx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GswX4Ht4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0FIIYVdI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_f5HYTuPv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uFsvFk6x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fkLWp0RX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UQVXApkU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_NhKUIET0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wBE7Sc6h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D97RTU6i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8fbqnXDs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6rQBwIjX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eri19ZTt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KoFizdYO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y4npHpRs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MmoTNObs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aruDH3rj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_cTPYRA1a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WhzAVxbP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BH6i0O4U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e9gr2ilp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5uieYsiy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_HJFGqfKT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_njm4VCRK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_FSm7tCB2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_MAkJ4T4h_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_60DA2NWr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fTrDJqYd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GQ3O9ot3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_RMSlcykQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_STWA3xxx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Rys5WrzP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_tHtChYvB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1Nt4D1Z2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_k7XjSE8f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_GGvPak1G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BGuUsJHd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_S0jL0vGO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_SLpzQZB1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s6NC3j0G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_WBnLSuyO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cUnop_91iEiBPp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l9Y4gKGR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_49fFBan8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kIKOAeyI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G5q3gZ4f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G9paiiD3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jsDzk6CE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kaom0bzs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bAdnsPzc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gMrYlLpu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IIZnMz3E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XzbWC1ap_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q0hg3Mfe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_b7FALOZI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_alD1UEWj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OBl6N9jo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ewQSVmc9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_BWgsD4ol_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_98Erw8X2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1zrcDLHE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yQspSC8x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z4HAuTxo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D3r2OVEZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UGHPaDdY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cgzns9wF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_V0MSEfhy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_frsSRzvi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rZ6tHTKp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_76QCmD8W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_snlAinLW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Oa8KZ8Us_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1FKZuCdV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DbZMIJSo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KVfsy2jK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zkXAcqBs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2RUuaS0p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PfoAb5Bj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ldoMtSMn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vHfshZqc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vMFcHUA8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iFJTzrqf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ovCHqB7M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PYHD8Pn7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EER7Q9JQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CwcQyLwM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4HEVZbbI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_3H2D7uoq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wErKKt9I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NBBFrI7n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GmFyqLY8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JYFlGmiT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_t0dJ1Ock_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QDOk6EDc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pDVJVmf3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_F24zE9zk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QluutgBP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Bb92mduM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSystem_fUsDEppM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_q3F0kl04_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Ol1d12fe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0tQ1XXaz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_k8nrucTZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QRs4mnEr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WyZ7XV3Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SlrD3E1F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4Nr8EECV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_u080xMMl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Joc0IAJw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4YdY1flz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ugTnIQOK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6f4f8tuu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IkFiAGLE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Eyyw1uzS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HgGg8lTq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_I1uYVk9J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jfeKxl34_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tiTVOk83_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iLJpxqBv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KnFcAw7j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nAFfEcbz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Qvju91rT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_8flguAe9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ekstw2Td_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nnvRYwQu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UI4hwqir_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_f8ABTOi4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_t1YsCdY8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_82onErnw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FtllL4cI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DfUEaF5e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hCH9Q5Tq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_81AvGmoS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_XhYsFE6F_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_zrJs5TeH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CcosNZET_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_VYugz0ND_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yIrXtSTb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3v4Vc9PD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XkwzoYhU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hJiEyPtx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UquGtnGo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dtsbW6Qm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_p585PrEN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_s14OKUfh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_msEwaeiB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_EOm50D8I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_G1Q3Y0Cv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_6DRSx9G2_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);

  // objects
  SignalLine sLine_6uv1PHnA;
  SignalBiquad_k sBiquad_k_nZ5BRMa1;
  SignalBiquad_k sBiquad_k_G74d5LHS;
  SignalBiquad_k sBiquad_k_JawTDRl0;
  SignalBiquad_k sBiquad_k_L01P9xro;
  ControlBinop cBinop_VDiYHdiU;
  ControlBinop cBinop_2kXlPf1i;
  ControlBinop cBinop_awoyNSED;
  ControlBinop cBinop_VIGOmzYE;
  ControlBinop cBinop_M9nRj7Og;
  ControlBinop cBinop_5t8TCAWc;
  ControlBinop cBinop_ZGYyLYTO;
  ControlBinop cBinop_yETxP7aP;
  ControlBinop cBinop_muBpYVV5;
  ControlBinop cBinop_f4kIBQCc;
  ControlBinop cBinop_A7o3WhkC;
  ControlBinop cBinop_DoMEYk70;
  ControlVar cVar_zCIekfRk;
  ControlBinop cBinop_3q2Wxj5h;
  ControlBinop cBinop_rOdPrOiH;
  ControlBinop cBinop_wzaIyzZW;
  ControlBinop cBinop_tsQNLYzJ;
  ControlVar cVar_9k5aa6JV;
  ControlBinop cBinop_61DknFda;
  ControlVar cVar_HnVGaPjX;
  ControlBinop cBinop_EpetZqVk;
  ControlBinop cBinop_6UAhfC5N;
  ControlBinop cBinop_MkRHqBbn;
  ControlBinop cBinop_6pu9J4Qx;
  ControlBinop cBinop_GswX4Ht4;
  ControlBinop cBinop_0FIIYVdI;
  ControlBinop cBinop_f5HYTuPv;
  ControlVar cVar_uFsvFk6x;
  ControlBinop cBinop_fkLWp0RX;
  ControlBinop cBinop_UQVXApkU;
  ControlBinop cBinop_D97RTU6i;
  ControlVar cVar_8fbqnXDs;
  ControlBinop cBinop_6rQBwIjX;
  ControlBinop cBinop_eri19ZTt;
  ControlBinop cBinop_KoFizdYO;
  ControlBinop cBinop_Y4npHpRs;
  ControlBinop cBinop_MmoTNObs;
  ControlBinop cBinop_aruDH3rj;
  ControlBinop cBinop_WhzAVxbP;
  ControlBinop cBinop_e9gr2ilp;
  ControlRandom cRandom_HJFGqfKT;
  ControlBinop cBinop_njm4VCRK;
  ControlSlice cSlice_60DA2NWr;
  SignalVari sVari_m1pZwtiA;
  ControlVar cVar_GQ3O9ot3;
  ControlIf cIf_Rys5WrzP;
  ControlIf cIf_GGvPak1G;
  ControlBinop cBinop_BGuUsJHd;
  ControlRandom cRandom_S0jL0vGO;
  ControlSlice cSlice_SLpzQZB1;
  ControlBinop cBinop_s6NC3j0G;
  ControlBinop cBinop_l9Y4gKGR;
  ControlBinop cBinop_49fFBan8;
  ControlBinop cBinop_kIKOAeyI;
  ControlBinop cBinop_G5q3gZ4f;
  ControlBinop cBinop_G9paiiD3;
  ControlVar cVar_jsDzk6CE;
  ControlBinop cBinop_kaom0bzs;
  ControlBinop cBinop_bAdnsPzc;
  ControlBinop cBinop_gMrYlLpu;
  ControlBinop cBinop_IIZnMz3E;
  ControlBinop cBinop_Q0hg3Mfe;
  ControlBinop cBinop_alD1UEWj;
  ControlBinop cBinop_OBl6N9jo;
  ControlBinop cBinop_ewQSVmc9;
  ControlBinop cBinop_1zrcDLHE;
  ControlBinop cBinop_yQspSC8x;
  ControlBinop cBinop_Z4HAuTxo;
  ControlBinop cBinop_D3r2OVEZ;
  ControlVar cVar_UGHPaDdY;
  ControlVar cVar_cgzns9wF;
  ControlVar cVar_V0MSEfhy;
  ControlVar cVar_frsSRzvi;
  ControlBinop cBinop_rZ6tHTKp;
  ControlBinop cBinop_76QCmD8W;
  ControlBinop cBinop_snlAinLW;
  ControlBinop cBinop_Oa8KZ8Us;
  ControlBinop cBinop_zkXAcqBs;
  ControlBinop cBinop_2RUuaS0p;
  ControlBinop cBinop_PfoAb5Bj;
  ControlBinop cBinop_ldoMtSMn;
  ControlBinop cBinop_vHfshZqc;
  ControlVar cVar_vMFcHUA8;
  ControlBinop cBinop_iFJTzrqf;
  ControlBinop cBinop_ovCHqB7M;
  ControlBinop cBinop_PYHD8Pn7;
  ControlVar cVar_EER7Q9JQ;
  ControlBinop cBinop_CwcQyLwM;
  ControlBinop cBinop_4HEVZbbI;
  ControlBinop cBinop_wErKKt9I;
  ControlBinop cBinop_NBBFrI7n;
  ControlBinop cBinop_GmFyqLY8;
  ControlBinop cBinop_pDVJVmf3;
  ControlBinop cBinop_F24zE9zk;
  ControlDelay cDelay_Ol1d12fe;
  ControlBinop cBinop_0tQ1XXaz;
  ControlBinop cBinop_k8nrucTZ;
  ControlVar cVar_QRs4mnEr;
  ControlBinop cBinop_WyZ7XV3Z;
  ControlBinop cBinop_Joc0IAJw;
  ControlBinop cBinop_4YdY1flz;
  ControlVar cVar_ugTnIQOK;
  ControlVar cVar_6f4f8tuu;
  ControlBinop cBinop_I1uYVk9J;
  ControlBinop cBinop_tiTVOk83;
  ControlBinop cBinop_KnFcAw7j;
  ControlVar cVar_ekstw2Td;
  ControlVar cVar_nnvRYwQu;
  ControlBinop cBinop_UI4hwqir;
  ControlBinop cBinop_t1YsCdY8;
  ControlBinop cBinop_FtllL4cI;
  ControlBinop cBinop_DfUEaF5e;
  ControlVar cVar_XkwzoYhU;
  ControlVar cVar_hJiEyPtx;
  ControlSlice cSlice_dtsbW6Qm;
  ControlSlice cSlice_p585PrEN;
  ControlSlice cSlice_EOm50D8I;
  ControlSlice cSlice_G1Q3Y0Cv;
};

#endif // _HEAVY_CONTEXT_TUTORIAL_LASER_HPP_
