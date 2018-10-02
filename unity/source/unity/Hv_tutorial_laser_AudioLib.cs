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

using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;
using UnityEngine.Assertions;
using AOT;

#if UNITY_EDITOR
using UnityEditor;

[CustomEditor(typeof(Hv_tutorial_laser_AudioLib))]
public class Hv_tutorial_laser_Editor : Editor {

  [MenuItem("Heavy/tutorial_laser")]
  static void CreateHv_tutorial_laser() {
    GameObject target = Selection.activeGameObject;
    if (target != null) {
      target.AddComponent<Hv_tutorial_laser_AudioLib>();
    }
  }

  private Hv_tutorial_laser_AudioLib _dsp;

  private void OnEnable() {
    _dsp = target as Hv_tutorial_laser_AudioLib;
  }

  public override void OnInspectorGUI() {
    bool isEnabled = _dsp.IsInstantiated();
    if (!isEnabled) {
      EditorGUILayout.LabelField("Press Play!",  EditorStyles.centeredGreyMiniLabel);
    }
    GUILayout.BeginVertical();
    
    // PARAMETERS
    GUI.enabled = true;
    EditorGUILayout.Space();
    EditorGUI.indentLevel++;

    // base_frequency
    GUILayout.BeginHorizontal();
    float base_frequency = _dsp.GetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Base_frequency);
    float newBase_frequency = EditorGUILayout.Slider("base_frequency", base_frequency, 60.0f, 22000.0f);
    if (base_frequency != newBase_frequency) {
      _dsp.SetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Base_frequency, newBase_frequency);
    }
    GUILayout.EndHorizontal();

    // filter_res
    GUILayout.BeginHorizontal();
    float filter_res = _dsp.GetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Filter_res);
    float newFilter_res = EditorGUILayout.Slider("filter_res", filter_res, 0.0f, 500.0f);
    if (filter_res != newFilter_res) {
      _dsp.SetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Filter_res, newFilter_res);
    }
    GUILayout.EndHorizontal();

    // random_amount
    GUILayout.BeginHorizontal();
    float random_amount = _dsp.GetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Random_amount);
    float newRandom_amount = EditorGUILayout.Slider("random_amount", random_amount, 0.0f, 5000.0f);
    if (random_amount != newRandom_amount) {
      _dsp.SetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Random_amount, newRandom_amount);
    }
    GUILayout.EndHorizontal();

    // trigger
    GUILayout.BeginHorizontal();
    float trigger = _dsp.GetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Trigger);
    float newTrigger = EditorGUILayout.Slider("trigger", trigger, 0.0f, 1.0f);
    if (trigger != newTrigger) {
      _dsp.SetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Trigger, newTrigger);
    }
    GUILayout.EndHorizontal();

    EditorGUI.indentLevel--;

    

    GUILayout.EndVertical();
  }
}
#endif // UNITY_EDITOR

[RequireComponent (typeof (AudioSource))]
public class Hv_tutorial_laser_AudioLib : MonoBehaviour {
  
  // Parameters are used to send float messages into the patch context (thread-safe).
  // Example usage:
  /*
    void Start () {
        Hv_tutorial_laser_AudioLib script = GetComponent<Hv_tutorial_laser_AudioLib>();
        // Get and set a parameter
        float base_frequency = script.GetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Base_frequency);
        script.SetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter.Base_frequency, base_frequency + 0.1f);
    }
  */
  public enum Parameter : uint {
    Base_frequency = 0xBA292486,
    Filter_res = 0xE9397404,
    Random_amount = 0xAD78F8FA,
    Trigger = 0xEAD0B378,
  }
  
  // Delegate method for receiving float messages from the patch context (thread-safe).
  // Example usage:
  /*
    void Start () {
        Hv_tutorial_laser_AudioLib script = GetComponent<Hv_tutorial_laser_AudioLib>();
        script.RegisterSendHook();
        script.FloatReceivedCallback += OnFloatMessage;
    }

    void OnFloatMessage(Hv_tutorial_laser_AudioLib.FloatMessage message) {
        Debug.Log(message.receiverName + ": " + message.value);
    }
  */
  public class FloatMessage {
    public string receiverName;
    public float value;

    public FloatMessage(string name, float x) {
      receiverName = name;
      value = x;
    }
  }
  public delegate void FloatMessageReceived(FloatMessage message);
  public FloatMessageReceived FloatReceivedCallback;
  public float base_frequency = 6000.0f;
  public float filter_res = 20.0f;
  public float random_amount = 0.0f;
  public float trigger = 0.0f;

  // internal state
  private Hv_tutorial_laser_Context _context;

  public bool IsInstantiated() {
    return (_context != null);
  }

  public void RegisterSendHook() {
    _context.RegisterSendHook();
  }
  
  // see Hv_tutorial_laser_AudioLib.Parameter for definitions
  public float GetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter param) {
    switch (param) {
      case Parameter.Base_frequency: return base_frequency;
      case Parameter.Filter_res: return filter_res;
      case Parameter.Random_amount: return random_amount;
      case Parameter.Trigger: return trigger;
      default: return 0.0f;
    }
  }

  public void SetFloatParameter(Hv_tutorial_laser_AudioLib.Parameter param, float x) {
    switch (param) {
      case Parameter.Base_frequency: {
        x = Mathf.Clamp(x, 60.0f, 22000.0f);
        base_frequency = x;
        break;
      }
      case Parameter.Filter_res: {
        x = Mathf.Clamp(x, 0.0f, 500.0f);
        filter_res = x;
        break;
      }
      case Parameter.Random_amount: {
        x = Mathf.Clamp(x, 0.0f, 5000.0f);
        random_amount = x;
        break;
      }
      case Parameter.Trigger: {
        x = Mathf.Clamp(x, 0.0f, 1.0f);
        trigger = x;
        break;
      }
      default: return;
    }
    if (IsInstantiated()) _context.SendFloatToReceiver((uint) param, x);
  }
  
  public void SendFloatToReceiver(string receiverName, float x) {
    _context.SendFloatToReceiver(StringToHash(receiverName), x);
  }

  public void FillTableWithMonoAudioClip(string tableName, AudioClip clip) {
    if (clip.channels > 1) {
      Debug.LogWarning("Hv_tutorial_laser_AudioLib: Only loading first channel of '" +
          clip.name + "' into table '" +
          tableName + "'. Multi-channel files are not supported.");
    }
    float[] buffer = new float[clip.samples]; // copy only the 1st channel
    clip.GetData(buffer, 0);
    _context.FillTableWithFloatBuffer(StringToHash(tableName), buffer);
  }

  public void FillTableWithMonoAudioClip(uint tableHash, AudioClip clip) {
    if (clip.channels > 1) {
      Debug.LogWarning("Hv_tutorial_laser_AudioLib: Only loading first channel of '" +
          clip.name + "' into table '" +
          tableHash + "'. Multi-channel files are not supported.");
    }
    float[] buffer = new float[clip.samples]; // copy only the 1st channel
    clip.GetData(buffer, 0);
    _context.FillTableWithFloatBuffer(tableHash, buffer);
  }

  public void FillTableWithFloatBuffer(string tableName, float[] buffer) {
    _context.FillTableWithFloatBuffer(StringToHash(tableName), buffer);
  }

  public void FillTableWithFloatBuffer(uint tableHash, float[] buffer) {
    _context.FillTableWithFloatBuffer(tableHash, buffer);
  }

  public uint StringToHash(string str) {
    return _context.StringToHash(str);
  }

  private void Awake() {
    _context = new Hv_tutorial_laser_Context((double) AudioSettings.outputSampleRate);
    
  }
  
  private void Start() {
    _context.SendFloatToReceiver((uint) Parameter.Base_frequency, base_frequency);
    _context.SendFloatToReceiver((uint) Parameter.Filter_res, filter_res);
    _context.SendFloatToReceiver((uint) Parameter.Random_amount, random_amount);
    _context.SendFloatToReceiver((uint) Parameter.Trigger, trigger);
  }
  
  private void Update() {
    // retreive sent messages
    if (_context.IsSendHookRegistered()) {
      Hv_tutorial_laser_AudioLib.FloatMessage tempMessage;
      while ((tempMessage = _context.msgQueue.GetNextMessage()) != null) {
        FloatReceivedCallback(tempMessage);
      }
    }
  }

  private void OnAudioFilterRead(float[] buffer, int numChannels) {
    Assert.AreEqual(numChannels, _context.GetNumOutputChannels()); // invalid channel configuration
    _context.Process(buffer, buffer.Length / numChannels); // process dsp
  }
}

class Hv_tutorial_laser_Context {

#if UNITY_IOS && !UNITY_EDITOR
  private const string _dllName = "__Internal";
#else
  private const string _dllName = "Hv_tutorial_laser_AudioLib";
#endif

  // Thread-safe message queue
  public class SendMessageQueue {
    private readonly object _msgQueueSync = new object();
    private readonly Queue<Hv_tutorial_laser_AudioLib.FloatMessage> _msgQueue = new Queue<Hv_tutorial_laser_AudioLib.FloatMessage>();

    public Hv_tutorial_laser_AudioLib.FloatMessage GetNextMessage() {
      lock (_msgQueueSync) {
        return (_msgQueue.Count != 0) ? _msgQueue.Dequeue() : null;
      }
    }

    public void AddMessage(string receiverName, float value) {
      Hv_tutorial_laser_AudioLib.FloatMessage msg = new Hv_tutorial_laser_AudioLib.FloatMessage(receiverName, value);
      lock (_msgQueueSync) {
        _msgQueue.Enqueue(msg);
      }
    }
  }

  public readonly SendMessageQueue msgQueue = new SendMessageQueue();
  private readonly GCHandle gch;
  private readonly IntPtr _context; // handle into unmanaged memory
  private SendHook _sendHook = null;

  [DllImport (_dllName)]
  private static extern IntPtr hv_tutorial_laser_new_with_options(double sampleRate, int poolKb, int inQueueKb, int outQueueKb);

  [DllImport (_dllName)]
  private static extern int hv_processInlineInterleaved(IntPtr ctx,
      [In] float[] inBuffer, [Out] float[] outBuffer, int numSamples);

  [DllImport (_dllName)]
  private static extern void hv_delete(IntPtr ctx);

  [DllImport (_dllName)]
  private static extern double hv_getSampleRate(IntPtr ctx);

  [DllImport (_dllName)]
  private static extern int hv_getNumInputChannels(IntPtr ctx);

  [DllImport (_dllName)]
  private static extern int hv_getNumOutputChannels(IntPtr ctx);

  [DllImport (_dllName)]
  private static extern void hv_setSendHook(IntPtr ctx, SendHook sendHook);

  [DllImport (_dllName)]
  private static extern void hv_setPrintHook(IntPtr ctx, PrintHook printHook);

  [DllImport (_dllName)]
  private static extern int hv_setUserData(IntPtr ctx, IntPtr userData);

  [DllImport (_dllName)]
  private static extern IntPtr hv_getUserData(IntPtr ctx);

  [DllImport (_dllName)]
  private static extern void hv_sendBangToReceiver(IntPtr ctx, uint receiverHash);

  [DllImport (_dllName)]
  private static extern void hv_sendFloatToReceiver(IntPtr ctx, uint receiverHash, float x);

  [DllImport (_dllName)]
  private static extern uint hv_msg_getTimestamp(IntPtr message);

  [DllImport (_dllName)]
  private static extern bool hv_msg_hasFormat(IntPtr message, string format);

  [DllImport (_dllName)]
  private static extern float hv_msg_getFloat(IntPtr message, int index);

  [DllImport (_dllName)]
  private static extern bool hv_table_setLength(IntPtr ctx, uint tableHash, uint newSampleLength);

  [DllImport (_dllName)]
  private static extern IntPtr hv_table_getBuffer(IntPtr ctx, uint tableHash);

  [DllImport (_dllName)]
  private static extern float hv_samplesToMilliseconds(IntPtr ctx, uint numSamples);

  [DllImport (_dllName)]
  private static extern uint hv_stringToHash(string s);

  private delegate void PrintHook(IntPtr context, string printName, string str, IntPtr message);

  private delegate void SendHook(IntPtr context, string sendName, uint sendHash, IntPtr message);

  public Hv_tutorial_laser_Context(double sampleRate, int poolKb=10, int inQueueKb=4, int outQueueKb=2) {
    gch = GCHandle.Alloc(msgQueue);
    _context = hv_tutorial_laser_new_with_options(sampleRate, poolKb, inQueueKb, outQueueKb);
    hv_setPrintHook(_context, new PrintHook(OnPrint));
    hv_setUserData(_context, GCHandle.ToIntPtr(gch));
  }

  ~Hv_tutorial_laser_Context() {
    hv_delete(_context);
    GC.KeepAlive(_context);
    GC.KeepAlive(_sendHook);
    gch.Free();
  }

  public void RegisterSendHook() {
    // Note: send hook functionality only applies to messages containing a single float value
    if (_sendHook == null) {
      _sendHook = new SendHook(OnMessageSent);
      hv_setSendHook(_context, _sendHook);
    }
  }

  public bool IsSendHookRegistered() {
    return (_sendHook != null);
  }

  public double GetSampleRate() {
    return hv_getSampleRate(_context);
  }

  public int GetNumInputChannels() {
    return hv_getNumInputChannels(_context);
  }

  public int GetNumOutputChannels() {
    return hv_getNumOutputChannels(_context);
  }

  public void SendBangToReceiver(uint receiverHash) {
    hv_sendBangToReceiver(_context, receiverHash);
  }

  public void SendFloatToReceiver(uint receiverHash, float x) {
    hv_sendFloatToReceiver(_context, receiverHash, x);
  }

  public void FillTableWithFloatBuffer(uint tableHash, float[] buffer) {
    if (hv_table_getBuffer(_context, tableHash) != IntPtr.Zero) {
      hv_table_setLength(_context, tableHash, (uint) buffer.Length);
      Marshal.Copy(buffer, 0, hv_table_getBuffer(_context, tableHash), buffer.Length);
    } else {
      Debug.Log(string.Format("Table '{0}' doesn't exist in the patch context.", tableHash));
    }
  }

  public uint StringToHash(string s) {
    return hv_stringToHash(s);
  }

  public int Process(float[] buffer, int numFrames) {
    return hv_processInlineInterleaved(_context, buffer, buffer, numFrames);
  }

  [MonoPInvokeCallback(typeof(PrintHook))]
  private static void OnPrint(IntPtr context, string printName, string str, IntPtr message) {
    float timeInSecs = hv_samplesToMilliseconds(context, hv_msg_getTimestamp(message)) / 1000.0f;
    Debug.Log(string.Format("{0} [{1:0.000}]: {2}", printName, timeInSecs, str));
  }

  [MonoPInvokeCallback(typeof(SendHook))]
  private static void OnMessageSent(IntPtr context, string sendName, uint sendHash, IntPtr message) {
    if (hv_msg_hasFormat(message, "f")) {
      SendMessageQueue msgQueue = (SendMessageQueue) GCHandle.FromIntPtr(hv_getUserData(context)).Target;
      msgQueue.AddMessage(sendName, hv_msg_getFloat(message, 0));
    }
  }
}
