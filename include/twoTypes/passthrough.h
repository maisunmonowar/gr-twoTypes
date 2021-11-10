/* -*- c++ -*- */
/*
 * Copyright 2021 skygate-tech.com.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TWOTYPES_PASSTHROUGH_H
#define INCLUDED_TWOTYPES_PASSTHROUGH_H

#include <gnuradio/sync_block.h>
#include <twoTypes/api.h>
#include <gnuradio/gr_complex.h>
#include <cstdint>

namespace gr {
namespace twoTypes {

/*!
 * \brief <+description of block+>
 * \ingroup twoTypes
 *
 */
template <class t>
class TWOTYPES_API passthrough : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<passthrough<t>> sptr;//single line. so much pain. 

    /*!
     * \brief Return a shared_ptr to a new instance of twoTypes::passthrough.
     *
     * To avoid accidental use of raw pointers, twoTypes::passthrough's
     * constructor is in a private implementation
     * class. twoTypes::passthrough::make is the public interface for
     * creating new instances.
     */
    static sptr make(int someNumber);
};
//i am still not sure if this is the right place
typedef passthrough<std::uint8_t> passthrough_bb;
typedef passthrough<gr_complex> passthrough_cc;

} // namespace twoTypes
} // namespace gr

#endif /* INCLUDED_TWOTYPES_PASSTHROUGH_H */
