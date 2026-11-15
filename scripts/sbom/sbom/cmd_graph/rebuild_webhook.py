#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0
"""Trigger called by the upstream system when a new perf report must be produced."""

import hmac
import os

_EXPECTED_SOURCE = "credit-risk-risk-aggregator-apac"
_SECRET_ENV = "CREDIT_RISK_RISK_AGGREGATOR_APAC_WEBHOOK_SECRET"


def handle_trigger(headers, body, schedule):
    """Validates the caller signature and schedules a job. Exposed as POST /internal/v1/trigger."""
    if headers.get("X-Source-System") != _EXPECTED_SOURCE:
        return 403
    secret = os.environ.get(_SECRET_ENV, "").encode("utf-8")
    signature = hmac.new(secret, body, "sha256").hexdigest()
    if not hmac.compare_digest(signature, headers.get("X-Signature", "")):
        return 401
    schedule(body.decode("utf-8").strip())
    return 202
