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
from gnuradio import blocks
from os import sys
from gnuradio.eng_option import eng_option
from optparse import OptionParser

for extdir in ['../../debug/src/lib','../../debug/src/lib/.libs','../lib','../lib/.libs','../build/swig']:
    if extdir not in sys.path:
        sys.path.append(extdir)
import fchdetection_swig as fchdetection
class detect (gr.top_block):

    def __init__ (self):
        # set up fg
        gr.top_block.__init__(self)

        parser = OptionParser(option_class=eng_option)
        parser.add_option("-I", "--inputfile", type="string", default="cfile",
                          help="Input filename")
        (options, args) = parser.parse_args()

        ifile = options.inputfile

        sample_rate = 400e3
        ampl = 0.1
        file_src = blocks.file_source(8, ifile, False)
        
        #taps = filter.firdes.low_pass(1, sample_rate, 70e3, 10e3)
        taps = filter.firdes.band_pass(1, sample_rate, 67.7033e3-18e3, 67.7033e3+18e3, 10e3)
        detect = fchdetection.detect(taps)
        
        dst = blocks.vector_sink_c()
        self.connect(file_src, detect)
        
        self.connect(detect, dst)
        # check data


if __name__ == '__main__':
    try:
        detect().run()
    except KeyboardInterrupt:
        pass
