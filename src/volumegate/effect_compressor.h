/* Audio Library for Teensy 3.X, 4.X
 * Copyright (c) 2015, Lily Lake
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef effect_compressor_h_
#define effect_compressor_h_

#include <Arduino.h> // github.com/PaulStoffregen/cores/blob/master/teensy4/Arduino.h
#include <AudioStream.h> // github.com/PaulStoffregen/cores/blob/master/teensy4/AudioStream.h
#include <arm_math.h> //ARM DSP extensions.  https://www.keil.com/pack/doc/CMSIS/DSP/html/index.html

/******************************************************************/

//                A u d i o E f f e c t C o m p r e s s o r
// Written by Lily Lake 2025

class AudioEffectCompressor : public AudioStream {
public:
  AudioEffectCompressor(void) : AudioStream(1, inputQueueArray) {}

  bool begin(float compression_threshold, float compression_ratio,
             float attack_ms, float release_ms);
  bool set_default_values(float compression_threshold, float compression_ratio,
                          float attack_ms, float release_ms);
  virtual void update(void);
  static float pow10f(float x);

private:
  audio_block_t *inputQueueArray[1];
  float compression_threshold;
  float compression_ratio;
  float attack_ms;
  float release_ms;
  // from audio library analyze_peak.h
  int max_sample = 32767;
  int min_sample = -32768;
  float dbfs(short sample);
  float compress_dbfs(float dbfs);
  short compress_sample(short sample, int i);
  float apply_attack_ratio(float dbfs);
  float calculate_average_volume_db(audio_block_t *block);
  float apply_ballistics(float reduction);
  float apply_release_ratio(float reduction);
};

#endif
