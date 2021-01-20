﻿/*
 *  Created by Phil on 03/12/2013.
 *  Copyright 2013 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_SECTION_H_INCLUDED
#define TWOBLUECUBES_CATCH_SECTION_H_INCLUDED

#include "catch_section_info.h"
#include "catch_totals.h"
#include "catch_timer.h"

#include <string>

namespace Catch {

    class Section : NonCopyable {
    public:
        Section( SectionInfo const& info );
        ~Section();

        // This indicates whether the section should be executed or not
        explicit operator bool() const;

    private:
        SectionInfo m_info;

        std::string m_name;
        Counts m_assertions;
        bool m_sectionIncluded;
        Timer m_timer;
    };

} // end namespace Catch

    #define INTERNAL_CATCH_SECTION( ... ) \
        if( Catch::Section const& INTERNAL_CATCH_UNIQUE_NAME( catch_internal_Section ) = Catch::SectionInfo( CATCH_INTERNAL_LINEINFO, __VA_ARGS__ ) )

#endif // TWOBLUECUBES_CATCH_SECTION_H_INCLUDED
