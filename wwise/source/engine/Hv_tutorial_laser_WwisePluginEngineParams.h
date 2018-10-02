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

#ifndef _HV_TUTORIAL_LASER_WWISE_PLUGIN_ENGINE_PARAMS_H_
#define _HV_TUTORIAL_LASER_WWISE_PLUGIN_ENGINE_PARAMS_H_

#include <AK/SoundEngine/Common/IAkPlugin.h>
#include <AK/Tools/Common/AkAssert.h>

/** Generated RTPC IDs */

// Input Parameters
static const AkPluginParamID HV_TUTORIAL_LASER_PARAM_IN_BASE_FREQUENCY_ID = 0;
static const AkPluginParamID HV_TUTORIAL_LASER_PARAM_IN_FILTER_RES_ID = 1;
static const AkPluginParamID HV_TUTORIAL_LASER_PARAM_IN_RANDOM_AMOUNT_ID = 2;
static const AkPluginParamID HV_TUTORIAL_LASER_PARAM_IN_TRIGGER_ID = 3;

/** Parameters structure for this effect. */
struct Hv_tutorial_laser_RTPCParams {
  /** Generated Heavy Parameters */
  AkReal32 fHVParam_base_frequency;
  AkReal32 fHVParam_filter_res;
  AkReal32 fHVParam_random_amount;
  AkReal32 fHVParam_trigger;
};

/**
 * class Hv_tutorial_laser_EngineParams
 * Implementation of Heavy Wwise plugin shared parameters.
 */
class Hv_tutorial_laser_EngineParams : public AK::IAkPluginParam {
 public:
  /** Allow effect to call accessor functions for retrieving parameter values. */
  friend class Hv_tutorial_laser_WwisePluginEngine;

  /** Default Constructor. */
  Hv_tutorial_laser_EngineParams();

  /** Destructor. */
  virtual ~Hv_tutorial_laser_EngineParams();

  /** Copy constructor. */
  Hv_tutorial_laser_EngineParams(const Hv_tutorial_laser_EngineParams &in_rCopy);

  /** Create duplicate. */
  virtual IAkPluginParam *Clone(AK::IAkPluginMemAlloc *in_pAllocator);

  /** Parameters node initialization. */
  virtual AKRESULT Init(AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock,
      AkUInt32 in_uBlockSize);

  /** Terminate. */
  virtual AKRESULT Term(AK::IAkPluginMemAlloc *in_pAllocator);

  /** Set all parameters at once. */
  virtual AKRESULT SetParamsBlock(const void * in_pParamsBlock,
      AkUInt32 in_uBlockSize);

  /** Update one parameter. */
  virtual AKRESULT SetParam(AkPluginParamID in_ParamID, const void *in_pValue,
      AkUInt32 in_uParamSize);

private:
  /** Hide assignment operator. */
  Hv_tutorial_laser_EngineParams &operator=(const Hv_tutorial_laser_EngineParams &in_rCopy) = default;

  /** RTPC'd Heavy Parameter Getter Methods */
  AkReal32 GetParam_base_frequency();
  AkReal32 GetParam_filter_res();
  AkReal32 GetParam_random_amount();
  AkReal32 GetParam_trigger();

  /** RTPC Parameter structure. */
  Hv_tutorial_laser_RTPCParams m_Params;
};

/** Getter methods for generated Heavy parameters */
inline AkReal32 Hv_tutorial_laser_EngineParams::GetParam_base_frequency() {
  AkReal32 fParam_base_frequency = m_Params.fHVParam_base_frequency;
  AKASSERT(fParam_base_frequency >= 60.0 && fParam_base_frequency <= 22000.0);
  return fParam_base_frequency;
}

inline AkReal32 Hv_tutorial_laser_EngineParams::GetParam_filter_res() {
  AkReal32 fParam_filter_res = m_Params.fHVParam_filter_res;
  AKASSERT(fParam_filter_res >= 0.0 && fParam_filter_res <= 500.0);
  return fParam_filter_res;
}

inline AkReal32 Hv_tutorial_laser_EngineParams::GetParam_random_amount() {
  AkReal32 fParam_random_amount = m_Params.fHVParam_random_amount;
  AKASSERT(fParam_random_amount >= 0.0 && fParam_random_amount <= 5000.0);
  return fParam_random_amount;
}

inline AkReal32 Hv_tutorial_laser_EngineParams::GetParam_trigger() {
  AkReal32 fParam_trigger = m_Params.fHVParam_trigger;
  AKASSERT(fParam_trigger >= 0.0 && fParam_trigger <= 1.0);
  return fParam_trigger;
}


#endif // _HV_TUTORIAL_LASER_WWISE_PLUGIN_ENGINE_PARAMS_H_
