#License 

  Copyright 2014 Zhenhua HAN(hzhua201@gmail.com).
 
  This is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3, or (at your option)
  any later version.
 
  This software is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with this software; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street,
  Boston, MA 02110-1301, USA.

#Usage

<pre><code>
gr-fchdetection$ mkdir build
gr-fchdetection/build$ cd build
gr-fchdetection/build$ cmake ../
gr-fchdetection/build$ make
gr-fchdetection/build$ cd ../python
gr-fchdetection/python$ ./python/detect.py -I input.cfile > somefile.output
</code></pre>

Then you can plot the "somefile.output" with any tools (matlab,matplotlib...) you like.

#Reminder
This program implemented the algorithm of "Robust Frequency Burst Detection Algorithm for 
GSM/GPRS",G. Narendra Varma, Usha Sahu, G. Prabhu Charan. The copyright of this algorithm
remains to them. Be careful when you use it.
