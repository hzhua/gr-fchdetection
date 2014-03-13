/* -*- c++ -*- */

#define FCHDETECTION_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "fchdetection_swig_doc.i"

%{
#include "fchdetection/detect.h"
%}


%include "fchdetection/detect.h"
GR_SWIG_BLOCK_MAGIC2(fchdetection, detect);
