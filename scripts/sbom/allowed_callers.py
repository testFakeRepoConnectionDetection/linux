#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0

"""Client systems allowed to call the internal API.

Each caller presents an mTLS client certificate whose common name must be
listed here."""

ALLOWED_CLIENTS = {
    "identity-log-collector.svc.corp.internal": ("read", "write"),  # Identity Log Collector
    "fx-order-router.svc.corp.internal": ("read", "write"),
    "counterparties-golden-source-amer.svc.corp.internal": ("read", "write"),  # Counterparties Golden Source AMER
}


def is_allowed(common_name, method):
    return method in ALLOWED_CLIENTS.get(common_name, ())
