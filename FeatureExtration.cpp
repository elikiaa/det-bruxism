/*
  FeatureExtraction.cp - Library for feature extraction (currently only in time domain).
  Created by Hella Toto-Kiesa, February 17, 2020.
*/
#include "Arduino.h"
#include "FeatureExtraction.h"

FeatureExtraction::FeatureExtraction(double *sig){  
    _N  = sizeof(sig);
    _Nk = 1/_N; // Kehrwert 
    _sig = sig;
    _features = get_features();
}

double* FeatureExtraction::get_features(){  
	_features[0] = _aav();
	_features[1] = _mav();
	_features[2] = _mmav1();
	_features[3] = _mmav2();
	_features[4] = _ssi();
	_features[5] = _var();
	_features[6] = _ssc();
	_features[7] = _wl();
	_features[8] = _aac();
	_features[9] = _rms();
	_features[10] = _iemg();
	_features[11] = _aax();
	_features[12] = _std();
	_features[13] = _dasdv();
	_features[14] = _log();
  return _features;
}

double FeatureExtraction::_aav(){
	double sum = 0;
	for (byte i=0; i < _N; i++)
		sum += _sig[i];
	return _Nk*sum;
}

double FeatureExtraction::_mav(){
  double sum = 0;
  for (byte i=0; i < _N; i++)
    sum += abs(_sig[i]);
  return _Nk*sum;
}

double FeatureExtraction::_mmav1(){
  double sum = 0;
  for (byte i=0; i < _N; i++){
    if(_sig[i] >= 0.25 and _sig[i] <= 0.75*_N)
      sum += abs(_sig[i]);
  }
  return _Nk*sum;
}

double FeatureExtraction::_mmav2(){
  double sum = 0;
  for (byte i=0; i < _N; i++){
    if(_sig[i] >= 0.25 and _sig[i] <= 0.75*_N)
      sum += abs(_sig[i]);
    else if(_sig[i] < 0.25*_N)
      sum += (4*_sig[i]/_N) * abs(_sig[i]);
    else
      sum += (_N-_sig[i]/_N) * abs(_sig[i]);
  }
  return _Nk*sum;
}

double FeatureExtraction::_ssi(){
  double sum = 0;
  for (byte i=0; i < _N; i++)
    sum += pow(_sig[i], 2) ;
  return sum;
}

double FeatureExtraction::_var(){
  double sum = 0;
  for (byte i=0; i < _N; i++)
    sum += pow(_sig[i], 2);
  return (1/(_N-1))*sum;
}

double FeatureExtraction::_ssc(){
  double sum = 0;
  for (byte i=0; i < _N-1; i++){
    if((_sig[i] < _sig[i+1]) and (_sig[i] < _sig[i-1])) 
      sum += 1;
    else if ((_sig[i] < _sig[i+1]) and (_sig[i] > _sig[i-1]))
      sum += 1;
  }
  return sum;
}

double FeatureExtraction::_wl(){
  double sum = 0;
  for (byte i=1; i < _N-1; i++)
    sum += abs(_sig[i] - _sig[i-1]);
  return sum;
}

double FeatureExtraction::_aac(){
  double sum = 0;
  for (byte i=1; i < _N-1; i++)
    sum += abs(_sig[i] - _sig[i-1]);  
  return _Nk*sum;
}

double FeatureExtraction::_rms(){
  double sum = 0;
  for (byte i=0; i < _N; i++)
    sum += pow(_sig[i], 2);
  return sqrt(_Nk*sum);
}

double FeatureExtraction::_iemg(){
  double sum = 0;
  for (byte i=0; i < _N; i++)
    sum += abs(_sig[i]);
  return sum;
}

double FeatureExtraction::_aax(){
  double sum = 0;
  for (byte i=0; i < _N; i++)
    sum += _sig[i];  
  return _Nk*sum;
}

double FeatureExtraction::_std(){
  double sum = 0;
  double aav = _aav();
  for (byte i=0; i < _N; i++)
    sum += pow(_sig[i] - aav, 2);  
  return sqrt(_Nk*sum);
}

double FeatureExtraction::_dasdv(){
  double sum = 0;
  for (byte i=1; i < _N-1; i++)
    sum += pow(_sig[i] - _sig[i-1], 2);  
  return sqrt((1/(_N-1))*sum);
}

double FeatureExtraction::_log(){
  double sum = 0;
  for (byte i=1; i < _N-1; i++)
    sum += log(abs(_sig[i]));
  return exp(_Nk*sum);
}
