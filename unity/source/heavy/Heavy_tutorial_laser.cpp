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

#include "Heavy_tutorial_laser.hpp"

#define Context(_c) reinterpret_cast<Heavy_tutorial_laser *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_tutorial_laser_new(double sampleRate) {
    return new Heavy_tutorial_laser(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_tutorial_laser_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_tutorial_laser(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_tutorial_laser::Heavy_tutorial_laser(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_6uv1PHnA);
  numBytes += sBiquad_k_init(&sBiquad_k_nZ5BRMa1, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_G74d5LHS, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_JawTDRl0, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_L01P9xro, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_VDiYHdiU, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_2kXlPf1i, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_awoyNSED, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VIGOmzYE, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_A7o3WhkC, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_zCIekfRk, 1000.0f);
  numBytes += cVar_init_f(&cVar_9k5aa6JV, 6.0f);
  numBytes += cBinop_init(&cBinop_61DknFda, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_HnVGaPjX, 1.0f);
  numBytes += cBinop_init(&cBinop_6UAhfC5N, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0FIIYVdI, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_uFsvFk6x, 6.0f);
  numBytes += cVar_init_f(&cVar_8fbqnXDs, 1000.0f);
  numBytes += cBinop_init(&cBinop_Y4npHpRs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_MmoTNObs, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_WhzAVxbP, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_e9gr2ilp, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_HJFGqfKT, 759232871);
  numBytes += cSlice_init(&cSlice_60DA2NWr, 1, 1);
  numBytes += sVari_init(&sVari_m1pZwtiA, 0, 0, false);
  numBytes += cVar_init_f(&cVar_GQ3O9ot3, 0.0f);
  numBytes += cIf_init(&cIf_Rys5WrzP, false);
  numBytes += cIf_init(&cIf_GGvPak1G, false);
  numBytes += cBinop_init(&cBinop_BGuUsJHd, 6000.0f); // __add
  numBytes += cRandom_init(&cRandom_S0jL0vGO, 869799893);
  numBytes += cSlice_init(&cSlice_SLpzQZB1, 1, 1);
  numBytes += cBinop_init(&cBinop_s6NC3j0G, 600.0f); // __mul
  numBytes += cBinop_init(&cBinop_49fFBan8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_G5q3gZ4f, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_jsDzk6CE, 1000.0f);
  numBytes += cBinop_init(&cBinop_gMrYlLpu, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_alD1UEWj, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ewQSVmc9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_yQspSC8x, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_UGHPaDdY, 6.0f);
  numBytes += cVar_init_f(&cVar_cgzns9wF, 0.0f);
  numBytes += cVar_init_f(&cVar_V0MSEfhy, 0.0f);
  numBytes += cVar_init_f(&cVar_frsSRzvi, 0.0f);
  numBytes += cBinop_init(&cBinop_2RUuaS0p, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ldoMtSMn, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_vMFcHUA8, 1000.0f);
  numBytes += cBinop_init(&cBinop_ovCHqB7M, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_PYHD8Pn7, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_EER7Q9JQ, 6.0f);
  numBytes += cBinop_init(&cBinop_4HEVZbbI, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_GmFyqLY8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_pDVJVmf3, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_Ol1d12fe, 0.0f);
  numBytes += cBinop_init(&cBinop_k8nrucTZ, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_QRs4mnEr, 20.0f);
  numBytes += cBinop_init(&cBinop_Joc0IAJw, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_ugTnIQOK, 0.0f);
  numBytes += cVar_init_f(&cVar_6f4f8tuu, 0.0f);
  numBytes += cBinop_init(&cBinop_I1uYVk9J, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_tiTVOk83, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_KnFcAw7j, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_ekstw2Td, 0.0f);
  numBytes += cVar_init_f(&cVar_nnvRYwQu, 0.0f);
  numBytes += cBinop_init(&cBinop_UI4hwqir, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_FtllL4cI, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_DfUEaF5e, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_XkwzoYhU, 20.0f);
  numBytes += cVar_init_f(&cVar_hJiEyPtx, 0.0f);
  numBytes += cSlice_init(&cSlice_dtsbW6Qm, 0, 1);
  numBytes += cSlice_init(&cSlice_p585PrEN, 1, 1);
  numBytes += cSlice_init(&cSlice_EOm50D8I, 1, -1);
  numBytes += cSlice_init(&cSlice_G1Q3Y0Cv, 1, -1);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_tutorial_laser::~Heavy_tutorial_laser() {
  // nothing to free
}

HvTable *Heavy_tutorial_laser::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_tutorial_laser::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JYFlGmiT_sendMessage);
      break;
    }
    case 0xBA292486: { // base_frequency
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1Nt4D1Z2_sendMessage);
      break;
    }
    case 0xE9397404: { // filter_res
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tHtChYvB_sendMessage);
      break;
    }
    case 0xAD78F8FA: { // random_amount
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RMSlcykQ_sendMessage);
      break;
    }
    case 0xEAD0B378: { // trigger
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_STWA3xxx_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_tutorial_laser::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "random_amount";
        info->hash = 0xAD78F8FA;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 5000.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 1: {
        info->name = "trigger";
        info->hash = 0xEAD0B378;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 2: {
        info->name = "base_frequency";
        info->hash = 0xBA292486;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 60.0f;
        info->maxVal = 22000.0f;
        info->defaultVal = 6000.0f;
        break;
      }
      case 3: {
        info->name = "filter_res";
        info->hash = 0xE9397404;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 500.0f;
        info->defaultVal = 20.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 4;
}



/*
 * Send Function Implementations
 */


void Heavy_tutorial_laser::cBinop_VDiYHdiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_61DknFda, HV_BINOP_MULTIPLY, 1, m, &cBinop_61DknFda_sendMessage);
}

void Heavy_tutorial_laser::cBinop_2kXlPf1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VDiYHdiU, HV_BINOP_ADD, 1, m, &cBinop_VDiYHdiU_sendMessage);
}

void Heavy_tutorial_laser::cBinop_awoyNSED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wzaIyzZW_sendMessage);
}

void Heavy_tutorial_laser::cSystem_D7ywxIff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VIGOmzYE, HV_BINOP_DIVIDE, 1, m, &cBinop_VIGOmzYE_sendMessage);
}

void Heavy_tutorial_laser::cMsg_skW7XlaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D7ywxIff_sendMessage);
}

void Heavy_tutorial_laser::cBinop_VIGOmzYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2kXlPf1i, HV_BINOP_MULTIPLY, 1, m, &cBinop_2kXlPf1i_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_vECKB5M4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_A7o3WhkC, HV_BINOP_DIVIDE, 0, m, &cBinop_A7o3WhkC_sendMessage);
}

void Heavy_tutorial_laser::cBinop_M9nRj7Og_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_f4kIBQCc_sendMessage);
}

void Heavy_tutorial_laser::cBinop_5t8TCAWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A7o3WhkC, HV_BINOP_DIVIDE, 1, m, &cBinop_A7o3WhkC_sendMessage);
}

void Heavy_tutorial_laser::cBinop_ZGYyLYTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DoMEYk70_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VDiYHdiU, HV_BINOP_ADD, 0, m, &cBinop_VDiYHdiU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_yETxP7aP_sendMessage);
}

void Heavy_tutorial_laser::cBinop_yETxP7aP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_61DknFda, HV_BINOP_MULTIPLY, 0, m, &cBinop_61DknFda_sendMessage);
}

void Heavy_tutorial_laser::cBinop_muBpYVV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_tsQNLYzJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_awoyNSED, HV_BINOP_MULTIPLY, 0, m, &cBinop_awoyNSED_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2kXlPf1i, HV_BINOP_MULTIPLY, 0, m, &cBinop_2kXlPf1i_sendMessage);
}

void Heavy_tutorial_laser::cUnop_vECKB5M4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_rOdPrOiH_sendMessage);
}

void Heavy_tutorial_laser::cBinop_f4kIBQCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_G74d5LHS, 5, m);
}

void Heavy_tutorial_laser::cBinop_A7o3WhkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ZGYyLYTO_sendMessage);
}

void Heavy_tutorial_laser::cBinop_DoMEYk70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_muBpYVV5_sendMessage);
}

void Heavy_tutorial_laser::cVar_zCIekfRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_3q2Wxj5h_sendMessage);
}

void Heavy_tutorial_laser::cBinop_3q2Wxj5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VIGOmzYE, HV_BINOP_DIVIDE, 0, m, &cBinop_VIGOmzYE_sendMessage);
}

void Heavy_tutorial_laser::cBinop_rOdPrOiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_awoyNSED, HV_BINOP_MULTIPLY, 1, m, &cBinop_awoyNSED_sendMessage);
}

void Heavy_tutorial_laser::cBinop_wzaIyzZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_G74d5LHS, 4, m);
}

void Heavy_tutorial_laser::cCast_1cWSqmO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zCIekfRk, 0, m, &cVar_zCIekfRk_sendMessage);
}

void Heavy_tutorial_laser::cBinop_tsQNLYzJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_M9nRj7Og_sendMessage);
}

void Heavy_tutorial_laser::cVar_9k5aa6JV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_5t8TCAWc_sendMessage);
}

void Heavy_tutorial_laser::cBinop_61DknFda_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_G74d5LHS, 1, m);
}

void Heavy_tutorial_laser::cVar_HnVGaPjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_EpetZqVk_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_GGvPak1G, 1, m, &cIf_GGvPak1G_sendMessage);
}

void Heavy_tutorial_laser::cBinop_EpetZqVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HnVGaPjX, 1, m, &cVar_HnVGaPjX_sendMessage);
}

void Heavy_tutorial_laser::cBinop_6UAhfC5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nZ5BRMa1, 1, m);
}

void Heavy_tutorial_laser::cBinop_MkRHqBbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_f5HYTuPv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WhzAVxbP, HV_BINOP_MULTIPLY, 0, m, &cBinop_WhzAVxbP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4npHpRs, HV_BINOP_MULTIPLY, 0, m, &cBinop_Y4npHpRs_sendMessage);
}

void Heavy_tutorial_laser::cBinop_6pu9J4Qx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MkRHqBbn_sendMessage);
}

void Heavy_tutorial_laser::cBinop_GswX4Ht4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6pu9J4Qx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MmoTNObs, HV_BINOP_ADD, 0, m, &cBinop_MmoTNObs_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_fkLWp0RX_sendMessage);
}

void Heavy_tutorial_laser::cBinop_0FIIYVdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4npHpRs, HV_BINOP_MULTIPLY, 1, m, &cBinop_Y4npHpRs_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_cTPYRA1a_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_e9gr2ilp, HV_BINOP_DIVIDE, 0, m, &cBinop_e9gr2ilp_sendMessage);
}

void Heavy_tutorial_laser::cBinop_f5HYTuPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6rQBwIjX_sendMessage);
}

void Heavy_tutorial_laser::cVar_uFsvFk6x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_D97RTU6i_sendMessage);
}

void Heavy_tutorial_laser::cBinop_fkLWp0RX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6UAhfC5N, HV_BINOP_MULTIPLY, 0, m, &cBinop_6UAhfC5N_sendMessage);
}

void Heavy_tutorial_laser::cBinop_UQVXApkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nZ5BRMa1, 5, m);
}

void Heavy_tutorial_laser::cSystem_NhKUIET0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0FIIYVdI, HV_BINOP_DIVIDE, 1, m, &cBinop_0FIIYVdI_sendMessage);
}

void Heavy_tutorial_laser::cMsg_wBE7Sc6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NhKUIET0_sendMessage);
}

void Heavy_tutorial_laser::cBinop_D97RTU6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e9gr2ilp, HV_BINOP_DIVIDE, 1, m, &cBinop_e9gr2ilp_sendMessage);
}

void Heavy_tutorial_laser::cVar_8fbqnXDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_aruDH3rj_sendMessage);
}

void Heavy_tutorial_laser::cBinop_6rQBwIjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UQVXApkU_sendMessage);
}

void Heavy_tutorial_laser::cBinop_eri19ZTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nZ5BRMa1, 4, m);
}

void Heavy_tutorial_laser::cBinop_KoFizdYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WhzAVxbP, HV_BINOP_MULTIPLY, 1, m, &cBinop_WhzAVxbP_sendMessage);
}

void Heavy_tutorial_laser::cBinop_Y4npHpRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MmoTNObs, HV_BINOP_ADD, 1, m, &cBinop_MmoTNObs_sendMessage);
}

void Heavy_tutorial_laser::cBinop_MmoTNObs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6UAhfC5N, HV_BINOP_MULTIPLY, 1, m, &cBinop_6UAhfC5N_sendMessage);
}

void Heavy_tutorial_laser::cBinop_aruDH3rj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0FIIYVdI, HV_BINOP_DIVIDE, 0, m, &cBinop_0FIIYVdI_sendMessage);
}

void Heavy_tutorial_laser::cUnop_cTPYRA1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_KoFizdYO_sendMessage);
}

void Heavy_tutorial_laser::cBinop_WhzAVxbP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_eri19ZTt_sendMessage);
}

void Heavy_tutorial_laser::cCast_BH6i0O4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8fbqnXDs, 0, m, &cVar_8fbqnXDs_sendMessage);
}

void Heavy_tutorial_laser::cBinop_e9gr2ilp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_GswX4Ht4_sendMessage);
}

void Heavy_tutorial_laser::cMsg_5uieYsiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_6uv1PHnA, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 250.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_6uv1PHnA, 0, m, NULL);
}

void Heavy_tutorial_laser::cRandom_HJFGqfKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_njm4VCRK_sendMessage);
}

void Heavy_tutorial_laser::cBinop_njm4VCRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FSm7tCB2_sendMessage);
}

void Heavy_tutorial_laser::cUnop_FSm7tCB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fTrDJqYd_sendMessage(_c, 0, m);
}

void Heavy_tutorial_laser::cSwitchcase_MAkJ4T4h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_60DA2NWr, 0, m, &cSlice_60DA2NWr_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HJFGqfKT, 0, m, &cRandom_HJFGqfKT_sendMessage);
      break;
    }
  }
}

void Heavy_tutorial_laser::cSlice_60DA2NWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HJFGqfKT, 1, m, &cRandom_HJFGqfKT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_tutorial_laser::cMsg_fTrDJqYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_m1pZwtiA, m);
}

void Heavy_tutorial_laser::cVar_GQ3O9ot3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uFsvFk6x, 0, m, &cVar_uFsvFk6x_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BH6i0O4U_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9k5aa6JV, 0, m, &cVar_9k5aa6JV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1cWSqmO7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EER7Q9JQ, 0, m, &cVar_EER7Q9JQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KVfsy2jK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UGHPaDdY, 0, m, &cVar_UGHPaDdY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XzbWC1ap_sendMessage);
}

void Heavy_tutorial_laser::cReceive_RMSlcykQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s6NC3j0G, HV_BINOP_MULTIPLY, 1, m, &cBinop_s6NC3j0G_sendMessage);
}

void Heavy_tutorial_laser::cReceive_STWA3xxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_frsSRzvi, 0, m, &cVar_frsSRzvi_sendMessage);
}

void Heavy_tutorial_laser::cIf_Rys5WrzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_tutorial_laser::cReceive_tHtChYvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GQ3O9ot3, 0, m, &cVar_GQ3O9ot3_sendMessage);
}

void Heavy_tutorial_laser::cReceive_1Nt4D1Z2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BGuUsJHd, HV_BINOP_ADD, 1, m, &cBinop_BGuUsJHd_sendMessage);
}

void Heavy_tutorial_laser::cMsg_k7XjSE8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  cSwitchcase_6DRSx9G2_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.0f);
  msg_setFloat(m, 1, 300.0f);
  cSwitchcase_6DRSx9G2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_tutorial_laser::cIf_GGvPak1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_t0dJ1Ock_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_tutorial_laser::cBinop_BGuUsJHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k7XjSE8f_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cgzns9wF, 0, m, &cVar_cgzns9wF_sendMessage);
}

void Heavy_tutorial_laser::cRandom_S0jL0vGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s6NC3j0G, HV_BINOP_MULTIPLY, 0, m, &cBinop_s6NC3j0G_sendMessage);
}

void Heavy_tutorial_laser::cSlice_SLpzQZB1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_S0jL0vGO, 1, m, &cRandom_S0jL0vGO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_tutorial_laser::cBinop_s6NC3j0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_91iEiBPp_sendMessage);
}

void Heavy_tutorial_laser::cSwitchcase_WBnLSuyO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SLpzQZB1, 0, m, &cSlice_SLpzQZB1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_S0jL0vGO, 0, m, &cRandom_S0jL0vGO_sendMessage);
      break;
    }
  }
}

void Heavy_tutorial_laser::cUnop_91iEiBPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BGuUsJHd, HV_BINOP_ADD, 0, m, &cBinop_BGuUsJHd_sendMessage);
}

void Heavy_tutorial_laser::cBinop_l9Y4gKGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_alD1UEWj, HV_BINOP_DIVIDE, 0, m, &cBinop_alD1UEWj_sendMessage);
}

void Heavy_tutorial_laser::cBinop_49fFBan8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_L01P9xro, 1, m);
}

void Heavy_tutorial_laser::cBinop_kIKOAeyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G5q3gZ4f, HV_BINOP_DIVIDE, 1, m, &cBinop_G5q3gZ4f_sendMessage);
}

void Heavy_tutorial_laser::cBinop_G5q3gZ4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IIZnMz3E_sendMessage);
}

void Heavy_tutorial_laser::cBinop_G9paiiD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OBl6N9jo_sendMessage);
}

void Heavy_tutorial_laser::cVar_jsDzk6CE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_l9Y4gKGR_sendMessage);
}

void Heavy_tutorial_laser::cBinop_kaom0bzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_49fFBan8, HV_BINOP_MULTIPLY, 0, m, &cBinop_49fFBan8_sendMessage);
}

void Heavy_tutorial_laser::cBinop_bAdnsPzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_L01P9xro, 5, m);
}

void Heavy_tutorial_laser::cBinop_gMrYlLpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_49fFBan8, HV_BINOP_MULTIPLY, 1, m, &cBinop_49fFBan8_sendMessage);
}

void Heavy_tutorial_laser::cBinop_IIZnMz3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_G9paiiD3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gMrYlLpu, HV_BINOP_ADD, 0, m, &cBinop_gMrYlLpu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_kaom0bzs_sendMessage);
}

void Heavy_tutorial_laser::cCast_XzbWC1ap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jsDzk6CE, 0, m, &cVar_jsDzk6CE_sendMessage);
}

void Heavy_tutorial_laser::cBinop_Q0hg3Mfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQspSC8x, HV_BINOP_MULTIPLY, 1, m, &cBinop_yQspSC8x_sendMessage);
}

void Heavy_tutorial_laser::cUnop_b7FALOZI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Q0hg3Mfe_sendMessage);
}

void Heavy_tutorial_laser::cBinop_alD1UEWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ewQSVmc9, HV_BINOP_MULTIPLY, 1, m, &cBinop_ewQSVmc9_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_b7FALOZI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_G5q3gZ4f, HV_BINOP_DIVIDE, 0, m, &cBinop_G5q3gZ4f_sendMessage);
}

void Heavy_tutorial_laser::cBinop_OBl6N9jo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_1zrcDLHE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQspSC8x, HV_BINOP_MULTIPLY, 0, m, &cBinop_yQspSC8x_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ewQSVmc9, HV_BINOP_MULTIPLY, 0, m, &cBinop_ewQSVmc9_sendMessage);
}

void Heavy_tutorial_laser::cBinop_ewQSVmc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gMrYlLpu, HV_BINOP_ADD, 1, m, &cBinop_gMrYlLpu_sendMessage);
}

void Heavy_tutorial_laser::cSystem_BWgsD4ol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_alD1UEWj, HV_BINOP_DIVIDE, 1, m, &cBinop_alD1UEWj_sendMessage);
}

void Heavy_tutorial_laser::cMsg_98Erw8X2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BWgsD4ol_sendMessage);
}

void Heavy_tutorial_laser::cBinop_1zrcDLHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Z4HAuTxo_sendMessage);
}

void Heavy_tutorial_laser::cBinop_yQspSC8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_D3r2OVEZ_sendMessage);
}

void Heavy_tutorial_laser::cBinop_Z4HAuTxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bAdnsPzc_sendMessage);
}

void Heavy_tutorial_laser::cBinop_D3r2OVEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_L01P9xro, 4, m);
}

void Heavy_tutorial_laser::cVar_UGHPaDdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_kIKOAeyI_sendMessage);
}

void Heavy_tutorial_laser::cVar_cgzns9wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_tutorial_laser::cVar_V0MSEfhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_tutorial_laser::cVar_frsSRzvi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GGvPak1G, 0, m, &cIf_GGvPak1G_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HnVGaPjX, 0, m, &cVar_HnVGaPjX_sendMessage);
}

void Heavy_tutorial_laser::cBinop_rZ6tHTKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_NBBFrI7n_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PYHD8Pn7, HV_BINOP_MULTIPLY, 0, m, &cBinop_PYHD8Pn7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2RUuaS0p, HV_BINOP_MULTIPLY, 0, m, &cBinop_2RUuaS0p_sendMessage);
}

void Heavy_tutorial_laser::cBinop_76QCmD8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4HEVZbbI, HV_BINOP_DIVIDE, 1, m, &cBinop_4HEVZbbI_sendMessage);
}

void Heavy_tutorial_laser::cBinop_snlAinLW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GmFyqLY8, HV_BINOP_MULTIPLY, 0, m, &cBinop_GmFyqLY8_sendMessage);
}

void Heavy_tutorial_laser::cBinop_Oa8KZ8Us_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_rZ6tHTKp_sendMessage);
}

void Heavy_tutorial_laser::cSystem_1FKZuCdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ovCHqB7M, HV_BINOP_DIVIDE, 1, m, &cBinop_ovCHqB7M_sendMessage);
}

void Heavy_tutorial_laser::cMsg_DbZMIJSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1FKZuCdV_sendMessage);
}

void Heavy_tutorial_laser::cCast_KVfsy2jK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vMFcHUA8, 0, m, &cVar_vMFcHUA8_sendMessage);
}

void Heavy_tutorial_laser::cBinop_zkXAcqBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Oa8KZ8Us_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ldoMtSMn, HV_BINOP_ADD, 0, m, &cBinop_ldoMtSMn_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_snlAinLW_sendMessage);
}

void Heavy_tutorial_laser::cBinop_2RUuaS0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ldoMtSMn, HV_BINOP_ADD, 1, m, &cBinop_ldoMtSMn_sendMessage);
}

void Heavy_tutorial_laser::cBinop_PfoAb5Bj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PYHD8Pn7, HV_BINOP_MULTIPLY, 1, m, &cBinop_PYHD8Pn7_sendMessage);
}

void Heavy_tutorial_laser::cBinop_ldoMtSMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GmFyqLY8, HV_BINOP_MULTIPLY, 1, m, &cBinop_GmFyqLY8_sendMessage);
}

void Heavy_tutorial_laser::cBinop_vHfshZqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JawTDRl0, 4, m);
}

void Heavy_tutorial_laser::cVar_vMFcHUA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_CwcQyLwM_sendMessage);
}

void Heavy_tutorial_laser::cBinop_iFJTzrqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wErKKt9I_sendMessage);
}

void Heavy_tutorial_laser::cBinop_ovCHqB7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2RUuaS0p, HV_BINOP_MULTIPLY, 1, m, &cBinop_2RUuaS0p_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_3H2D7uoq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4HEVZbbI, HV_BINOP_DIVIDE, 0, m, &cBinop_4HEVZbbI_sendMessage);
}

void Heavy_tutorial_laser::cBinop_PYHD8Pn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vHfshZqc_sendMessage);
}

void Heavy_tutorial_laser::cVar_EER7Q9JQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_76QCmD8W_sendMessage);
}

void Heavy_tutorial_laser::cBinop_CwcQyLwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ovCHqB7M, HV_BINOP_DIVIDE, 0, m, &cBinop_ovCHqB7M_sendMessage);
}

void Heavy_tutorial_laser::cBinop_4HEVZbbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zkXAcqBs_sendMessage);
}

void Heavy_tutorial_laser::cUnop_3H2D7uoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_PfoAb5Bj_sendMessage);
}

void Heavy_tutorial_laser::cBinop_wErKKt9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JawTDRl0, 5, m);
}

void Heavy_tutorial_laser::cBinop_NBBFrI7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iFJTzrqf_sendMessage);
}

void Heavy_tutorial_laser::cBinop_GmFyqLY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JawTDRl0, 1, m);
}

void Heavy_tutorial_laser::cReceive_JYFlGmiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q3F0kl04_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QRs4mnEr, 0, m, &cVar_QRs4mnEr_sendMessage);
  cSwitchcase_MAkJ4T4h_onMessage(_c, NULL, 0, m, NULL);
  cMsg_CcosNZET_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ekstw2Td, 0, m, &cVar_ekstw2Td_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XkwzoYhU, 0, m, &cVar_XkwzoYhU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uFsvFk6x, 0, m, &cVar_uFsvFk6x_sendMessage);
  cMsg_wBE7Sc6h_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8fbqnXDs, 0, m, &cVar_8fbqnXDs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EER7Q9JQ, 0, m, &cVar_EER7Q9JQ_sendMessage);
  cMsg_DbZMIJSo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vMFcHUA8, 0, m, &cVar_vMFcHUA8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9k5aa6JV, 0, m, &cVar_9k5aa6JV_sendMessage);
  cMsg_skW7XlaV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zCIekfRk, 0, m, &cVar_zCIekfRk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UGHPaDdY, 0, m, &cVar_UGHPaDdY_sendMessage);
  cMsg_98Erw8X2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jsDzk6CE, 0, m, &cVar_jsDzk6CE_sendMessage);
}

void Heavy_tutorial_laser::cCast_t0dJ1Ock_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5uieYsiy_sendMessage(_c, 0, m);
  cSwitchcase_WBnLSuyO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_tutorial_laser::cCast_QDOk6EDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hJiEyPtx, 0, m, &cVar_hJiEyPtx_sendMessage);
}

void Heavy_tutorial_laser::cBinop_pDVJVmf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_F24zE9zk_sendMessage);
}

void Heavy_tutorial_laser::cBinop_F24zE9zk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KnFcAw7j, HV_BINOP_SUBTRACT, 1, m, &cBinop_KnFcAw7j_sendMessage);
}

void Heavy_tutorial_laser::cMsg_QluutgBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pDVJVmf3, HV_BINOP_MULTIPLY, 0, m, &cBinop_pDVJVmf3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Joc0IAJw, HV_BINOP_DIVIDE, 1, m, &cBinop_Joc0IAJw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QRs4mnEr, 0, m, &cVar_QRs4mnEr_sendMessage);
}

void Heavy_tutorial_laser::cSwitchcase_Bb92mduM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_4Nr8EECV_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_4Nr8EECV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SlrD3E1F_sendMessage);
      break;
    }
  }
}

void Heavy_tutorial_laser::cSystem_fUsDEppM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WyZ7XV3Z_sendMessage);
}

void Heavy_tutorial_laser::cMsg_q3F0kl04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fUsDEppM_sendMessage);
}

void Heavy_tutorial_laser::cDelay_Ol1d12fe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ol1d12fe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ol1d12fe, 0, m, &cDelay_Ol1d12fe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ugTnIQOK, 0, m, &cVar_ugTnIQOK_sendMessage);
}

void Heavy_tutorial_laser::cBinop_0tQ1XXaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ol1d12fe, 2, m, &cDelay_Ol1d12fe_sendMessage);
}

void Heavy_tutorial_laser::cBinop_k8nrucTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_0tQ1XXaz_sendMessage);
}

void Heavy_tutorial_laser::cVar_QRs4mnEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k8nrucTZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_k8nrucTZ_sendMessage);
}

void Heavy_tutorial_laser::cBinop_WyZ7XV3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k8nrucTZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_k8nrucTZ_sendMessage);
}

void Heavy_tutorial_laser::cCast_SlrD3E1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4Nr8EECV_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ol1d12fe, 0, m, &cDelay_Ol1d12fe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ugTnIQOK, 0, m, &cVar_ugTnIQOK_sendMessage);
}

void Heavy_tutorial_laser::cMsg_4Nr8EECV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ol1d12fe, 0, m, &cDelay_Ol1d12fe_sendMessage);
}

void Heavy_tutorial_laser::cCast_u080xMMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s14OKUfh_sendMessage(_c, 0, m);
}

void Heavy_tutorial_laser::cBinop_Joc0IAJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I1uYVk9J, HV_BINOP_DIVIDE, 1, m, &cBinop_I1uYVk9J_sendMessage);
}

void Heavy_tutorial_laser::cBinop_4YdY1flz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XhYsFE6F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_tutorial_laser::cVar_ugTnIQOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KnFcAw7j, HV_BINOP_SUBTRACT, 0, m, &cBinop_KnFcAw7j_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_4YdY1flz_sendMessage);
}

void Heavy_tutorial_laser::cVar_6f4f8tuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_82onErnw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jfeKxl34_sendMessage);
}

void Heavy_tutorial_laser::cCast_IkFiAGLE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f8ABTOi4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FtllL4cI, HV_BINOP_ADD, 0, m, &cBinop_FtllL4cI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nnvRYwQu, 1, m, &cVar_nnvRYwQu_sendMessage);
}

void Heavy_tutorial_laser::cCast_Eyyw1uzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DfUEaF5e, HV_BINOP_SUBTRACT, 0, m, &cBinop_DfUEaF5e_sendMessage);
}

void Heavy_tutorial_laser::cMsg_HgGg8lTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Bb92mduM_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FtllL4cI, HV_BINOP_ADD, 1, m, &cBinop_FtllL4cI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tiTVOk83, HV_BINOP_ADD, 1, m, &cBinop_tiTVOk83_sendMessage);
}

void Heavy_tutorial_laser::cBinop_I1uYVk9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FtllL4cI, HV_BINOP_ADD, 1, m, &cBinop_FtllL4cI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tiTVOk83, HV_BINOP_ADD, 1, m, &cBinop_tiTVOk83_sendMessage);
}

void Heavy_tutorial_laser::cCast_jfeKxl34_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Joc0IAJw, HV_BINOP_DIVIDE, 0, m, &cBinop_Joc0IAJw_sendMessage);
}

void Heavy_tutorial_laser::cBinop_tiTVOk83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nnvRYwQu, 1, m, &cVar_nnvRYwQu_sendMessage);
}

void Heavy_tutorial_laser::cMsg_iLJpxqBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_6f4f8tuu, 1, m, &cVar_6f4f8tuu_sendMessage);
}

void Heavy_tutorial_laser::cBinop_KnFcAw7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ugTnIQOK, 1, m, &cVar_ugTnIQOK_sendMessage);
}

void Heavy_tutorial_laser::cCast_nAFfEcbz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QluutgBP_sendMessage(_c, 0, m);
}

void Heavy_tutorial_laser::cSwitchcase_Qvju91rT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nAFfEcbz_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pDVJVmf3, HV_BINOP_MULTIPLY, 0, m, &cBinop_pDVJVmf3_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_Joc0IAJw, HV_BINOP_DIVIDE, 1, m, &cBinop_Joc0IAJw_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_QRs4mnEr, 0, m, &cVar_QRs4mnEr_sendMessage);
      break;
    }
  }
}

void Heavy_tutorial_laser::cCast_8flguAe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HgGg8lTq_sendMessage(_c, 0, m);
}

void Heavy_tutorial_laser::cVar_ekstw2Td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DfUEaF5e, HV_BINOP_SUBTRACT, 1, m, &cBinop_DfUEaF5e_sendMessage);
}

void Heavy_tutorial_laser::cVar_nnvRYwQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tiTVOk83, HV_BINOP_ADD, 0, m, &cBinop_tiTVOk83_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FtllL4cI, HV_BINOP_ADD, 0, m, &cBinop_FtllL4cI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_V0MSEfhy, 0, m, &cVar_V0MSEfhy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8fbqnXDs, 0, m, &cVar_8fbqnXDs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zCIekfRk, 0, m, &cVar_zCIekfRk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vMFcHUA8, 0, m, &cVar_vMFcHUA8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jsDzk6CE, 0, m, &cVar_jsDzk6CE_sendMessage);
}

void Heavy_tutorial_laser::cBinop_UI4hwqir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_t1YsCdY8_sendMessage);
}

void Heavy_tutorial_laser::cCast_f8ABTOi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HgGg8lTq_sendMessage(_c, 0, m);
}

void Heavy_tutorial_laser::cBinop_t1YsCdY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ugTnIQOK, 1, m, &cVar_ugTnIQOK_sendMessage);
}

void Heavy_tutorial_laser::cCast_82onErnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UI4hwqir, HV_BINOP_MULTIPLY, 0, m, &cBinop_UI4hwqir_sendMessage);
}

void Heavy_tutorial_laser::cBinop_FtllL4cI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ekstw2Td, 0, m, &cVar_ekstw2Td_sendMessage);
}

void Heavy_tutorial_laser::cBinop_DfUEaF5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I1uYVk9J, HV_BINOP_DIVIDE, 0, m, &cBinop_I1uYVk9J_sendMessage);
}

void Heavy_tutorial_laser::cCast_hCH9Q5Tq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8flguAe9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QDOk6EDc_sendMessage);
}

void Heavy_tutorial_laser::cCast_81AvGmoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nnvRYwQu, 0, m, &cVar_nnvRYwQu_sendMessage);
}

void Heavy_tutorial_laser::cSwitchcase_XhYsFE6F_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_81AvGmoS_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hCH9Q5Tq_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_tutorial_laser::cCast_zrJs5TeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iLJpxqBv_sendMessage(_c, 0, m);
}

void Heavy_tutorial_laser::cMsg_CcosNZET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VYugz0ND_sendMessage);
}

void Heavy_tutorial_laser::cSystem_VYugz0ND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pDVJVmf3, HV_BINOP_MULTIPLY, 1, m, &cBinop_pDVJVmf3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UI4hwqir, HV_BINOP_MULTIPLY, 1, m, &cBinop_UI4hwqir_sendMessage);
}

void Heavy_tutorial_laser::cCast_yIrXtSTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hJiEyPtx, 1, m, &cVar_hJiEyPtx_sendMessage);
}

void Heavy_tutorial_laser::cCast_3v4Vc9PD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_msEwaeiB_sendMessage(_c, 0, m);
}

void Heavy_tutorial_laser::cVar_XkwzoYhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Qvju91rT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_tutorial_laser::cVar_hJiEyPtx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nnvRYwQu, 0, m, &cVar_nnvRYwQu_sendMessage);
}

void Heavy_tutorial_laser::cCast_UquGtnGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6f4f8tuu, 0, m, &cVar_6f4f8tuu_sendMessage);
}

void Heavy_tutorial_laser::cSlice_dtsbW6Qm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yIrXtSTb_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eyyw1uzS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_tutorial_laser::cSlice_p585PrEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_82onErnw_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jfeKxl34_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_tutorial_laser::cMsg_s14OKUfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Bb92mduM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_tutorial_laser::cMsg_msEwaeiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Bb92mduM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_tutorial_laser::cSlice_EOm50D8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_msEwaeiB_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_msEwaeiB_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_tutorial_laser::cSlice_G1Q3Y0Cv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3v4Vc9PD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IkFiAGLE_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3v4Vc9PD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IkFiAGLE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_tutorial_laser::cSwitchcase_6DRSx9G2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_EOm50D8I, 0, m, &cSlice_EOm50D8I_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_G1Q3Y0Cv, 0, m, &cSlice_G1Q3Y0Cv_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UquGtnGo_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_p585PrEN, 0, m, &cSlice_p585PrEN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dtsbW6Qm, 0, m, &cSlice_dtsbW6Qm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u080xMMl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zrJs5TeH_sendMessage);
      break;
    }
  }
}




/*
 * Context Process Implementation
 */

int Heavy_tutorial_laser::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_i(&sVari_m1pZwtiA, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_m1pZwtiA, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_6uv1PHnA, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_nZ5BRMa1, VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_G74d5LHS, VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_JawTDRl0, VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_L01P9xro, VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_tutorial_laser::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_tutorial_laser::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
