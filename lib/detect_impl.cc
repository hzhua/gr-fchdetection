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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include <gnuradio/gr_complex.h>
#include <stdio.h>
#include "detect_impl.h"

namespace gr {
    namespace fchdetection {

        detect::sptr
            detect::make(std::vector<float> _taps)
            {
                return gnuradio::get_initial_sptr
                    (new detect_impl(_taps));
            }

        /*
         * The private constructor
         */
        detect_impl::detect_impl(std::vector<float> _taps)
            : gr::block("detect",
                    gr::io_signature::make(1, 1, sizeof(gr_complex)),
                    gr::io_signature::make(0, 1, sizeof(gr_complex)))
        {
            avg_sig = 0;
            avg_cnt = 0;
            avg_e = 0;
            avg_e_exist = false;
            for(int i = 0 ; i < _taps.size() ; i++){
                taps.push_back(gr_complex(_taps[i] , 0));
            }

        }

        /*
         * Our virtual destructor.
         */
        detect_impl::~detect_impl()
        {
        }

        void
            detect_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
            {
                ninput_items_required[0] = noutput_items;
            }


        float power(gr_complex x){
            return x.real()*x.real() + x.imag()*x.imag();
        }

        float norm(gr_complex x){
            return sqrt(power(x));
        }
        int
            detect_impl::general_work (int noutput_items,
                    gr_vector_int &ninput_items,
                    gr_vector_const_void_star &input_items,
                    gr_vector_void_star &output_items)
            {
                const gr_complex *in = (const gr_complex *) input_items[0];
                gr_complex *out = (gr_complex *) output_items[0];
                int cnt = ninput_items[0];

                // Do <+signal processing+>
                // Tell runtime system how many input items we consumed on
                // each input stream.
                //
                float ro = 0.03125;
                

                for(int i = 0 ; i < cnt ; i++){

                    float p_in = power(in[i]);
                    avg_sig = (p_in - avg_sig)/(avg_cnt+1) + avg_sig;
                    avg_cnt += 1.0;

                    if(i < taps.size()-1){
                        out[i] = in[i];
                    }else{

                        out[i] = gr_complex(0);

                        float tot_en = 0;
                        for(int j = 0 ; j < taps.size() ; j++){
                            tot_en += norm(in[j]);
                        }

                        if(tot_en/taps.size() < 0.1){
                            
                        //printfi("i=%d\n" , i);
                        //getchar();
                            continue;
                        }

                        float G = 1.0/tot_en;


                        for(int k = 0 ; k < taps.size() ; k++){
                            out[i] = out[i] + conj(taps[k])*in[i-k];
                        }


                        if(i+5 >= cnt){
                            continue;
                        }
                        
                        gr_complex e = in[i+5] - out[i];
                        
                        if(!avg_e_exist){
                            avg_e = norm(e);
                            avg_e_exist = true;
                        }else{
                            avg_e = (1-ro)*avg_e + ro*norm(e);
                        }

                        
                        gr_complex conj_e = conj(e);//gr_complex(e.real() , - e.imag());
                        for(int k = 0 ; k < taps.size() ; k++){
                            taps[k] = taps[k] + G*conj_e*in[i - k];
                        }
                        //printf("i = %d %.4f G = %.4f in = %.4f out = %.4f diff = %.4f\n" ,i, avg_e ,G, norm(in[i]) , norm(out[i]), norm(e));
                        //if(norm(e) > 1){getchar();}
                        printf("%.4f\n", norm(avg_e));
                        
                    }

                }

                consume_each (noutput_items);

                // Tell runtime system how many output items we produced.
                return noutput_items;
            }

    } /* namespace fchdetection */
} /* namespace gr */

