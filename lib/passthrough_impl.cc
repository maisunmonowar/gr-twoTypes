/* -*- c++ -*- */
/*
 * Copyright 2021 skygate-tech.com.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "passthrough_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace twoTypes {

// using input_type = std::uint8_t;
// using output_type = std::uint8_t;

template <class t>
typename passthrough<t>::sptr 
passthrough<t>::make(int someNumber)
{
    return gnuradio::make_block_sptr<passthrough_impl<t>>(someNumber);
}

/*
 * The private constructor
 */
template <class t>
passthrough_impl<t>::passthrough_impl(int someNumber)
    : gr::sync_block("passthrough",
                     gr::io_signature::make(1, 1, sizeof(t)),
                     gr::io_signature::make(1, 1, sizeof(t)))
{
}

/*
 * Our virtual destructor.
 */
template <class t>
passthrough_impl<t>::~passthrough_impl() {}

template <class t>
int passthrough_impl<t>::work(int noutput_items,
                           gr_vector_const_void_star& input_items,
                           gr_vector_void_star& output_items)
{
    const t* iptr = (const t*) input_items[0];
    t* optr = (t*)output_items[0];

    // Do <+signal processing+>
    memcpy(optr, iptr, noutput_items * sizeof(t));
    // Tell runtime system how many output items we produced.
    return noutput_items;
}
template class passthrough<gr_complex>;
template class passthrough<std::uint8_t>;
} /* namespace twoTypes */
} /* namespace gr */
