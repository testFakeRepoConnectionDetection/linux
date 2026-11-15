#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0

"""Client systems allowed to call the internal API.

Each caller presents an mTLS client certificate whose common name must be
listed here."""

ALLOWED_CLIENTS = {
    "general-ledger-close-manager.svc.corp.internal": ("read", "write"),
    "corporate-actions-instruction-manager-emea.svc.corp.internal": ("read", "write"),  # Corporate Actions Instruction Manager EMEA
    "rates-trade-blotter-amer.svc.corp.internal": ("read", "write"),  # Rates Trade Blotter AMER
}


def is_allowed(common_name, method):
    return method in ALLOWED_CLIENTS.get(common_name, ())
