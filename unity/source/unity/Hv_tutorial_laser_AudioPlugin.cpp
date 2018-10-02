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

// http://docs.unity3d.com/500/Documentation/Manual/AudioMixerNativeAudioPlugin.html

#include "AudioPluginUtil.h"
#include "heavy/Heavy_tutorial_laser.hpp"

namespace Hv_tutorial_laser_UnityPlugin {

  enum Param {
    P_BASE_FREQUENCY,
    P_FILTER_RES,
    P_RANDOM_AMOUNT,
    P_TRIGGER,
    P_NUM_HV_PARAMS_
  };

  struct EffectData {
    struct Data {
      float p[4];
      HeavyContextInterface *context;
    } data;
  };

  int InternalRegisterEffectDefinition(UnityAudioEffectDefinition& definition) {
    int numparams = P_NUM_HV_PARAMS_;
    definition.paramdefs = new UnityAudioParameterDefinition[numparams];
    // channels will be set to 0 if numInputChannels > 0 else it will be set to numOutputChannels
    definition.channels = 2;
    RegisterParameter(definition, "base_frequency", "", 60.0f, 22000.0f, 6000.0f, 1.0f, 1.0f, P_BASE_FREQUENCY, "base_frequency");
    RegisterParameter(definition, "filter_res", "", 0.0f, 500.0f, 20.0f, 1.0f, 1.0f, P_FILTER_RES, "filter_res");
    RegisterParameter(definition, "random_amount", "", 0.0f, 5000.0f, 0.0f, 1.0f, 1.0f, P_RANDOM_AMOUNT, "random_amount");
    RegisterParameter(definition, "trigger", "", 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, P_TRIGGER, "trigger");
    return numparams;
  }

  UNITY_AUDIODSP_RESULT UNITY_AUDIODSP_CALLBACK CreateCallback(UnityAudioEffectState* state) {
    EffectData* effectdata = new EffectData;
    effectdata->data.context = new Heavy_tutorial_laser((double) state->samplerate, 10, 4, 2);
    state->effectdata = effectdata;
    InitParametersFromDefinitions(InternalRegisterEffectDefinition, effectdata->data.p);
    return UNITY_AUDIODSP_OK;
  }

  UNITY_AUDIODSP_RESULT UNITY_AUDIODSP_CALLBACK ReleaseCallback(UnityAudioEffectState* state) {
    EffectData::Data* data = &state->GetEffectData<EffectData>()->data;
    delete data->context;
    delete data;
    return UNITY_AUDIODSP_OK;
  }

  UNITY_AUDIODSP_RESULT UNITY_AUDIODSP_CALLBACK SetFloatParameterCallback(
      UnityAudioEffectState* state, int index, float value) {
    EffectData::Data *data = &state->GetEffectData<EffectData>()->data;

    switch (index) {
      case P_BASE_FREQUENCY: data->context->sendFloatToReceiver(Heavy_tutorial_laser::Parameter::In::BASE_FREQUENCY, value); break;
      case P_FILTER_RES: data->context->sendFloatToReceiver(Heavy_tutorial_laser::Parameter::In::FILTER_RES, value); break;
      case P_RANDOM_AMOUNT: data->context->sendFloatToReceiver(Heavy_tutorial_laser::Parameter::In::RANDOM_AMOUNT, value); break;
      case P_TRIGGER: data->context->sendFloatToReceiver(Heavy_tutorial_laser::Parameter::In::TRIGGER, value); break;
      default: return UNITY_AUDIODSP_ERR_UNSUPPORTED;
    }

    data->p[index] = value;
    return UNITY_AUDIODSP_OK;
  }

  UNITY_AUDIODSP_RESULT UNITY_AUDIODSP_CALLBACK GetFloatParameterCallback(
        UnityAudioEffectState* state, int index, float* value, char *valuestr) {
    EffectData::Data* data = &state->GetEffectData<EffectData>()->data;
    if (index < 0 || index >= P_NUM_HV_PARAMS_) return UNITY_AUDIODSP_ERR_UNSUPPORTED;
    if (value != NULL) *value = data->p[index];
    if (valuestr != NULL) valuestr[0] = 0;
    return UNITY_AUDIODSP_OK;
  }

  int UNITY_AUDIODSP_CALLBACK GetFloatBufferCallback(UnityAudioEffectState* state,
      const char* name, float* buffer, int numsamples) {
    return UNITY_AUDIODSP_OK;
  }

  UNITY_AUDIODSP_RESULT UNITY_AUDIODSP_CALLBACK ProcessCallback(
      UnityAudioEffectState* state, float* inbuffer, float* outbuffer,
      unsigned int length, int inchannels, int outchannels) {
    EffectData::Data* data = &state->GetEffectData<EffectData>()->data;
    if (state->flags & UnityAudioEffectStateFlags_IsPaused) return UNITY_AUDIODSP_OK;
    hv_assert(inchannels == data->context->getNumInputChannels());
    hv_assert(outchannels == data->context->getNumOutputChannels());

    data->context->processInlineInterleaved(inbuffer, outbuffer, length);
    return UNITY_AUDIODSP_OK;
  }
}