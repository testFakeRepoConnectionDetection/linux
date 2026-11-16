// SPDX-License-Identifier: GPL-2.0

/*
 * Accepts the trigger sent by Equity Market Data Feed APAC when a new perf report must be produced.
 */
#include <string.h>

#define TRIGGER_EXPECTED_SOURCE "ext-gw-561"
#define TRIGGER_SECRET_ENV "EXT_GW_561_WEBHOOK_SECRET"

int trigger_source_allowed(const char *source_header)
{
	return source_header && strcmp(source_header, TRIGGER_EXPECTED_SOURCE) == 0;
}
