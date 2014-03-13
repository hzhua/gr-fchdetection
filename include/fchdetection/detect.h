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


#ifndef INCLUDED_FCHDETECTION_DETECT_H
#define INCLUDED_FCHDETECTION_DETECT_H

#include <fchdetection/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace fchdetection {

    /*!
     * \brief <+description of block+>
     * \ingroup fchdetection
     *
     */
    class FCHDETECTION_API detect : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<detect> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of fchdetection::detect.
       *
       * To avoid accidental use of raw pointers, fchdetection::detect's
       * constructor is in a private implementation
       * class. fchdetection::detect::make is the public interface for
       * creating new instances.
       */
      static sptr make(std::vector<float> _taps);
    };

  } // namespace fchdetection
} // namespace gr

#endif /* INCLUDED_FCHDETECTION_DETECT_H */

