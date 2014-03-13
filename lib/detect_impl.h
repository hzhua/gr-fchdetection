/* -*- c++ -*- */
/* 
 * Copyright 2014 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_FCHDETECTION_DETECT_IMPL_H
#define INCLUDED_FCHDETECTION_DETECT_IMPL_H

#include <fchdetection/detect.h>
#include <vector>

namespace gr {
  namespace fchdetection {

    class detect_impl : public detect
    {
     private:
      // Nothing to declare in this block.

     public:
      detect_impl(std::vector<float> _taps);
      ~detect_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      float avg_sig,avg_cnt,avg_e;
      bool avg_e_exist;
      std::vector<gr_complex> taps;
      
      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace fchdetection
} // namespace gr

#endif /* INCLUDED_FCHDETECTION_DETECT_IMPL_H */

