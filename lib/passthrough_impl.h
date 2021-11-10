/* -*- c++ -*- */
/*
 * Copyright 2021 skygate-tech.com.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TWOTYPES_PASSTHROUGH_IMPL_H
#define INCLUDED_TWOTYPES_PASSTHROUGH_IMPL_H

#include <twoTypes/passthrough.h>

namespace gr {
namespace twoTypes {

template <class t>
class passthrough_impl : public passthrough<t>
{
private:
    // Nothing to declare in this block.

public:
    passthrough_impl<t>(int someNumber);
    ~passthrough_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace twoTypes
} // namespace gr

#endif /* INCLUDED_TWOTYPES_PASSTHROUGH_IMPL_H */
