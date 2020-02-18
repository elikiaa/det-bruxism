/*
  FeatureExtraction.h - Library for feature extraction (currently only in time domain).
  Created by Hella Toto-Kiesa, February 17, 2020.
*/
#ifndef FeatureExtraction_h
#define FeatureExtraction_h

#include "Arduino.h"

const byte NFEATURES = 15;
const byte NSAMPLES = 255;

class FeatureExtraction
{
  public:
    FeatureExtraction(double *sig);
    double *get_features();
  private:
    size_t _N;
    double _Nk;
    double *_sig;
    double *_features;
    double _aav();
    double _mav();
    double _mmav1();
    double _mmav2();
    double _ssi();
    double _var();
    double _ssc();
    double _wl();
    double _aac();
    double _rms();
    double _iemg();
    double _aax();
    double _std();
    double _dasdv();
    double _log();
};

#endif
