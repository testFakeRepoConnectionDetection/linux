// SPDX-License-Identifier: GPL-2.0

/*
 * Accepts the trigger sent by Mortgages Document Store EMEA when a new perf report must be produced.
 */
#include <string.h>

#define TRIGGER_EXPECTED_SOURCE "mortgages-document-store-emea"
#define TRIGGER_SECRET_ENV "MORTGAGES_DOCUMENT_STORE_EMEA_WEBHOOK_SECRET"

int trigger_source_allowed(const char *source_header)
{
	return source_header && strcmp(source_header, TRIGGER_EXPECTED_SOURCE) == 0;
}
