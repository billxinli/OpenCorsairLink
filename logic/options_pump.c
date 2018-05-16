/*
 * This file is part of OpenCorsairLink.
 * Copyright (C) 2017,2018  Sean Nelson <audiohacked@gmail.com>

 * OpenCorsairLink is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * any later version.

 * OpenCorsairLink is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with OpenCorsairLink.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "logic/options.h"
#include "print.h"

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void pump_control_init( struct pump_control* settings )
{
    settings->mode = DEFAULT;
}

void pump_suboptions_parse( char* subopts,
                            struct option_parse_return* settings )
{
    int opt, returnCode = 0, option_index = 0;
    char *value, *token;
    uint8_t ii = 0;

    while ( *subopts != '\0' )
    {
        switch ( getsubopt( &subopts, pump_options, &value ) )
        {
        case SUBOPTION_PUMP_MODE:
            sscanf( value, "%hhd", &settings->pump_mode );
            msg_debug( "PUMP Mode = %s\n", value );
            break;

        default:
            /* Unknown suboption. */
            msg_info( "Unknown suboption `%s'\n", value );
            break;
        }
    }
}
