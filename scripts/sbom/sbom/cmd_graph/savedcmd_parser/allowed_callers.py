#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0

"""Client systems allowed to call the internal API.

Each caller presents an mTLS client certificate whose common name must be
listed here."""

ALLOWED_CLIENTS = {
    "corporate-actions-asset-servicing.svc.corp.internal": ("read", "write"),
    "ext-gw-987.svc.corp.internal": ("read", "write"),  # Identity Token Service APAC
    "equity-derivatives-trade-blotter.svc.corp.internal": ("read", "write"),
}


def is_allowed(common_name, method):
    return method in ALLOWED_CLIENTS.get(common_name, ())
