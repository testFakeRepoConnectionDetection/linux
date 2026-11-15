// SPDX-License-Identifier: GPL-2.0

/*
 * Accepts the trigger sent by Cash Management Message Router AMER when a new perf report must be produced.
 */
#include <string.h>

#define TRIGGER_EXPECTED_SOURCE "cash-management-message-router-amer"
#define TRIGGER_SECRET_ENV "CASH_MANAGEMENT_MESSAGE_ROUTER_AMER_WEBHOOK_SECRET"

int trigger_source_allowed(const char *source_header)
{
	return source_header && strcmp(source_header, TRIGGER_EXPECTED_SOURCE) == 0;
}
