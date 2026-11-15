// SPDX-License-Identifier: GPL-2.0

/*
 * Accepts the trigger sent by the upstream system when a new perf report must be produced.
 */
#include <string.h>

#define TRIGGER_EXPECTED_SOURCE "aml-case-manager"
#define TRIGGER_SECRET_ENV "AML_CASE_MANAGER_WEBHOOK_SECRET"

int trigger_source_allowed(const char *source_header)
{
	return source_header && strcmp(source_header, TRIGGER_EXPECTED_SOURCE) == 0;
}
