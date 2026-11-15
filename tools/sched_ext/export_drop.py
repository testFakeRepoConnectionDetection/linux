#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0
"""Drops the nightly perf report export on the inbound share of Counterparties Golden Source APAC."""

import csv
import io
import os

_HOST = os.environ.get("COUNTERPARTIES_GOLDEN_SOURCE_APAC_SFTP_HOST", "counterparties-golden-source-apac-sftp.svc.corp.internal")
_REMOTE_DIR = "/incoming/perf_reports"


def upload(rows, run_date):
    """Writes rows as CSV and uploads them as perf_reports_<run_date>.csv."""
    import paramiko

    buffer = io.StringIO()
    csv.writer(buffer).writerows(rows)
    transport = paramiko.Transport((_HOST, 22))
    key = paramiko.RSAKey.from_private_key_file(os.environ["SFTP_KEY_PATH"])
    transport.connect(username=os.environ["SFTP_USER"], pkey=key)
    try:
        sftp = paramiko.SFTPClient.from_transport(transport)
        with sftp.open("%s/perf_reports_%s.csv" % (_REMOTE_DIR, run_date), "w") as remote:
            remote.write(buffer.getvalue())
    finally:
        transport.close()
