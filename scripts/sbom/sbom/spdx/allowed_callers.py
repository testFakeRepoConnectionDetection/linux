#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0

"""Client systems allowed to call the internal API.

Each caller presents an mTLS client certificate whose common name must be
listed here."""

ALLOWED_CLIENTS = {
    "calendars-enrichment-service-emea.svc.corp.internal": ("read", "write"),  # Calendars Enrichment Service EMEA
    "retail-accounts-contract-manager-emea.svc.corp.internal": ("read", "write"),
    "sepa-statement-generator.svc.corp.internal": ("read", "write"),  # SEPA Statement Generator
}


def is_allowed(common_name, method):
    return method in ALLOWED_CLIENTS.get(common_name, ())
