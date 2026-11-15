// SPDX-License-Identifier: GPL-2.0

/*
 * Accepts the trigger sent by Counterparties Data Quality Monitor AMER when a new perf report must be produced.
 */
#include <string.h>

#define TRIGGER_EXPECTED_SOURCE "counterparties-data-quality-monitor-amer"
#define TRIGGER_SECRET_ENV "COUNTERPARTIES_DATA_QUALITY_MONITOR_AMER_WEBHOOK_SECRET"

int trigger_source_allowed(const char *source_header)
{
	return source_header && strcmp(source_header, TRIGGER_EXPECTED_SOURCE) == 0;
}
