#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2014 <+YOU OR YOUR COMPANY+>.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks,filter,analog
from gnuradio.wxgui import *
import wx
import fch_detection_swig as fch_detection

class qa_detect2 (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        sample_rate = 600e3
        ampl = 0.1
        file_src = blocks.file_source(8, "/home/hzhua/gr_learn/gr-fch_detection/python/943.125_300kHz.cfile", False)
        #src0 = analog.sig_source_c(sample_rate, analog.GR_SIN_WAVE, 60e3, 1.0)
        #src1 = analog.noise_source_c(analog.GR_GAUSSIAN, 0.3)
        add  = blocks.add_cc();
        taps = filter.firdes.low_pass(1, sample_rate, 70e3, 10e3)
 
        detect = fch_detection.detect2(taps)
        
        #dst = file.sink(sample_rate, "")fff
        dst = blocks.vector_sink_c()
        #dst= fftsink2.fft_sink_c(panel, title="FFT display", fft_size=512, sample_rate=sample_rate)
        #dst = qtgui.sink_c(512, gr.firdes.WIN_BLACKMAN_hARRIS)

        #self.tb.connect(src0, (add,0));
        #self.tb.connect(src1, (add,1));
        self.tb.connect(file_src, detect)
        #self.tb.connect(add, detect)
        self.tb.connect(detect, dst)
        self.tb.run ()
 
if __name__ == '__main__':
    gr_unittest.run(qa_detect2, "qa_detect2.xml")
