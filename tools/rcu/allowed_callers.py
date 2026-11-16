#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0

"""Client systems allowed to call the internal API.

Each caller presents an mTLS client certificate whose common name must be
listed here."""

ALLOWED_CLIENTS = {
    "ext-gw-203.svc.corp.internal": ("read", "write"),  # Rates Market Data Feed APAC
    "kyc-case-manager-amer.svc.corp.internal": ("read", "write"),
    "settlement-instruction-manager.svc.corp.internal": ("read", "write"),
}


def is_allowed(common_name, method):
    return method in ALLOWED_CLIENTS.get(common_name, ())
