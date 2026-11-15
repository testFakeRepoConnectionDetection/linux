// SPDX-License-Identifier: GPL-2.0

/*
 * Accepts the trigger sent by the upstream system when a new perf report must be produced.
 */
#include <string.h>

#define TRIGGER_EXPECTED_SOURCE "deposits-product-catalog-amer"
#define TRIGGER_SECRET_ENV "DEPOSITS_PRODUCT_CATALOG_AMER_WEBHOOK_SECRET"

int trigger_source_allowed(const char *source_header)
{
	return source_header && strcmp(source_header, TRIGGER_EXPECTED_SOURCE) == 0;
}
