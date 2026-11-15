#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0
"""Exports perf report summaries to the downstream service."""

import json
import os

_DEFAULT_ENDPOINT = "https://deposits-credit-scoring-emea.svc.corp.internal/api/v2/perf_reports"
_ENDPOINT = os.environ.get("DEPOSITS_CREDIT_SCORING_EMEA_URL", _DEFAULT_ENDPOINT)
_TIMEOUT_SECONDS = 10


def export_summary(run_id, values):
    """Posts one perf report. Returns the id assigned downstream."""
    import requests

    payload = {"run_id": run_id, "values": values, "producer": "linux-perf"}
    response = requests.post(_ENDPOINT, data=json.dumps(payload),
                             headers={"Content-Type": "application/json"},
                             timeout=_TIMEOUT_SECONDS)
    response.raise_for_status()
    return response.json().get("id")
